// -- Cambios respecto a v00 --
// 1. la validacion del indice usa CANTIDAD_SONIDOS
// 2. enviarSonido() ahora tambien guarda sonidoActual en el ampli
// 3. nuevo metodo reproducirSonido()
// 4. usa los arreglos sonido0..sonido4 de 16 bits y tamano cuenta muestras

// -- Cambios respecto a v02 --
// 1. el constructor tambien acomoda sonidoInicio, sonidoLoop y sonidoApagado
// 2. enviarSonido() deja unaVez en false, para que el loop funcione
// 3. reproducirSonido() respeta margenSonido y devuelve si reprodujo
// 4. nuevos metodos de sistema y sistemaSonando()

// -- Cambios respecto a v06 --
// 1. el constructor asigna la ganancia (volumen base) de cada sonido
// 2. enviarSonido() y reproducirSistema() entregan esa ganancia al ampli

// -- Cambios respecto a v07 --
// 1. el catalogo guarda nombres de archivos .raw de la SD en vez de arreglos
//    ya no se incluyen Sonido0.h a Sonido4.h, asi no ocupan memoria flash
//    los .raw se generan con codigos/convertir-raw/convertirRaw.py
// 2. enviarSonido() carga el sonido con amplificador.cargarArchivo()
//    si el sonido estuviera en flash, usa amplificador.cargarAudio() como antes
// 3. reproducirSonido() no reproduce si el sonido no se pudo cargar

#include "Audio.h"

// los sonidos del catalogo ya no se incluyen aca, se leen desde la tarjeta SD
// incluye el sonido de sistema, que sigue en flash, hecho con script/generarSonidoSistema.py
#include "SonidoSistema.h"

// funcion inicial que se ejecuta al crear la clase
Audio::Audio() {
  // nombre del archivo .raw de cada sonido en la raiz de la tarjeta SD
  // los nombres usan maximo 8 letras + .raw para que cualquier tarjeta los acepte
  // el tamano de cada sonido lo calcula el ampli al abrir el archivo
  catalogo[0].archivo = "sonido0.raw";
  catalogo[1].archivo = "sonido1.raw";
  catalogo[2].archivo = "sonido2.raw";
  catalogo[3].archivo = "sonido3.raw";
  catalogo[4].archivo = "sonido4.raw";

  // volumen base de cada sonido
  // cada uno sube hasta que su pico mas alto toca el maximo (32767), sin distorsion
  // se calcula como 32767 / pico del sonido, redondeado hacia abajo
  // sonido0 queda como viene
  catalogo[0].ganancia = 1.00f;
  // pico 5145, estaba al 15.7 % del maximo
  catalogo[1].ganancia = 6.36f;
  // pico 11064, estaba al 33.8 % del maximo
  catalogo[2].ganancia = 2.96f;
  // pico 26468, estaba al 80.8 % del maximo
  catalogo[3].ganancia = 1.23f;
  // pico 32768, ya estaba al maximo y no se puede subir sin distorsion
  catalogo[4].ganancia = 1.00f;

  // los tres sonidos de sistema usan el mismo arreglo
  // para cambiar uno basta con apuntarlo a otro arreglo
  sonidoInicio.muestras = sonidoSistema;
  sonidoInicio.tamano = sizeof(sonidoSistema) / sizeof(sonidoSistema[0]);
  sonidoLoop = sonidoInicio;
  sonidoApagado = sonidoInicio;
}

// carga en el ampli el sonido elegido por el encoder, sin reproducirlo
bool Audio::enviarSonido(Ampli &amplificador, int indiceEncoder) {
  // revisa si el numero del encoder esta fuera de los limites
  // los numeros validos van de cero a CANTIDAD_SONIDOS - 1
  if (indiceEncoder < 0 || indiceEncoder >= CANTIDAD_SONIDOS) {
    // si el numero es incorrecto sale sin hacer nada para evitar errores
    return false;
  }

  // toma el sonido elegido del estante
  DatosSonido &sonido = catalogo[indiceEncoder];

  if (sonido.archivo != nullptr) {
    // el sonido esta en la SD: el ampli abre el archivo .raw
    // si no hay tarjeta o el archivo no existe, no se carga nada
    if (!amplificador.cargarArchivo(sonido.archivo)) {
      return false;
    }
  } else {
    // el sonido esta en flash: se entrega el arreglo como antes
    amplificador.cargarAudio(sonido.muestras, sonido.tamano);
  }
  // avisa al ampli que sonido quedo cargado
  amplificador.sonidoActual = indiceEncoder;
  // entrega al ampli el volumen base de este sonido
  amplificador.gananciaSonido = catalogo[indiceEncoder].ganancia;
  // los sonidos del catalogo si pueden quedar en loop
  amplificador.unaVez = false;
  return true;
}

// se usa al presionar el encoder
// el orden importa: detener, cargar y luego reproducir
bool Audio::reproducirSonido(Ampli &amplificador, int indiceEncoder) {
  // revisa si el numero del encoder esta fuera de los limites
  if (indiceEncoder < 0 || indiceEncoder >= CANTIDAD_SONIDOS) {
    // si el numero es incorrecto sale sin cortar lo que esta sonando
    return false;
  }

  // leemos el tiempo transcurrido desde que se encendio el microcontrolador
  uint32_t tiempoActual = to_ms_since_boot(get_absolute_time());

  // si algo esta sonando y no ha pasado margenSonido, no se reinicia
  // asi presionar muchas veces seguidas no corta el sonido una y otra vez
  if (amplificador.sonando && (tiempoActual - ultimoSonido < margenSonido)) {
    return false;
  }

  // calla el sonido anterior sin cambiar el modo loop
  amplificador.detener();
  // carga el sonido elegido
  // si no se pudo cargar (sin SD o sin archivo), no se reproduce nada
  if (!enviarSonido(amplificador, indiceEncoder)) {
    return false;
  }
  // reproduce el sonido nuevo
  // como enLoop no se toco, si el loop estaba activo sigue activo
  amplificador.reproducir();
  // guarda el momento para medir el margen la proxima vez
  ultimoSonido = tiempoActual;
  return true;
}

// suena al encender la raspi
void Audio::reproducirInicio(Ampli &amplificador) {
  reproducirSistema(amplificador, sonidoInicio);
}

// suena al activar el modo loop
void Audio::reproducirLoop(Ampli &amplificador) {
  reproducirSistema(amplificador, sonidoLoop);
}

// queda listo por si se agrega una forma de apagar la maquina
void Audio::reproducirApagado(Ampli &amplificador) {
  reproducirSistema(amplificador, sonidoApagado);
}

// devuelve true mientras suena un sonido de sistema
// unaVez solo es true cuando el sonido cargado es de sistema
bool Audio::sistemaSonando(Ampli &amplificador) {
  return amplificador.sonando && amplificador.unaVez;
}

// detiene lo que suena, carga el sonido de sistema y lo reproduce una sola vez
void Audio::reproducirSistema(Ampli &amplificador, DatosSonido &sonido) {
  // calla el sonido anterior, nunca suenan dos a la vez
  amplificador.detener();
  // carga el sonido de sistema
  amplificador.cargarAudio(sonido.muestras, sonido.tamano);
  // -1 indica que el sonido cargado no es del catalogo
  amplificador.sonidoActual = -1;
  // entrega al ampli el volumen base del sonido de sistema (1.0, queda como viene)
  amplificador.gananciaSonido = sonido.ganancia;
  // aunque el loop este activo, este sonido no se repite
  amplificador.unaVez = true;
  // reproduce el sonido de sistema
  amplificador.reproducir();
}
