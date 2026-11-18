# grupo-01

## integrantes

- [19 - Dayana Pañitrur](https://www.github.com/dayanapanitrur)
- [23 - Camila Ramírez](https://www.github.com/Estrabismx)
- [29 - Bianka Vilchez](https://www.github.com/biankavilchez)

## sobre el proyecto

Nuestra máquina es un instrumento que no es musical ¿o si? es la intervención humana la que lo decide y lo hará por medio de la captura, edición y reproducción del sonido. Por cada nueva intervención que se vaya acumulando sobre la anterior, generará capas de sonido que progresivamente alteran el registro original. Utiliza una lógica de edición irreversible por cada audio que se graba, con efectos y modulaciones de sonido que solo se podrán aplicar para los sonidos grabados más no para el conjunto total de estos, de esta forma las intervenciones quedan almacenadas y transforman continuamente el resultado del conjunto de sonidos. El registro solo se puede reproducir desde el inicio o detener completamente, sin poder recuperar o editar libremente un punto específico del proceso. La lógica irreversible también aplica para el conjunto final de sonidos, el cuál no se puede borrar, solo puede llegar a un límite de audios almacenados.

Dentro del funcionamiento técnico, este es controlado por un microcontrolador Raspberry Pi Pico 2W, el cual se encarga de gestionar las entradas de la interfaz física y el procesamiento del sonido y su manipulación. Para asegurar un rendimiento continuo y evitar las limitaciones de memoria al trabajar con audios muy largos o con muchas capas, el sistema integra un módulo de tarjeta SD, que permite almacenar, sobreescribir y reproducir el conjunto de sonidos grabados de manera fluida.

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

<h5>envolventes</h5>
<ul>
  <li>attack</li>
  <li>decay</li>
  <li>sustain</li>
  <li>release</li>
</ul>

<h5>fx / modulación</h5>
<ul>
  <li>pitching</li>
  <li>reverb</li>
  <li>trémolo</li>
  <li>bit crushing</li>
  <li>ring modulator</li>
  <li>velocidad</li>
</ul>

<h5>ecualización</h5>
<ul>
  <li>high pass filter</li>
</ul>

<h5>niveles / ganancia</h5>
<ul>
  <li>volumen de audio</li>
  <li>volumen general</li>
</ul>

<br>

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
| 5 | Pantalla LCD Oled 1.3" 128x64 | 01 | $5.000 | https://afel.cl/products/pantalla-lcd-oled-1-3-128x64-caracteres-azules | ![](./imagenes/pantalla.webp)
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

#### Modo Grabar

##### Modo Editar

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

<img src="./imagenes/bit-crusher.webp" alt="" width="50%">

<br>

### [Mini Glitch](https://electricmojoguitars.com/products/tkog-mini-glitch)

<img src="./imagenes/mini-glitch.png" alt="" width="50%">

<br>

### [MOOG GRANDMOTHER](https://www.moogmusic.com/synthesizers/grandmother/)

<img src="./imagenes/grandmother.jpg" alt="" width="50%">

### [Kaleidoloop](https://forum.critterandguitari.com/t/kaleidoloop-returns/10321)

<img src="./imagenes/kaleidoloop.png" alt="" width="50%">

### [Circuito Integrado LPC2138FBD64](https://www.y-ic.com/pdf/Freescale-NXP-Semiconductors/LPC2138FBD64.html)

<img src="./imagenes/lpc2138fbd64.jpg" alt="" width="50%">
