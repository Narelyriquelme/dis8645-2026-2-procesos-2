# Proyecto-02
*Integrantes*

☆ Vanessa García /

☆ Isidora Pérez / <https://github.com/isipm08>

☆ Narely Riquelme /

☆ Angel Sabogal / <https://github.com/angel-udp>

## Commodore 64 Ultimate 

El Commodore 64 Ultimate representa el renacimiento de uno de los ordenadores clásicos, siendo una recreación física y fiel de la máquina original. Donde su principal objetivo es ofrecer la misma experiencia nostálgica, recuperando carcasa clásico, pero adaptándola a las necesidades tecnológicas de hoy en día.

Para lograr el parecido a la máquina original, en su interior alberga una placa equipada con un chip AMD Xilinx Artix-7 FPGA, una tecnología que le permite replicar el comportamiento del hardware clásico ciclo a ciclo. Gracias a esto, el equipo alcanza un 99% de compatibilidad con todo el software que se lanzó para el ordenador, al mismo tiempo que incorpora mejoras modernas, como mayor capacidad de memoria y un modo turbo de 48 MHz para optimizar el rendimiento. Finalmente envolviéndose en una carcasa que recupera la estética y esencia clásica del Commodore, integrando interruptores mecánicos Gateron Pro 3.0 de 55 gramos, teclado de 66 teclas y un soporte para macros y tecnología NKRO garantizando escritura fluida.

Este equipo destaca su versatilidad al realizar la conexión entre dos épocas distintas, la evolución de este muestra cómo los computadores pasaron de ser equipos destinados al aprendizaje y al trabajo, a convertirse en herramientas para jugar, crear música, experimentar gráficos, acercando la tecnología y programación a los hogares. Aunque es compatible con cintas de casete, unidades de disco y con televisores de tubo (CRT). Afortunadamente, no todo el mundo está dispuesto a utilizar una consola retro con un monitor CRT (especialmente por el tamaño que ocupa y su elevado peso). Estos usuarios pueden utilizar la salida HDMI a 1080p para conectarlo a monitores y Smart TV actuales (el cable viene incluido junto con el equipo). 

Dentro de su sistema operativo incluye las suite GEOS, como el GEOWrite, que fue uno de los primeros procesadores de texto modernos, con capacidad de edición WYSIWYG, múltiples fuentes y estilos, escribir documentos, dar forma al texto, e inserción de imágenes. Ahora, es un entorno de escritura sin conexión, ideal para diarios personales, ensayos y redacción sin distracciones. También el GEOPaint era un editor gráfico para dibujar y pintar, crear ilustraciones digitales, con patrones, rellenos y pinceles. Se utilizó para crear tarjetas de felicitación, diseños de boletines informativos y muchísimos proyectos de arte digital para principiantes. Ahora es una herramienta creativa sin distracciones, perfecta para artistas digitales emergentes. Y el GEOPublish fue una de las primeras herramientas modernas de autoedición, combinar texto e imágenes. Fue responsable de innumerables periódicos escolares, boletines parroquiales, folletos de pequeños negocios y carteles de bandas musicales. Y también el resto de la suite como GEOSpell, GEOPile, GEOCalc, GEOGif, GEOS Deskpack Plus, Fuentes GEOS, GEODemo.


## Descripción del proyecto

**DORE 8** es un videojuego retro inspirado en la estética del Commodore 64. El proyecto cuenta con una factura técnica desarrollada en C++, luego ejecutada en el microcontrolador Raspberry Pi Pico, tras ser prototipado de forma virtual en la plataforma Wokwi. El relato material sostiene los componentes físicos, tales como: dos perillas, dos botones, una pantalla y buzzer, el cual reproduce música retro y efectos de sonido. Buscando evocar los paneles de control de los microcomputadores en los años ochenta, incluyendo lo físico por parte del jugador con la narraativa digital. El juego tiene como objetivo acompañar y ayudar a un estudiante a llegar a la universidad, superando diferentes desafíos, como recorrer un laberinto para alcanzar la micro, esquivar vehículos durante el trayecto y llegar a su sala de clases. 

