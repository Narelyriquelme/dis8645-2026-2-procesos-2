// -- LectorSD --
// implementacion de la clase que lee archivos .raw desde la tarjeta SD por bloques
// no usa sleep_ms: cada lectura de bloque termina apenas llegan los 1024 bytes,
// asi el loop principal de main.cpp sigue siendo non-blocking

#include "LectorSD.h"

// incluye las funciones del bus SPI de la pico (spi1)
#include "hardware/spi.h"
// incluye las estructuras de configuracion de la libreria de la SD
// (spi_t, sd_spi_if_t, sd_card_t, sd_get_num y sd_get_by_num)
#include "hw_config.h"
// incluye memset para rellenar el buffer con silencio
#include <string.h>

// -- configuracion de hardware que pide la libreria --
// la libreria no sabe a que pines esta conectada la SD,
// por eso le pregunta al programa usando sd_get_num() y sd_get_by_num()
// estas estructuras parten vacias y LectorSD::iniciar() las completa

// datos del bus SPI: que periferico usar y en que pines
static spi_t configuracionSPI = {};
// datos de la interfaz SPI de la tarjeta: que bus usa y cual es su pin CS
static sd_spi_if_t interfazSPI = {};
// datos de la tarjeta SD: que tipo de conexion usa (SPI o SDIO)
static sd_card_t tarjetaSD = {};

// la libreria llama a esta funcion para saber cuantas tarjetas hay
extern "C" size_t sd_get_num() {
  // solo hay una tarjeta SD conectada
  return 1;
}

// la libreria llama a esta funcion para pedir los datos de una tarjeta
extern "C" sd_card_t* sd_get_by_num(size_t numero) {
  // solo existe la tarjeta numero 0
  if (numero == 0) {
    return &tarjetaSD;
  }
  // cualquier otro numero no existe
  return NULL;
}

// funcion inicial: guarda los pines del bus SPI1
LectorSD::LectorSD(uint pinMISO, uint pinCS, uint pinSCK, uint pinMOSI) {
  this->pinMISO = pinMISO;
  this->pinCS = pinCS;
  this->pinSCK = pinSCK;
  this->pinMOSI = pinMOSI;

  // deja el buffer en silencio para que no suene basura al partir
  memset(bufferAudio, 0, sizeof(bufferAudio));
}

// configura el SPI1 y monta la tarjeta SD
bool LectorSD::iniciar() {
  // si ya estaba montada no hay nada que hacer
  if (montada) {
    return true;
  }

  // -- configuracion del bus SPI --
  // usa el periferico SPI1, porque el SPI0 choca con el ampli I2S
  configuracionSPI.hw_inst = spi1;
  // pin por donde la SD envia datos a la pico
  configuracionSPI.miso_gpio = pinMISO;
  // pin por donde la pico envia datos a la SD
  configuracionSPI.mosi_gpio = pinMOSI;
  // pin del reloj del bus
  configuracionSPI.sck_gpio = pinSCK;
  // velocidad de trabajo: 12.5 MHz
  // la libreria parte en 400 kHz para despertar la tarjeta y luego sube a esta velocidad
  // si hay errores de lectura con cables largos, bajar a 5 MHz (5 * 1000 * 1000)
  configuracionSPI.baud_rate = 12500 * 1000;

  // -- configuracion de la interfaz de la tarjeta --
  // la tarjeta usa el bus SPI configurado arriba
  interfazSPI.spi = &configuracionSPI;
  // pin CS (chip select): la pico lo baja para hablarle a la tarjeta
  interfazSPI.ss_gpio = pinCS;

  // -- configuracion de la tarjeta --
  // la tarjeta esta conectada por SPI, no por SDIO
  tarjetaSD.type = SD_IF_SPI;
  tarjetaSD.spi_if_p = &interfazSPI;
  // el modulo MH SD Card no tiene pin de deteccion de tarjeta
  tarjetaSD.use_card_detect = false;

  // -- montaje de la tarjeta --
  // "0:" es la unidad 0, que corresponde a tarjetaSD
  // el 1 al final obliga a montar ahora mismo, asi se sabe altiro si hay error
  // al montar, la libreria inicializa el SPI1 y los pines automaticamente
  FRESULT resultado = f_mount(&sistemaArchivos, "0:", 1);

  // FR_OK significa que todo salio bien
  montada = (resultado == FR_OK);
  return montada;
}

