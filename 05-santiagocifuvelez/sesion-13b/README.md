# sesion-13b
# Te escucho tocar, Santiago...

**Realizado por:**  
*Francisca Jesús Palma Cuevas (frannciscapalma)*
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*Nicolás Elías Valdés Greve (nicolasvaldesgreve)*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*Santiago Cifuentes Vélez (santiagocifuvelez)*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*Tomás Antonio Catrileo Curihual (tomascatri)*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

## Descripción del trabajo

Te escucho tocar Santiago, es un sampler fisico tangible que permite recorrer acusticamente cuatro trayectos en los medios de transporte más comunes para lxs estudiantes univresitarios los cuales toman como punto de partida general el barrio universitario, especificamente la universidad Diego Portales, hasta la casa de cada unx de ellxs en la ciudad de Santiago de Chile.

Este proyecto nace desde la rutina que se crea entorno a los medios de transportes y nuestra convivencia del traso que se vuelve huella en nuestro día a día cuando vamos de un lugar a otro. Tanto así, que solemos anticipar sonidos en nuestras cabezas para adelantarnos,
"se inicia el cierre de puertas",
o el grito del frenazo del metro cuando comienza a detenerse y en vez de ser incomodo, es la antitesis de la felicidad de saber que es tu turno de ir a casa. 

(El ejemplo anterior fue tomando como ejemplo el metro, pero lo mismo sucede con el transporte que usted tome).

Pero bueno, aunque la prosa poetica romantice los sonidos con los cuales nos familiarizamos a lo largo de nuestra vida, este proyecto tambien busca resaltar su concepto de cuna, el cual empieza con la _justicia acústica_, ya que no todos los trayectos suenan igual, el ruido de la ciudad se vive de forma distinta dependiendo de cómo y por dónde nos movamos. 

## ¿Cómo funciona este sampler?
Este instrumento contiene sonidos pre-grabados del recorrido casa-universidad que se representa en un mapa de Santiago de Chile con 4 líneas las cuales inician por los hogares de cada integrante del grupo (4 integrantes = 4 líneas), y todas terminan en un punto en común: el barrio Universitario; metro República; Universidad Diego Portales.

Cada línea tiene 6 puntos de contacto, en donde cada punto tiene un sonido grabado en ese tramo del viaje. Al pasar la línea con el dedo o un caimán el sensor capacitivo detecta en qué punto esta el contacto y reproduce el sonido, el cual dura mientras hay contacto y vuelve al silencio al soltar.

Nuestro sampler; Te escucho tocar, Santiago... cuenta con dos fases: 
- **Exploración liberal:** sonido como reacción al paso del dedo del usuario.
- **Exploración de composición:** sonidos que se pueden grabar para reproducir a manera de secuencia. Aquí es donde nuestro instrumento se define como sampler.

Entonces: 
1. El instrumento se compone de 4 líneas que representan el recorrido de cada integrante.
2. Cada línea tiene 6 sonidos pre-grabados en coherencia al transporte allí escogido.
3. Al pasar el dedo por encima de la línea siguiendo el recorrido se pueden activar y escuchar los sonidos dependiendo de la ubicación del dedo. 
4. **Botón 1 = grabar:** 
Para grabar la secuencia de sonidos por donde el usuario paso su dedo, ya sea una sola línea o entre líneas, nuestro sampler va a tener un botón 1: grabar.
- Si se oprime una sola vez = grabar
- Si se vuelve a oprimir = dejar de grabar

5. **Botón 2: = reproducir composición** 
Para reproducir la grabación de la secuencia de sonidos que se compuso, está el botón 2. 
- Si se oprime una sola vez = reproduce composición.
- Si se vuelve a oprimir = se pausa la composición. 

6. **Botón 3 = resetear la maquina**
Este botón permite limpiar alguna secuencia ya grabada. Reset.

7. **Perilla 1 = tempo:**
Velocidad de reproducción de la secuencia que se compuso.

8. **Perilla 2 = Volumen**
Graduar el volumen del sampler.

## Carateristicas de diseño
1. 9v 
2. Standalone
3. Fuente abierta
4. Bajo licencia del MIT
5. Lenguaje c++
6. agregar méssss

## Referente: 

**Stylophone:** 
Dispositivo en el cual el usuario interactua con el instrumento mediante una herramienta conductora. El instrumento tiende al silencio, y solo se permite generar sonidos al hacer contacto con la interfaz del instrumento mediante la herramienta conductora, y deja de sonar cuando se separa de este.

**korg volca sample 1:**

## Registro sonoro

Cada integrante grabó su recorrido casa-universidad en un medio de transporte distinto:

1. Metro (Fran): Línea 1 y 5.
2. Micro (Nico): 210 y E07
3. Colectivo (Tomás): Cerro navia 
4. Bicicleta (Santi): Vargas Buston 

#### Criterios de grabación

Acordamos qué sonidos grabar...

| Sonido    | Metro     | Micro | Colectivo | Bicicleta |
| -------- | --------- | ----- | --------- | --------- |
| Sonido 1 | perro     | pájaros | sonidos de las llaves |  Reja de la casa al cerrarse para salir.         |
| Sonido 2 | torniquete| tintineo micro | hola se paga | La cadena de la bicicleta al pedalear.           |
| Sonido 3 | inicio metro | "permiso"s | radio sonando | La respiración agitada.           |
| Sonido 4 | vendedores <br> ambulantes | cantante micro <br> (en su defecto, <br> alguien predicando) | direccionales sonando  |Tomar agua.           |
| Sonido 5 | Estación Central| sonido motor micro (ayuda) | se sube un pasajero   |Los autos en la avenida.           |
| Sonido 6 | Permisooo| "la puertaa" |  adios y gracias  | Clic del seguro del parking de la bicicleta |