En el ámbito visual, adoptamos un estilo de pantallas retro, bloques marcados y delimitados, además de una tipografía geométrica estilo "arcade". Los gráficos se construyen mediante figuras geométricas para optimizar el uso de memoria. Nuestro objetivo es combinar la estética de los videojuegos antiguos con una experiencia interactiva sencilla y entretenida.

Los controles parecen intuitivos, pero al momento de jugar se invierte la usabilidad en momentos clave para simular el estrés y la emoción que se genera el camino a la universidad. En cuanto a estructura, nos centramos en Slides, reforzando la narrativa del sistema de etapas.

### ¿Por qué Dore 8?

El nombre de nuestro proyecto nace como una síntesis conceptual y un homenaje directo. Este se extrae de la terminación ```commodore``` y el número 8 hace referencia a la ```era de los 8 bits```, ya que este es el período en donde los videojuegos y la informática estaba dominada por consolas y microcomputadores cuyos procesadores manejaba la información en bloques de 8 bits por ciclo. De esta forma encapsulamos de manera general los gráficos con figuras geométricas, sonido y uso de controles mecánicos. Y además porque somos el grupo 08 jaja.

### Inspiración: La Influencia del Commodore 64

La referencia al Commodore 64 Ultimate se manifiesta en cuatro pilares fundamentales del proyecto:

1. **Estética Gráfica y Lenguaje Visual:** Uso de bloques visuales marcados, bordes delimitados en pantalla y tipografía geométrica estilo monospaciado, emulando el modo de texto y la construcción de sprites característicos de la época de los 8 bits.
2. **Identidad Sonora (Chiptune):** Generación de melodías tipo *chiptune* construidas bajo el espíritu de la síntesis de onda cuadrada, emulando los tonos del legendario chip de sonido MOS 6581 SID del C64.
3. **Mecánica de Control Retro:** La interacción mediante perillas analógicas e interruptores táctiles evoca los paneles de control integrados y los mandos de los microcomputadores clásicos.
4. **Narrativa de Carga por Etapas:** La transición entre pantallas emula la experiencia de los juegos de cassette o disco de los años 80, donde el jugador avanza slide a slide resolviendo desafíos consecutivos para completar una historia.

## Funcionamiento y Dinámica del Juego

El flujo interactivo se estructura en **5 Slides correlativos**:

* **Slide 1 — Inicio e Instrucciones:** Pantalla de bienvenida con el título del juego, la explicación general de los controles y el planteamiento del desafío: *"Llega a la universidad"*.


* **Slide 2 — Etapa 1 (El Laberinto de la Micro):** El jugador debe mover al personaje a través de un laberinto vectorial para alcanzar el paradero de la micro antes de que el temporizador llegue a cero.


* **Slide 3 — Etapa 2 (La Micro en el Tráfico):** Control del vehículo de transporte público en una vía multicarril. El jugador debe esquivar el flujo de autos en movimiento. Como condicionante de dificultad en esta etapa, el juego activa la **inversión de controles** en las perillas.


* **Slide 4 — Etapa 3 (El Pasillo a la Sala):** Nivel final donde el estudiante transita el pasillo de la universidad para ingresar por la puerta de la sala de clases.


* **Slide 5 — Conclusión y Reflexión:** Pantalla de cierre al completar la meta. Muestra el mensaje *"¡Lo lograste!"* acompañado de una frase reflexiva sobre la resiliencia y la impredecibilidad de la vida diaria (*"Las cosas no siempre son como uno espera... pero igual se logra"*).

## Controles

## Pseudocódigo

## Diagramas
### experiencia usuario
### hardware
### software
## Esquemático 
### Tabla de materiales

