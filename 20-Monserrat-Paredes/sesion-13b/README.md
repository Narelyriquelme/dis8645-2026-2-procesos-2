# sesion-13b  →  13/11/26

## apuntes sesión

sesión-13b (viernes 13):

- descripción total del proyecto
- prototipos
- pseudocódigo
- esqueleto en wokwi

---

## Texto descriptivo del proyecto

Nuestro proyecto n°3 se basará en crear un juego donde el jugador debe interactuar con el sistema mediante botones pulsadores y utilizar el sonido como principal medio de comunicación para comprender lo que sucede durante la partida.

El juego consiste en controlar una nave espacial que debe sobrevivir a diferentes ataques enemigos, esquivando obstáculos y eliminando adversarios mediante disparos. A medida que transcurre el tiempo, la dificultad aumenta progresivamente, generando nuevos desafíos que exigen mayor atención y capacidad de reacción. A través de diferentes señales sonoras, el jugador podrá identificar la ubicación de los enemigos, anticipar ataques, reconocer daños en su nave y recibir información sobre su desempeño.

El jugador deberá interpretar las señales auditivas para tomar decisiones, desplazarse entre diferentes posiciones y disparar contra los enemigos antes de recibir un ataque.  La partida termina cuando la nave pierde todas sus vidas. El sistema comunica el resultado mediante una secuencia sonora y permite iniciar una nueva partida. 


### 1. **Mecánica y funcionamiento** 

El videojuego funciona mediante tres posiciones imaginarias: izquierda, centro y derecha. Estas posiciones representan los diferentes sectores del espacio por los que pueden aparecer los enemigos y desplazarse la nave del jugador. Durante la partida, los enemigos aparecen aleatoriamente en cualquiera de estos sectores. El jugador debe reconocer su ubicación mediante las señales emitidas por el parlante y utilizar los botones para desplazarse o disparar. 


### El funcionamiento general se desarrolla de la siguiente manera:

1. **Inicio:** el jugador presiona el botón de inicio y el sistema reproduce una señal sonora que indica que la partida ha comenzado.  
2. **Desarrollo:** aparecen enemigos y obstáculos en diferentes posiciones.  
3. **Identificación:** el parlante reproduce señales específicas que permiten reconocer la ubicación y proximidad de los enemigos.  
4. **Interacción:** el jugador utiliza los botones para desplazarse y disparar.  
5. **Supervivencia:** debe evitar los ataques enemigos y eliminar adversarios para conseguir puntos.  
6. **Dificultad progresiva:** a medida que aumenta el tiempo de juego, los enemigos aparecen con mayor frecuencia y velocidad.  
7. **Finalización:** cuando el jugador pierde todas sus vidas, se reproduce una señal de derrota y se comunica la puntuación final.


### Cada sonido tendrá un significado específico:

* **Pitido hacia la izquierda:** indica la presencia de un enemigo en el sector izquierdo.  
* **Pitido hacia la derecha:** indica la presencia de un enemigo en el sector derecho.  
* **Dos pitidos rápidos:** advierten que un enemigo se está aproximando.  
* **Sonido grave:** indica un ataque enemigo.  
* **Sonido de explosión:** comunica que un enemigo ha sido eliminado.  
* **Sonido de impacto:** indica que la nave recibió un daño.  
* **Alerta repetitiva:** advierte que el jugador se encuentra en su última vida.  
* **Melodía de recompensa:** indica que se consiguió una puntuación adicional o una mejora.  
* **Secuencia de derrota:** comunica que la partida ha terminado.

**Botón 1 – Movimiento hacia la izquierda:** permite desplazar la nave desde el centro hacia el sector izquierdo.

**Botón 2 – Movimiento hacia la derecha:** permite desplazar la nave desde el centro hacia el sector derecho.

**Botón 3 – Disparo:** permite atacar a los enemigos que aparecen durante la partida.

**Botón 4 – Inicio y pausa:** permite comenzar el videojuego, pausar la partida y reiniciarla cuando corresponda.

---

## Bill of Materials (BOM)

| # | Cantidad | Componente | Descripción / Función | Precio unitario | Enlace |
|---|:--------:|------------|------------------------|----------------:|--------|
| 1 | 1 | Raspberry Pi Pico RP2040 | Controlador principal del videojuego | $11.290 | [Comprar]([URL](https://raspberrypi.cl/products/raspberry-pi-pico-w-con-conexion-wifi)) |
| 2 | 1 | Parlante de 8 Ω | Reproducción de señales y efectos sonoros | $2.890 | [Comprar](https://mcielectronics.cl/shop/product/mini-parlante-altavoz-8-ohms-0-5w/?srsltid=AYCX9vJ9-djZf65FXXZwwQeBYD4vnUlDCRA0cK9tNaXlrv1RwtmbaxVus4Q) |
| 3 | 1 | Amplificador PAM8302 | Amplificación de las señales de audio | $0 | [Comprar](URL) |
| 4 | 4 | Botón pulsador | Control de movimiento, disparo e inicio | $500 | [Comprar](https://afel.cl/products/kit-boton-tactil-6x6x5-interruptor-5-unidades) |
| 5 | 4 | Resistencias de 10 kΩ | Opcionales, según la configuración de los botones | $20 | [Comprar](https://afel.cl/products/kit-500-resistencias-1-2w-50-valores) |
| 6 | 1 | Protoboard | Montaje y conexión de los componentes | $1.500 | [Comprar](https://afel.cl/products/mini-protoboard-400-puntos?_pos=1&_sid=0dda10b16&_ss=r) |
| 7 | Variable | Cables | Conexiones eléctricas | $2.000 | [Comprar](https://afel.cl/products/pack-60-cables-de-conexion?_pos=1&_sid=4bf4aa93a&_ss=r) |
| 8 | 1 | Fuente de alimentación USB de 5 V | Suministro de energía | $0 | [Comprar](URL) |

---

## Referentes:

- scanner sombre
  
- giroscopio acelerómetro: usar interacciones como los videojuegos
  
- posición del dispositivo

- ultrasónico

- sensor de distancia

- detector de obstáculos (0-10cm)

- echoes of bats and men

- oregon trail

- jugar con graves y agudos para mostrar distintos sonidos de amenaza o diferentes cosas

- acoustic communication

---

## Pseudocódigo

...


## encargos

## lectura

Libro: A New Program for Graphic Design

Autor: David Reinfurt

El libro está dividido en 3 grandes capítulos.

I. T--Y-P-O-G-R-A-P-H-Y

II. G-E-S-T-A-L-T

III. I-N-T-E-R-F-A-C-E

El autor plantea las bases de lo que significa enseñar diseño gráfico hoy. Introduce la idea de que el diseño no se trata de "estilo" o decoración, sino de sistemas, reglas y tecnología aplicadas a la comunicación.
