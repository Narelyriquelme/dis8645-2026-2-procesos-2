# grupo-01

## integrantes

- [19 - Dayana Pañitrur](https://www.github.com/dayanapanitrur)
- [23 - Camila Ramírez](https://www.github.com/Estrabismx)
- [29 - Bianka Vilchez](https://www.github.com/biankavilchez)

## sobre el proyecto

Nuestra máquina es un instrumento que no es musical ¿o sí? sin la intervención de quien la usa no produce nada, pero lo que resulta sea música o ruido depende de quien lo escucha. Nuestro proyecto recorre 3 etapas de interacción: captura, edición y reproducción del sonido. En la fase de captura, se incorpora un botón y un micrófono el cuál está articulado para que la persona pueda grabar su voz, disponiendo de un máximo de 30 segundos por grabación.

En la etapa de edición, cada grabación utiliza una lógica de edición irreversible. El dispositivo tiene una sección física de edición con efectos y modulaciones, controlables con deslizadores, perillas y botones. Al terminar una grabación, esta queda repitiéndose en bucle disponible para ser editada y solo a esta se le podrán aplicar los efectos. Una vez que ya se hayan hecho los cambios y almacenado a la mezcla de sonidos, ya no se podrán realizar más modificaciones.

En la etapa de reproducción las grabaciones se acumulan en una mezcla de unos diez minutos, dividida en 60 puntos de inicio, uno cada 10 segundos. Cada nueva grabación se ubica en uno de esos puntos y como puede durar hasta 30 segundos, se superpone con las que suenan cerca de ella. La lógica irreversible que se incorpora para cada audio individual, también aplica para la mezcla de sonidos, de esta manera solo se puede reproducir desde el principio o detener por completo: no se puede pausar ni avanzar a un punto específico. Tampoco se puede borrar. Una vez que los 60 puntos de inicio hayan sido totalmente ocupados, la máquina ya no permite grabar más, solo reproducir la mezcla final. El sonido sale por un altavoz con una perilla de volumen, y una pantalla muestra una abstracción gráfica de cuán saturada está la mezcla.

Dentro del funcionamiento interno, este dispositivo es controlado por una Raspberry Pi Pico 2 W, la cual se encarga de gestionar las entradas y salidas de la interfaz física correspondientes a las conexiones con perillas, sliders, botones, leds, altavoz y pantalla, y también gestiona el procesamiento del sonido y su manipulación. Para asegurar un rendimiento continuo y evitar las limitaciones de memoria de la Raspi al trabajar con audios muy largos o con muchas capas, el sistema integra un módulo de tarjeta SD, que permite almacenar y reproducir el conjunto de sonidos grabados de manera fluida.


### Interfaz

![](./imagenes/estructura.png)

La interfaz se organiza en tres zonas principales: reproducción, grabación y edición. La zona de reproducción se ubica a la izquierda e incorpora una pantalla para visualizar los datos del sonido, un parlante y los botones Play y Stop. Se decide incorporar una perilla de volumen en el lateral, ya que, al enfrentarse a la máquina, el usuario encontrará esta primera sección. Por ello, se considera importante disponer de este control cerca del botón Play, facilitando el ajuste del volumen durante la reproducción.

La zona de grabación se dispone al centro y contiene un micrófono y un botón para iniciar la captura de audio. Finalmente, la zona de edición se ubica a la derecha y reúne perillas deslizantes para modificar los efectos, acompañadas de indicadores luminosos de colores que permiten identificar visualmente sus rangos e intensidades. En el lateral de esta sección se incorpora otra perilla para ajustar el volumen del audio antes de guardarlo.

Con esta distribución se busca generar una lectura intuitiva de izquierda a derecha, como una guía de pasos que orienta al usuario a través de las distintas acciones: reproducir, grabar y editar. De esta manera, se diferencian las funciones, se facilita la lectura de los controles y se hace más intuitiva la interacción con el dispositivo.

### Posibilidades dentro del aspecto de audio

El tiempo máximo de grabación por cada audio es de 30 segundos.

Cada 10 segundos se da la orden de reproducir un audio.

Son 60 posibilidades donde podría iniciar un audio.

<br>

#### Modificadores de sonido

| Categoría | Efecto | Descripción original | Descripción simplificada | Descripción coloquial |
| :--- | :--- | :--- | :--- | :--- |
| Envolventes | Attack | regula en cuánto tiempo tarda el sonido en llegar a su volumen máximo desde que empieza, le importa cuándo y cómo inicia, no importa cómo termina. | tiempo que demora el sonido en aparecer desde el silencio hasta su punto máximo. | si el sonido entra de golpe o despacio. |
| Envolventes | Release | regula en cuánto tiempo tarda el sonido en apagarse por completo desde que dejas de tocarlo, le importa cuándo y cómo termina, no cómo empezó. | tiempo que demora el sonido en desaparecer al soltarlo. | si el sonido se corta en seco o se va apagando de a poco. |
| FX / Modulación | Pitching | modifica la altura tonal del sonido para hacerlo más agudo o más grave sin cambiar necesariamente su duración, alterando directamente la afinación de la señal. | sube o baja qué tan agudo o grave suena el audio. | dejar el sonido más finito o más grueso. |
| FX / Modulación | Reverb | agrega rebotes y cola al sonido simulando las dimensiones de un espacio físico, cambiando la sensación de amplitud y distancia alrededor del audio. | simula el tamaño y el rebote del lugar donde suena el audio. | hacer que suene seco o con eco de un lugar grande. |
| FX / Modulación | Trémolo | hace que el volumen suba y baje de manera repetitiva siguiendo un ritmo constante, manteniendo el tono intacto mientras oscila solo su intensidad. | oscilación rápida y repetitiva del volumen. | hacer que el volumen suba y baje rápido todo el rato. |
| FX / Modulación | Bit crushing | reduce la resolución y la calidad digital del sonido, perdiendo detalles limpios para generar una textura áspera, granulada y sucia. | baja la calidad del audio hasta volverlo áspero y pixelado. | queda el sonido roto, sucio y con poca calidad. |
| FX / Modulación | Ring modulator | multiplica el sonido original por otra onda interna creando frecuencias nuevas y disonantes, haciendo que pierda su forma natural y tome un carácter metálico. | cruza el audio con otra señal para volverlo metálico y disonante. | vuelve el sonido metálico, robótico o raro. |
| FX / Modulación | Velocidad | controla qué tan rápido o lento se reproduce el audio en el tiempo, lo que al cambiar el ritmo también suele alterar qué tan agudo o grave se escucha. | acelera o frena el tiempo de reproducción del audio. | poner el audio más rápido o más lento. |
| Niveles / Ganancia | Volumen de audio | regula la intensidad de un sonido o pista individual antes de juntarse con el resto, y luego se integrará con ese nivel de volumen a la mezcla de sonidos | controla qué tan fuerte suena una sola pista. | subirle o bajarle el volumen a un solo sonido sin tocar el resto. |
| Niveles / Ganancia | Volumen general | regula la intensidad de salida de toda la mezcla, controlando el nivel final que escuchas al sumar todos los sonidos y efectos. | controla la fuerza final de todo el conjunto a la vez. | sube o baja el volumen general |

### Diagramas

![](./imagenes/dis8645-2026-2-v02.png)

![](./imagenes/dis8645-2026-2.png)

### BOM

| # | Item                 | Cant. | Valor   | Link | Imagen |
| - | -------------------- | ----- | ------- | ---- | ------ |
| 1 | Raspberry Pi Pico 2W | 01     | $14.990 | <https://mcielectronics.cl/shop/product/raspberry-pi-pico-2-w-con-headers/> | <img src="./imagenes/pi-pico-2w.png" alt="" width="100%"> |
| 2 | Micrófono I2S INMP441 | 01 | $5.890<sup><b>1</b> | <https://www.mechatronicstore.cl/modulo-microfono-i2s-inmp441/> | <img src="./imagenes/microfono.jpg" alt="" width="100%"> |
| 3 | PCM5102A decodificador DAC | 01 | $1.122<sup><b>2</b> | <https://es.aliexpress.com/item/1005006104038963.html> | ![](./imagenes/pcm.avif) |
| 4 | Módulo PAM8302 | 01 | $720<sup><b>2</b> | https://es.aliexpress.com/item/1005007274382818.html | ![](./imagenes/amp.avif) |
| 5 | Pantalla LCD Oled Azul y Amarillo 0,96 | 01 | $4.500 | https://afel.cl/products/pantalla-lcd-oled-azul-y-amarillo-0-96 | ![](./imagenes/pantalla.jpg)
| 6 | Módulo Multiplexor CD74HC4067 | 02 | $2.000 | https://afel.cl/products/modulo-multiplexor-cd74hc4067 | ![](./imagenes/multi.webp) |
| 7 | Botones | 
| 8 | Potenciometros |
| 9 | Luces led |
| 10 | Slider |

### pseudo - código

- Se establece que:
  - `sonido` es una grabación sin ninguna modificación. Es nuestro pez
  -  Al editar sus parámetros la entendemos como `audio`. Ahora nuestro pez es un pescado
  - Una vez que se guarda, se añade a los demás `audios` y forma un `conjuntoDeAudios`. Este es nuetro pescado cocinado, no se puede "_**des**cocinar_"
  -Todos los `audios` guardados se reproducen en nuestro `canvas`, es decir, nuestro lienzo que podemos reproducir en cualquier momento pero no editar. El equivalente a decir el tamño del plato

- Ahora se inicia la máquina con el interruptor

```cpp

bool interruptorGeneral; // valor asociado a la lectura del switch o botón 
bool funcionamientoMaquina; // depende del interruptorEncendido
// si es true la maquina realiza sus funciones con normalidad
// si es false, la maquina debe tener un led encendido que indica que recibe corriente

if (interruptorGeneral){
funcionamientoMaquina = 1;}

```

- Se consulta si hay `conjuntoDeAudios`

- En caso de haber, se encienden 2 leds que indican la posibilidad de realizar 2 acciones (es decir que cada `led` es un indicador de uso de cada modo), estos corresponden a `reproduccion` y `grabacion`

    - `reproduccion` permite escuchar el `conjuntoDeAudios`

        - Al activar esta opción, se inhabilta el modo grabar mientras dure la reproducción (se apagan sus leds indicadores y los bótones dejar de ser leidos)

        - Posee 2 botones, uno de `reproducción` y otro de `detener` (no confundir con `pausa`), este segundo detiene la reproducción del `conjuntoDeAudios` y deja seteado en el inicio el `canva`, de modo que si se vuelve a dar a reproducir se hará desde el segundo 0 

        - La reproducción de `audios` es siempre en bucle
        
    - `grabacion` permite guardar sonidos de hasta un máximo de 10 segundos

        - Para grabar se presiona el boton asociado

        - para detener la grabacion antes de los 10s se vuelve a presionar el botón. Esto inicia automáticamente el modo de `edición`

        - Mientras esto ocurre se bloquea cualquier otro modo e inica la reproducción en bucle del sonido hasta que se guarde

        - Además los leds asociados a los efectos empiezan a variar su brillo mediante PWM

        - Estos efectos de sonido se dividen en 3 secciones con 3 modificadores cada una

        - Cada sección posee su potenciómetro deslizable que modifica los valores asociados

        - Al seleccionar un efecto se mantiene oscilando el led, mientras que todos los demás se apagan

        - Para terminar con el efecto y guardar sus cambios se presiona el botón asociado o se selecciona otro efecto

        - Al terminar de editar se guarda el `audio` con su botón asignado y se deja de reproducir en bucle

        - Una vez guardado el `audio` se le asigna una posición "aleatoria" en la que va a sonar en el `conjuntoDeAudios`

- En caso de no haber `conjuntoDeAudios` se bloquean todas las funciones a exepción de `grabar`, la cual al iniciarse ocurre con normalidad tal como se describio anteriormente

- Si la máquina es apagada desde el `interruptorGeneral`, el `conjuntoDeAudios` debe quedar almancenado

#### Modo Reproducir

Encargado de la reproducción del `conjuntoDeAudios`, utiliza 2 botones y posee una pantalla para visualizar desde la cantidad de audios que existen dentro del conjunto hasta la frecuencia con la que pueden ingresar cada audio. Los 2 botones son para la reproducción del conjunto y para detener la reproducción.

El elemento de la pantalla muestra [...]

`botonReproducir` es la instancia de la clase BotonGrupo1 y consiste de un push button, este lee y detecta cuando es presionado el botón, ignora doble click, cuanto tiempo se presiona (sin contar el _debounce_), una vez que inicia se debe utilizar `botonDetener`para detener el bucle

`botonDetener` es la instancia que detiene y cancela la reproducción

> revisar que tan necesario son 2 botones que hagan esto, ver que sea solo uno o un switch

#### Modo Grabar

Inicia presionando `botonGrabar`, el que solo detecta presionados y cambio de estados, es decir que se presiona una vez para iniciar y una segunda vez para cortar la grabación antes de 10 segundos (este corresponde al límite de duración que posee la grabación), posee un pequeño tiempo para que no se presione 2 veces y queden grabados de menos de 0.5s.

Una vez que se detiene la grabación con el segundo _click_ automáticamente se inicia la edición del sonido grabado

##### Modo Editar

Al entrar a esta sección el sonido grabado, se reproduce en bucle para notar como los efectos interfieren en tiempo real. Para seleccionar alguno de estos se observará que  

<br>

#### Estructura

Se considera ordenar el código en distintas clases, a continuación se listan algunas a considerar

- Boton (lectura de botones)

- Perilla (lectura de perillas)

- Multiplexor (pensado en un multiplexor para optimizar la lecutra de perillas)

- Lucesita (describen el funcionamiento de los distintos estados)

- [NombreEfecto] (se encarga de la complejidad de como debe modificar el `audio`)

- Aleatoriedad (es una estructura que simula aleatoriadad necesaria para el funcionamiento de la máquina)

- Conversor (lógica detrás de la placa ---- que convierte audio digital a análogo)

- Amplificacion (lógica detrás de la placa ---- que convierte amplifica el sónido)

- Reproduccion (define al modo `reproduccion`)

- Grabar (define al modo `grabar`)

- Borrar (define al modo `borrar`)

- Microfono (establece como se comunica el micrófono con el microcontrolador)

- SDCard (se encarga de la lógica detrás de la grabación y lectura de datos)

### Wokwi

https://wokwi.com/projects/480724591872061441

## Referentes

### [NYQUIST - Bit Crush](https://notpedals.com/products/nyquist)

<br>

Este es un pedal de efectos hechos con componentes analógicos. El efecto que produce es como el de pixelar el sonido, haciendo que este pierda nitidez. Nosotras rescatamos el efecto como tal y lo integramos a nuestra sección de edición de audio.

<img src="./imagenes/bit-crusher.webp" alt="" width="50%">

<br>

### [Mini Glitch](https://electricmojoguitars.com/products/tkog-mini-glitch)

<br>

Es un pedal que crea un glitch aleatorio en el sonido y sirve también para hacer looping experimental. Funciona capturando una muestra corta de señal y luego la repite, en otras palabras graba por sobre sí mismo y se realiza un feedback. Lo que rescatamos de este pedal es el funcionamiento que tiene: el bucle, el efecto de glitch y por sobre todo que use su propia señal para repetir es una lógica que nuestro proyecto busca al introducir audios sobre otros.

<img src="./imagenes/mini-glitch.png" alt="" width="50%">

<br>

### [MOOG GRANDMOTHER](https://www.moogmusic.com/synthesizers/grandmother/)

<br>

El Grandmother de Moog, pertenece a una familia de sintetizadores analógicos semimodulares, que quiere decir que tiene 41 puntos de conexión para conectar con otros módulos de sonido, pero que también se puede usar individualmente sin conectar cables.
Este es uno de nuestros principales referentes porque desde aquí pudimos interactuar de manera tangible para comprender como se modula el sonido a través de los efectos que se aplican a las ondas propias de los osciladores del sintetizador.

Por otra parte, hay varias cosas que al momento de estar utilizando este dispositivo nos hicieron ruido respecto a la accesibilidad y organización de la interfaz, por ejemplo, el hecho de que nos costó demasiado encontrar el volumen general, el cuál estaba en un lugar con poca jerarquía visual y pasaba muy desapercibido al estar contiguo al efecto de reverb y, si bien estaba en la sección de output, habían perillas que parecían ser más importantes que esta.

<img src="./imagenes/grandmother.jpg" alt="" width="50%">

### [Kaleidoloop](https://forum.critterandguitari.com/t/kaleidoloop-returns/10321)

El Critter & Guitari Kaleidoloop es un sampler y looper portátil diseñado para grabar sonidos, crear bucles con estos y manipularlos en tiempo real. 

Esta fue otra de las máquinas que apenas la vimos nos abrió muchas respuestas como también muchas preguntas. Partiendo desde cómo podría interactuar el usuario con la interfaz, ya sea en el gesto de acercarse a grabar su voz, o incluso abriendo la discusión sobre si el usuario tiende a grabar solo presionando una vez el botón o manteniéndolo presionado.

<br>

<img src="./imagenes/kaleidoloop.png" alt="" width="50%">

### [Circuito Integrado LPC2138FBD64](https://www.y-ic.com/pdf/Freescale-NXP-Semiconductors/LPC2138FBD64.html)

<img src="./imagenes/lpc2138fbd64.jpg" alt="" width="50%">