|Componente|Cantidad|Precio|Link|
|---|---|---|---|
|Raspberry Pi Pico|1|$14.990|<https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers>|
|Pantalla |1|$3.554|<https://a.aliexpress.com/_mKfPMoB>|
|Protoboard|1|$1.500|<https://afel.cl/products/mini-protoboard-400-puntos>|
|Botón Táctil|2|$200|<https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptor?_pos=1&_sid=cf59c1e34&_ss=r>|
|Cables dupont pack 20|x|$1.000|<https://afel.cl/products/pack-20-cables-de-conexion-macho-macho>|
|Kit 10 Cables Caiman a Dupont Hembra|x|$2.500|<https://afel.cl/products/kit-10-cables-caiman-a-dupont-hembra?_pos=2&_sid=aec538813&_ss=r>|
|Pack 20 Cables de Conexión Macho Hembra|x|$1.000|<https://afel.cl/products/pack-20-cables-de-conexion-macho-hembra?_pos=1&_sid=bff72fae6&_ss=r>
|Potenciómetro B100k|2|$1.000|<https://afel.cl/products/potenciometro-10k-ohm>|
|Cable USB-C|1| $1.800|<https://altronics.cl/cable-usb-tipo-c-datos-alimentacion>|

## Pruebas y error

Durante el desarrollo de DORE 8 fuimos realizando diferentes pruebas en Wokwi para comprobar que los componentes y el código funcionaran correctamente. Al principio comenzamos con un proyecto vacío, donde incorporamos la Raspberry Pi Pico, una pantalla, dos potenciómetros, dos botones, un buzzer y un LED. Realizamos las conexiones manualmente, siguiendo la distribución que queríamos para nuestro prototipo.

Una de las primeras pruebas fue comprobar el funcionamiento del sonido, ya que queríamos que el videojuego tuviera música retro de fondo y efectos sonoros. Para esto trabajamos con una clase llamada Audio, utilizando C++ y Pico SDK, sin Arduino. También probamos las perillas para verificar que permitieran mover un objeto en la pantalla y que los botones respondieran correctamente.

Durante estas pruebas nos encontramos con un error de compilación relacionado con la función stdio_init_all(). Al revisar el problema, identificamos que estaba relacionado con la configuración del entorno de compilación de Wokwi. Modificamos la configuración para utilizar Pico SDK y conseguimos que el programa funcionara.

Después de solucionar este problema, logramos visualizar los primeros gráficos en la pantalla, mover un cuadrado con las perillas y escuchar la música y los efectos del buzzer.

Posteriormente comenzamos a integrar los gráficos del videojuego. Para esto utilizamos como referencia las funciones gráficas de Adafruit, trabajando con figuras geométricas en lugar de imágenes bitmap, con el objetivo de reducir el uso de memoria. Incorporamos los dibujos del estudiante, la micro, los automóviles, el laberinto y las diferentes pantallas.

Otra dificultad que encontramos fue durante la prueba del nivel de la micro. Notamos que el movimiento era demasiado lento y que no resultaba tan claro cómo completar el desafío para avanzar al siguiente. Por eso decidimos modificar el código, reducir el tiempo del nivel de 30 a 15 segundos, aumentar la velocidad y agregar una línea de meta que permitiera identificar el objetivo.

Estas pruebas nos ayudaron a identificar aspectos que debíamos mejorar, tanto en el funcionamiento del código como en la experiencia del jugador. También nos permitieron entender la importancia de probar cada componente por separado antes de integrarlo al videojuego completo.

## Aciertos 

Uno de los principales aciertos durante el desarrollo de DORE 8 fue comenzar probando los componentes de manera individual antes de trabajar en el videojuego completo. Esto nos permitió comprobar que las perillas, los botones, la pantalla, el buzzer y el LED funcionaran correctamente, facilitando la identificación de errores.

Otro acierto fue utilizar C++ con Pico SDK, ya que era uno de los requisitos del proyecto. También decidimos trabajar con clases para mantener el código organizado y poder reutilizar algunas de las desarrolladas anteriormente, como las de las perillas y los botones.

