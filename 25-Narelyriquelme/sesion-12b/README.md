# sesion-12b

## apuntes sesión

Esta clase fue de **retroalimentación del proyecto 02** y de orientaciones para el **proyecto 03**, que va a ser de máquinas que suenan. Además vimos cómo funciona el protocolo I2S para sacar audio desde la Raspberry.

Flujo de la clase: feedback del proyecto 02 → cómo citar bien → reglas del proyecto 03 → sonido y audio (I2S).

---

### Citar y referenciar desde ya

Misa insistió en que hay que citar bien y hacerlo desde el comienzo del proyecto, porque si lo dejamos para el final vamos a sufrir en el seminario sos.

- **Marco teórico y referentes**: hay que acreditar las fuentes y citarlas.
- **Argumentar**: no basta con poner referencias, hay que explicar por qué tomamos cada decisión.
- **Zotero**: es el software que recomendaron para manejar la bibliografía. Las referencias se guardan con este formato:

---

### Comentarios del proyecto 02

Nos dieron comentarios de nuestro proyecto para mejorar de cara a la siguiente entrega:

- Mejorar la **descripción de los componentes**.
- Mejorar la **interfaz adversarial**.
- Hacer una **documentación más extensa**.
- Incluir y mejorar el **esquemático**.
- Revisar la **ortografía** y la redacción.
- Agregar **diagramas de flujo** para explicar mejor cómo funciona el proyecto.

También se habló de las dudas, de lo que nos ha gustado y lo que no del proceso.

---

### Proyecto 03: requisitos y opciones

- **Mini entregables** en cada clase, que se evalúan.
- Se mantienen los **grupos de 4**.
- **No hay más materia**: se trabaja con mini cápsulas.
- El **parlante es obligatorio** y la **pantalla es opcional**.
- Las máquinas tienen que sonar. Pueden tener micrófono para grabar algo y reproducirlo.
- Si se usa parlante, **no buzzer**.
- **No se puede usar el chip 386**.

#### Módulo grabador de audio

- **ISD1820**: módulo para grabar y reproducir audio. Funciona con voltaje y **no se programa con código**.

---

### Protocolo I2S

- **Salida de audio**: Raspberry + amplificador **MAX98357A**.
- **Lectura analógica (ADC)**: potenciómetro.
- **Lectura digital**: encoder KY-040 + pulsadores.

**I2S** sirve para intercambiar audio digital entre dispositivos que procesan sonido.

- Usa una **señal de reloj compartida** para sincronizar la transmisión, y así el audio viaja en serie.
- Permite transmitir audio de **alta calidad**.
- Funciona con arquitectura **controlador / dispositivo**.
- Siempre se envía primero el **MSB** (bit más significativo).
- Usa **tres líneas**: reloj de bits, selección de palabra (define el canal estéreo, izquierdo o derecho) y datos.

---

### Links varios

- https://www.brandnewnoise.com/
- https://bleeplabs.com/the-bleep-drum/
- https://hubot.cl/producto/modulo-conversor-adc-audio-estereo-pcm1808-24-bits-96-khz-i2s/
- https://www.korg.com/cl/products/dj/volca_sample_okgo_edition/index.php
- https://www.youtube.com/watch?v=UQ7BZlV_0zQ&t=108s
- https://www.elf-audio.com/koala/how-it-was-made.php

Sobre I2S y el amplificador:

- https://www.digikey.com/en/maker/tutorials/2023/what-is-the-i2s-communication-protocol
- https://www.keysight.com/blogs/en/tech/bench/2022/04/29/the-i2s-protocol-and-why-digital-audio-is-everywhere
- https://es.wikipedia.org/wiki/I%C2%B2S
- https://es.aliexpress.com/item/1005006823938000.html (MAX98357A)

---

## encargos

## lectura
