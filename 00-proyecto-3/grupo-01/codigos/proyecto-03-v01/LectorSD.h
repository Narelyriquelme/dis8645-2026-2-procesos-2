// -- LectorSD --
// lee archivos .raw (PCM de 16 bits sin cabecera) desde una tarjeta SD
// en lugar de cargar el sonido completo en memoria, lo lee por bloques
// de 512 muestras (1024 bytes), asi la RAM no se satura con sonidos largos
//
// usa la libreria externa FatFs a traves de no-OS-FatFS-SD-SDIO-SPI-RPi-Pico
// (github.com/carlk3/no-OS-FatFS-SD-SDIO-SPI-RPi-Pico), que trae ff.h
// y el driver SPI de la tarjeta SD para la Pico
//
// la tarjeta va conectada al bus SPI1, porque el SPI0 choca con el ampli I2S
// pines por defecto: MISO 8, CS 9, SCK 10, MOSI 11
//
// formato esperado de los archivos .raw:
// mono, 16 bits, little-endian, misma frecuencia que el ampli (11025 Hz)
//
// importante: solo debe existir un LectorSD en el programa,
// porque la configuracion de la tarjeta que pide la libreria es unica

#ifndef LECTORSD_H
#define LECTORSD_H

// incluye las funciones basicas de la pico (tipo uint, gpio, etc.)
#include "pico/stdlib.h"
// incluye los tipos de datos de tamano exacto
#include <stdint.h>
// incluye la libreria FatFs: FATFS, FIL, f_mount, f_open, f_read, f_close...
#include "ff.h"

// cantidad de muestras que se leen en cada bloque
const uint32_t MUESTRAS_POR_BLOQUE = 512;
// cantidad de bytes de cada bloque: 512 muestras x 2 bytes = 1024 bytes
const uint32_t BYTES_POR_BLOQUE = MUESTRAS_POR_BLOQUE * sizeof(uint16_t);

class LectorSD {
  public:

  // buffer donde queda el ultimo bloque leido desde la SD
  // el ampli puede leer las muestras directamente desde aqui
  uint16_t bufferAudio[MUESTRAS_POR_BLOQUE];

  // cantidad de muestras validas que dejo en bufferAudio la ultima lectura
  // normalmente es 512, pero en el ultimo bloque del archivo puede ser menos
  uint32_t muestrasLeidas = 0;

  // funcion inicial: solo guarda los pines, no toca el hardware todavia
  // por defecto usa los pines del SPI1 que no estan ocupados en main.cpp
  LectorSD(uint pinMISO = 8, uint pinCS = 9, uint pinSCK = 10, uint pinMOSI = 11);

  // configura el bus SPI1 con los pines guardados y monta la tarjeta SD
  // se llama una sola vez en el setup, antes del loop principal
  // devuelve true si la tarjeta quedo montada
  bool iniciar();

  // abre un archivo de audio en modo binario de solo lectura, por ejemplo "sonido0.raw"
  // si ya habia un archivo abierto, primero lo cierra
  // devuelve true si el archivo se pudo abrir
  bool abrirArchivo(const char* nombreArchivo);

  // lee el siguiente bloque de hasta 512 muestras y lo deja en bufferAudio
  // devuelve la cantidad de muestras leidas, 0 si el archivo se termino o hubo error
  // si el bloque viene incompleto, el resto del buffer se rellena con silencio
  uint32_t leerBloque();

  // vuelve al inicio del archivo abierto, sirve para el modo loop
  // devuelve true si pudo volver al inicio
  bool rebobinar();

  // cierra el archivo abierto, si es que habia uno
  void cerrarArchivo();

  // devuelve true si la tarjeta SD esta montada
  bool sdLista();

  // devuelve true si hay un archivo abierto
  bool archivoAbierto();

  // devuelve true si ya se leyo todo el archivo
  bool finDeArchivo();

  // devuelve la cantidad total de muestras del archivo abierto
  uint32_t totalMuestras();

  private:

  // pines del bus SPI1
  uint pinMISO;
  uint pinCS;
  uint pinSCK;
  uint pinMOSI;

  // estructura de FatFs que representa el sistema de archivos de la SD
  FATFS sistemaArchivos;
  // estructura de FatFs que representa el archivo de audio abierto
  FIL archivo;

  // indica si la tarjeta ya fue montada
  bool montada = false;
  // indica si hay un archivo abierto
  bool abierto = false;
};

#endif