La incorporación del buzzer también fue un avance importante, porque conseguimos reproducir música retro de fondo y efectos de sonido sin detener el movimiento de los elementos en pantalla. Esto nos permitió acercarnos más a la experiencia de los videojuegos antiguos que tomamos como referencia.

En cuanto a los gráficos, consideramos que fue una buena decisión utilizar figuras geométricas inspiradas en las funciones de Adafruit GFX, ya que nos permitió representar los personajes y escenarios sin depender de imágenes bitmap grandes. Además, logramos integrar las ocho pantallas del videojuego, manteniendo una misma línea visual.

Otro aspecto positivo fue establecer que el jugador solamente pudiera avanzar cuando completara cada desafío. Esto permitió que el juego tuviera una secuencia y que cada nivel tuviera un objetivo específico.

También fue importante identificar que algunos elementos necesitaban ajustes, como ocurrió con la velocidad de la micro. Esto nos llevó a mejorar el planteamiento del nivel y hacer más visible la meta.

En general, consideramos que uno de nuestros mayores aciertos fue avanzar de manera progresiva, probando, identificando errores y realizando modificaciones. Gracias a este proceso logramos pasar de un circuito básico en Wokwi a un prototipo de videojuego que integra gráficos, controles, música y diferentes desafíos.

## Carcasa 

## Documentación IA

### Organización del Proyecto por Clases: Juego Arcade (Raspberry Pi Pico)

Para mantener el código ordenado, eficiente en memoria y fácil de presentar, dividiremos el proyecto en **6 Clases independientes**, asignando a cada una su "Lista de supermercado" (**Atributos/Variables**) y sus "Acciones" (**Métodos/Funciones**).

---

```text
                        ┌────────────────────────┐
                        │    GameController      │
                        │ (Cerebro del Juego)    │
                        └───────────┬────────────┘
                                    │
    ┌──────────────┬────────────────┼────────────────┬──────────────┬──────────────┐
    ▼              ▼                ▼                ▼              ▼              ▼
┌─────────┐   ┌─────────┐     ┌───────────┐    ┌───────────┐  ┌───────────┐  ┌───────────┐
│ Botón 1 │   │ Botón 2 │     │ Perilla X │    │ Perilla Y │  │ Audio     │  │PantallaUI │
│ (Slide) │   │ (Audio) │     │ (Horiz.)  │    │ (Vert.)   │  │(Canciones)│  │ (Gráficos)│
└─────────┘   └─────────┘     └───────────┘    └───────────┘  └───────────┘  └───────────┘

```

---

#### 1. Clase `Boton` (Hardware)

* **Responsabilidad:** Lee un botón físico y elimina falsos toques por rebote mecánico (*debounce*).


* **Instancias en el proyecto:** 2 objetos (`botonSlide` y `botonAudio`).


* **Atributos (Variables):**
* `pin`: Pin GPIO de la Pico donde se conecta.
* `ultimoTiempoRebote`: Tiempo en milisegundos para filtrar lecturas erróneas.


* **Métodos (Funciones):**
* `begin()`: Configura el pin en modo entrada digital (`INPUT_PULLUP`).
* `fuePresionado()`: Retorna `true` solo cuando el usuario presiona el botón.





---

#### 2. Clase `Perilla` (Hardware)

* **Responsabilidad:** Lee un potenciómetro analógico, lo traduce a coordenadas de pantalla ($X$ o $Y$) y permite invertir los controles en ciertas etapas.


* **Instancias en el proyecto:** 2 objetos (`perillaX` y `perillaY`).


* **Atributos (Variables):**
* `pinAnalogico`: Pin ADC de la Pico.
* `invertida`: Interruptor booleano (`true`/`false`) para cambiar la dirección de movimiento.




* **Métodos (Funciones):**
* `begin()`: Configura la lectura del puerto analógico.
* `setInvertida(estado)`: Activa o desactiva la inversión de giro según la etapa.


* `obtenerPosicion(min, max)`: Convierte el voltaje en la posición en píxeles de la pantalla.





