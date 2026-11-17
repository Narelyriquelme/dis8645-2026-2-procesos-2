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

### Posibilidades dentro del aspecto de audio

El tiempo máximo de grabación por cada audio es de 30 segundos.

Cada 10 segundos se da la orden de reproducir un audio.

Son 60 posibilidades donde podría iniciar un audio.

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