// abre un archivo .raw en modo binario de solo lectura
bool LectorSD::abrirArchivo(const char* nombreArchivo) {
  // no se puede abrir nada si la tarjeta no esta montada
  if (!montada) {
    return false;
  }

  // si habia otro archivo abierto, se cierra antes de abrir el nuevo
  cerrarArchivo();

  // FA_READ abre el archivo solo para lectura
  // FatFs siempre trabaja en modo binario, no transforma los bytes
  FRESULT resultado = f_open(&archivo, nombreArchivo, FA_READ);

  abierto = (resultado == FR_OK);
  // todavia no se ha leido ningun bloque
  muestrasLeidas = 0;
  return abierto;
}

// lee el siguiente bloque de 512 muestras hacia bufferAudio
uint32_t LectorSD::leerBloque() {
  // sin archivo abierto no hay nada que leer
  if (!abierto) {
    muestrasLeidas = 0;
    return 0;
  }

  // f_read guarda aqui cuantos bytes alcanzo a leer realmente
  UINT bytesLeidos = 0;
  // lee hasta 1024 bytes directamente dentro de bufferAudio
  // los .raw vienen en little-endian, igual que la pico, asi que no hay que ordenar bytes
  FRESULT resultado = f_read(&archivo, bufferAudio, BYTES_POR_BLOQUE, &bytesLeidos);

  // si hubo un error de lectura, se considera que no se leyo nada
  if (resultado != FR_OK) {
    bytesLeidos = 0;
  }

  // convierte bytes a muestras: cada muestra ocupa 2 bytes
  // si el archivo tiene un byte suelto al final, se ignora
  muestrasLeidas = bytesLeidos / sizeof(uint16_t);

  // si el bloque vino incompleto (final del archivo o error),
  // rellena el resto del buffer con silencio para no reproducir datos viejos
  if (muestrasLeidas < MUESTRAS_POR_BLOQUE) {
    memset(&bufferAudio[muestrasLeidas], 0,
           (MUESTRAS_POR_BLOQUE - muestrasLeidas) * sizeof(uint16_t));
  }

  return muestrasLeidas;
}

// vuelve al inicio del archivo, util para el modo loop
bool LectorSD::rebobinar() {
  if (!abierto) {
    return false;
  }
  // f_lseek mueve la posicion de lectura al byte 0
  return f_lseek(&archivo, 0) == FR_OK;
}

// cierra el archivo abierto
void LectorSD::cerrarArchivo() {
  if (abierto) {
    f_close(&archivo);
    abierto = false;
  }
  muestrasLeidas = 0;
}

// devuelve true si la tarjeta esta montada
bool LectorSD::sdLista() {
  return montada;
}

// devuelve true si hay un archivo abierto
bool LectorSD::archivoAbierto() {
  return abierto;
}

// devuelve true si ya se leyo todo el archivo
bool LectorSD::finDeArchivo() {
  // si no hay archivo abierto, se considera terminado
  if (!abierto) {
    return true;
  }
  // f_eof devuelve distinto de 0 cuando la posicion llego al final
  return f_eof(&archivo) != 0;
}

// devuelve la cantidad total de muestras del archivo abierto
uint32_t LectorSD::totalMuestras() {
  if (!abierto) {
    return 0;
  }
  // f_size entrega el tamano en bytes, se divide por 2 para tener muestras
  return (uint32_t)(f_size(&archivo) / sizeof(uint16_t));
}