---

#### 3. Clase `AudioPlayer` (Sonido)

* **Responsabilidad:** Administra el zumbador y reproduce las 3 melodías arcade de forma secuencial sin pausar el juego.


* **Atributos (Variables):**
* `pinBuzzer`: Pin PWM asignado al altavoz.
* `cancionActual`: Número de melodía activa ($1, 2 \text{ o } 3$).




* **Métodos (Funciones):**
* `siguienteCancion()`: Alterna a la siguiente melodía al presionar el botón de audio.


* `actualizar()`: Toca las notas de la melodía en segundo plano.



---

#### 4. Clase `PantallaUI` (Gráficos y Renderizado)

* **Responsabilidad:** Maneja toda la parte visual (pantalla TFT), dibujando textos, gráficos vectoriales e imágenes sin recargar el procesamiento del juego.


* **Atributos (Variables):**
* `tft`: Referencia al objeto del controlador de la pantalla.


* **Métodos (Funciones):**
* `dibujarSlide(numeroSlide)`: Renderiza el fondo y textos fijos para cada una de las 5 etapas (Inicio, Laberinto micro, Esquivar autos, Sala y Conclusión).


* `dibujarEstudiante(x, y)`: Renderiza el gráfico vectorial del personaje en su coordenada actual.
* `dibujarTiempo(segundos)`: Muestra el contador en pantalla.





---

#### 5. Clase `Player` (Personaje)

* **Responsabilidad:** Almacena los datos del estudiante en el mapa y comprueba su estado.


* **Atributos (Variables):**
* `x`, `y`: Coordenadas actuales en pantalla.
* `ancho`, `alto`: Dimensiones del personaje.


* **Métodos (Funciones):**
* `actualizarPosicion(nuevaX, nuevaY)`: Actualiza las coordenadas recibidas desde las perillas.





---

#### 6. Clase `GameController` (El Cerebro)

* **Responsabilidad:** Coordina todo el juego, administra el paso entre los 5 slides, controla el tiempo límite y evalúa si el personaje choca o gana.


* **Atributos (Variables):**
* `slideActual`: Número del slide activo ($0 \text{ a } 4$).


* `tiempoRestante`: Temporizador para las etapas con tiempo límite.




* **Métodos (Funciones):**
* `siguienteSlide()`: Avanza de escena cuando se pulsa el botón correspondiente.


* `actualizar()`: Evalúa si los controles se invierten en el slide actual, actualiza las posiciones, verifica colisiones y le pide a `PantallaUI` que redibuje.


* `verificarColisiones()`: Revisa si el estudiante chocó con paredes/autos o si tocó la meta.





---

####  Flujo de Ejecución del Programa (`main.cpp`)

1. **Creación de Objetos:** Se instancia cada componente (`botonSlide`, `botonAudio`, `perillaX`, `perillaY`, `audio`, `pantalla` y `juego`).


2. **`setup()`:** Se inician las configuraciones de pines con el método `.begin()` de cada objeto.
3. **`loop()`:** Bucle continuo que ejecuta 4 pasos en milisegundos:
* Revisa si se presionó el botón de cambiar slide $\rightarrow$ pasa al siguiente slide.


* Revisa si se presionó el botón de audio $\rightarrow$ cambia la canción.


* Lee el movimiento de las 2 perillas $\rightarrow$ calcula la nueva posición del estudiante.


* Llama a `juego.actualizar()` y `audio.actualizar()` para actualizar gráficos, reglas de juego y música.

wokwi 

https://wokwi.com/projects/479061199676387329 

## Bibliografía

https://commodore.net/computer/ 
https://www.commodore.ca/commodore-history/chronological-history-of-commodore-computer/?utm
https://hardzone.es/noticias/perifericos/precio-especificaciones-commodore-64-ultimate/ 
https://www.ign.com/articles/commodore-64-ultimate-review
https://www.wired.com/review/commodore-64-ultimate/