---

## Bill of materials

| Componente | Cantidad | Valor unitario | Link |
| --- | ---: | ---: | --- |
| Raspberry Pi Pico 2 W con pines soldados | 1 | $14.990 | [Raspberry Pi Chile](https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers) |
| Módulo táctil capacitivo MPR121 de 12 entradas | 2 | $2.680 | [MechatronicStore](https://www.mechatronicstore.cl/modulo-controlador-de-sensor-tactil-capacitivo-teclado-i2c-mpr121/) |
| Protoboard MB-102 de 830 puntos | 1 | $2.500 | [Afel](https://afel.cl/products/protoboard-mb-102-830-puntos) |
| Interruptor MTS-102 de 3 pines | 1 | $400 | [Afel](https://afel.cl/products/interruptor-mts-102-3-pines) |
| LED de 5 mm, uno azul, amarillo, naranjo y morado para los carriles, más uno verde de encendido | 5 | $100 | [MechatronicStore](https://www.mechatronicstore.cl/led-alto-brillo-5mm-colores/) |
| 1 pack de 5 Resistencias de 470 Ω para los LED | 1 | $500 | [Triacs](https://triacs.cl/lamborghino/953-resistencia-470-ohm-12w-5-unid-.html) |
| Pack 10 cables caimán a Dupont macho | 1 | $2.500 | [Afel](https://afel.cl/products/kit-10-cables-caiman-a-dupont-macho) |
| 1 pack de 5 cables Dupont macho a macho | 1 | $1.000 | [Afel](https://afel.cl/products/pack-20-cables-de-conexion-macho-macho) |
| Cable USB a Micro USB de datos para alimentar y programar la Pico | 1 | $1.000 | [Afel](https://afel.cl/products/cable-micro-usb-30cm) |
| Parlante de 8 Ω y 1 W | 1 | $3.290 | [MechatronicStore](https://www.mechatronicstore.cl/altavoz-8-ohm-1w/) |
| Amplificador de audio I²S MAX98357A | 1 | $4.236 | [Mercado Libre](https://www.mercadolibre.cl/modulo-amplificador-audio-i2s-3w-clase-d-/p/MLC2069999027?pdp_filters=item_id%3AMLC4487218772) |

---



## Flowchart sampler: 
Te escucho tocar, Santiago...

```mermaid
---
config:
  flowchart:
    curve: step
---
flowchart TD
    Inicio(["Inicio"]) --> Encender["Encender la Raspberry Pi Pico 2 W"]
    Encender --> Preparar["Inicializar los sensores y la salida de audio I²S"]
    Preparar --> Leer["Leer los sensores"]
    Leer --> Detectar{"¿Hay una nuevo contacto?"}

    Detectar -->|No| SinPulsacion["Mantener el estado actual del audio"]
    SinPulsacion --> Leer
    Detectar -->|Sí| Identificar{"¿Qué sensor se activó?"}

    Identificar -->|1 · Metro| Metro["Seleccionar sample de metro"]
    Identificar -->|2 · Micro| Micro["Seleccionar sample de micro"]
    Identificar -->|3 · Colectivo| Colectivo["Seleccionar sample de colectivo"]
    Identificar -->|4 · Bicicleta| Bici["Seleccionar sample de bicicleta"]

    Metro --> EnCurso{"¿Hay un audio sonando?"}
    Micro --> EnCurso
    Colectivo --> EnCurso
    Bici --> EnCurso

    EnCurso -->|Sí| Detener["Detener el audio anterior"]
    EnCurso -->|No| Reproducir["Iniciar el audio seleccionado por el parlante mediante el MAX98357A"]
    Detener --> Reproducir
    Reproducir -->|Seguir leyendo <br> mientras suena| Leer
```

---

## Pseudocódigo

AL ENCENDER EL PANEL
    Encender la luz verde.
    Dejar apagadas las luces de los cuatro carriles.

MIENTRAS EL PANEL ESTÉ ENCENDIDO
    Revisar los 24 botones.

    Cuando alguien presione un botón:
        Encender la luz de su carril.
        Mostrar en la consola el número del botón, el carril y el momento del viaje.
        Ejemplo: Botón 3 | Carril Colectivo | Espera.

    Si alguien mantiene presionado el botón, el aviso aparece una sola vez.
    Si lo suelta y vuelve a presionarlo, aparece un nuevo aviso.

    Cuando se suelte el último botón presionado de un carril,
    apagar la luz de ese carril.

AL APAGAR EL PANEL
    Apagar todas las luces y dejar de registrar pulsaciones.

---

## Esqueleto en Wokwi 

En Wokwi, se creó un componente en simulación del sensor MPR121; cada botón en la simulación emite una señal que se manda a la consola simulando el sonido. Quisimos hacerlo así, ya que aún no tenemos los audios.

https://wokwi.com/projects/480903494879270913

---

## Case

## Fuentes

- <https://docs.sunfounder.com/projects/newton-lab-kit/en/latest/cproject/ar_mpr121.html> CONEXIONES DEL SENSOR
- <https://www.instructables.com/Stylobit-a-Microbit-Powered-Stylophone/> estilofono diy lego(? en caso de idk
- <https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial?view=all> 
