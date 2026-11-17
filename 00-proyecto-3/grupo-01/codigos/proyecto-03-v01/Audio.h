// -- Cambios respecto a v00 --
// 1. nueva constante CANTIDAD_SONIDOS en lugar del 5 y el 4 fijos
// 2. enviarSonido() ahora tambien guarda sonidoActual en el ampli
// 3. nuevo metodo reproducirSonido() para usar al presionar el encoder
// 4. muestras pasa de uint8_t a uint16_t y tamano cuenta muestras, no bytes

// -- Cambios respecto a v02 --
// 1. nuevos sonidos de sistema: sonidoInicio, sonidoLoop y sonidoApagado
//    por ahora los tres usan el mismo arreglo, sonidoSistema
// 2. nuevos metodos reproducirInicio(), reproducirLoop() y reproducirApagado()
// 3. nuevo metodo sistemaSonando() para bloquear los controles mientras suena uno
// 4. nuevo atributo margenSonido: tiempo minimo para volver a reproducir
//    un sonido que esta sonando, asi no se reinicia muchas veces seguidas
// 5. reproducirSonido() ahora devuelve true si alcanzo a reproducir

// -- Cambios respecto a v06 --
// 1. DatosSonido tiene un nuevo campo ganancia: volumen base propio de cada sonido
//    sonido1 a sonido4 suben hasta que su pico toca el maximo, sin distorsion

// -- Cambios respecto a v07 --
// 1. DatosSonido tiene un nuevo campo archivo: nombre del .raw en la tarjeta SD
//    los sonidos del catalogo se leen desde la SD y ya no ocupan memoria flash
//    los sonidos de sistema siguen en flash, asi suenan aunque no haya SD
// 2. enviarSonido() ahora devuelve true si alcanzo a cargar el sonido

#ifndef AUDIO_H
#define AUDIO_H

// incluye la clase del amplificador para poder enviarle los datos
#include "Ampli.h"
// incluye los tipos de datos de tamano exacto
#include <stdint.h>

// cantidad de sonidos del catalogo
// si se agrega un sonido solo hay que cambiar este numero y el constructor
const int CANTIDAD_SONIDOS = 5;

// agrupa los datos de un sonido en un solo paquete
// un sonido puede estar en flash (muestras y tamano) o en la SD (archivo)
struct DatosSonido {
  // puntero al arreglo de muestras de 16 bits del sonido
  // vale nullptr si el sonido esta en la SD
  const uint16_t* muestras = nullptr;
  // cantidad de muestras del arreglo de audio
  uint32_t tamano = 0;
  // nombre del archivo .raw en la tarjeta SD, por ejemplo "sonido0.raw"
  // vale nullptr si el sonido esta en flash
  const char* archivo = nullptr;
  // volumen base propio del sonido, 1.0 lo deja como viene
  // sirve para que los sonidos grabados mas bajos suenen parejo con los demas
  // se calcula como 32767 dividido por el pico mas alto del sonido
  // si es mayor, los picos se recortan y el sonido se distorsiona
  float ganancia = 1.0f;
};

class Audio {
  public:

  // arreglo que funciona como estante de sonidos
  // solo guarda los sonidos que se eligen con el encoder
  DatosSonido catalogo[CANTIDAD_SONIDOS];

  // sonidos de sistema, se guardan aparte del catalogo
  // para que el encoder no los pueda seleccionar
  // suenan una sola vez, aunque el loop este activo
  // suena al encender la raspi
  DatosSonido sonidoInicio;
  // suena al activar el modo loop
  DatosSonido sonidoLoop;
  // queda listo por si se agrega una forma de apagar la maquina
  DatosSonido sonidoApagado;

  // tiempo minimo en milisegundos para volver a reproducir
  // si se presiona el encoder mientras algo suena
  uint32_t margenSonido = 50;
  // momento en que se reprodujo el ultimo sonido del catalogo
  // lo usa reproducirSonido() para revisar margenSonido
  uint32_t ultimoSonido = 0;

  // funcion inicial que acomoda los arreglos en el estante
  Audio();

  // carga en el ampli el sonido elegido por el encoder, sin reproducirlo
  // devuelve false si el indice no existe o si el archivo no se pudo abrir en la SD
  bool enviarSonido(Ampli &amplificador, int indiceEncoder);

  // se usa al presionar el encoder
  // detiene lo que suena, carga el sonido elegido y lo reproduce
  // si el modo loop esta activo el nuevo sonido tambien queda en loop
  // si algo suena y no ha pasado margenSonido no hace nada y devuelve false
  // tambien devuelve false si el sonido no se pudo cargar desde la SD
  bool reproducirSonido(Ampli &amplificador, int indiceEncoder);

  // reproducen los sonidos de sistema una sola vez
  void reproducirInicio(Ampli &amplificador);
  void reproducirLoop(Ampli &amplificador);
  void reproducirApagado(Ampli &amplificador);

  // devuelve true mientras suena un sonido de sistema
  // mientras tanto main.cpp no deja usar los botones ni el encoder
  bool sistemaSonando(Ampli &amplificador);

  private:

  // la usan los tres metodos de sistema
  // detiene lo que suena, carga el sonido y lo reproduce una sola vez
  void reproducirSistema(Ampli &amplificador, DatosSonido &sonido);
};

#endif
