<p align="center">
  <img src="./imagenes/applemacintosh.gif" alt="Apple Macintosh" />
  <img src="./imagenes/applemacintosh.gif" alt="Apple Macintosh" />
</p>
<p align="center">
  <img src="./imagenes/applemacintosh.gif" alt="Apple Macintosh" />
  <img src="./imagenes/applemacintosh.gif" alt="Apple Macintosh" />
</p>

<h2 align="center">Remanencia</h2>

## Integrantes

- ***Anais Marschhausen*** @anaisbmg
- ***Antonia Loch***  @antoloch
- ***Hugo Montoya*** @hugomontoya
- ***Carla Núñez*** @ccarlabelenn

## Sobre el proyecto

Este proyecto toma como referente el Apple Macintosh de 1984, recuperando su lenguaje visual basado en ventanas, carpetas, íconos y una interfaz monocromática de píxeles. A partir de esta estética, proponemos un escritorio digital interactivo que permite explorar fotografías y recuerdos personales de una manera intuitiva y cercana.
El proyecto busca reflexionar sobre cómo la tecnología, además de procesar información y facilitar tareas cotidianas, puede convertirse en un medio para preservar algo profundamente humano: los recuerdos, los vínculos y las experiencias compartidas.

## Referente Apple Mac

El Macintosh 128K, lanzado en enero de 1984, destacó por incorporar una interfaz gráfica de usuario basada en ventanas, íconos y menús, junto con el uso de un ratón. Su pantalla monocromática de 1 bit representaba las imágenes mediante píxeles blancos y negros.
La tipografía y gran parte de la iconografía original fueron diseñadas por Susan Kare, cuyo trabajo contribuyó a que la informática resultara más accesible y comprensible para usuarios sin conocimientos técnicos.
Nuestro proyecto retoma este lenguaje visual y lo combina con un anacronismo consciente: ventanas simultáneas que funcionan como espacios de exploración y encuentro con recuerdos personales.

<p align="center">
  <img src="./imagenes/applemacintosh.png" alt="Macintosh 128K" width="300">
  <br>
  <em>Figura 1. Macintosh 128K. Imagen obtenida de Wikipedia:
  https://es.wikipedia.org/wiki/Macintosh_128K</em>
</p>


## Remanencia
La remanencia es aquello que permanece después de que algo ha pasado. El nombre representa la forma en que los recuerdos siguen existiendo tanto en nuestra memoria como en los dispositivos digitales que utilizamos para almacenarlos.
El proyecto busca explorar esa permanencia mediante una interfaz inspirada en los primeros computadores personales, permitiendo navegar recuerdos personales almacenados en un entorno digital.

## Concepto

La propuesta consiste en un escritorio digital compuesto por cuatro carpetas que contienen imágenes personales simplificadas a frame. Mediante botones y perillas físicas, el usuario puede desplazarse por la pantalla, seleccionar carpetas y explorar sus fotografías.
La interacción busca ser sencilla e intuitiva, generando una experiencia íntima que acerque la tecnología a las personas.

- **Escritorio:** inspirado en la interfaz gráfica del Macintosh de 1984.
- **Carpetas:** una cuadrícula de 2 × 2 con cuatro carpetas que contienen imágenes.
- **Ventanas:** elementos visuales que permiten mostrar el contenido de las carpetas.
- **Pantalla:** muestra el escritorio, las fotografías y las interacciones del usuario.
- **Estética:** píxeles, íconos y gráficos monocromáticos.

## Interacción

- **Perilla 1 (eje Y):** movimiento vertical en la pantalla
- **Perilla 2 (eje X):** movimiento horizontal, simulando el movimiento de un mouse
- **Botón 1:** seleccionar, abrir una carpeta y volver al escritorio
- **Botón 2:** controlar acciones relacionadas con la reproducción y visualización de imágenes

parte de nuestra clase:

- **Sin presionar:** estado 0.
- **Presionar durante 1 segundo:** abrir la carpeta seleccionada.
- **Presionar 2 veces:** avanzar a la siguiente fotografía.
- **Presionar 3 veces:** activar un carrusel de fotografías.
- **Mantener presionado durante 5 segundos:** volver al escritorio, independientemente de la posición de las perillas.

Al abrir una carpeta, se muestra inicialmente su primera imagen. El usuario puede avanzar entre fotografías y activar su reproducción secuencial. Una pulsación prolongada permite regresar al escritorio y explorar otra carpeta.

# Relato de uso de la máquina
Al encender el dispositivo, el usuario observa un escritorio digital con cuatro carpetas.
Utilizando la perilla horizontal y la perilla vertical puede desplazar el cursor sobre la pantalla hasta posicionarse sobre la carpeta que desea explorar.
Una vez seleccionada, mantiene presionado el botón principal durante un segundo para abrirla.
Al abrir una carpeta, se muestra una fotografía representativa. El usuario puede avanzar entre imágenes o activar una reproducción automática mediante distintas combinaciones de pulsaciones.
Cuando desea regresar al menú principal, puede mantener presionado el botón durante cinco segundos para volver al escritorio y explorar nuevas carpetas.
La experiencia busca recrear la sensación de recorrer recuerdos digitales mediante una interfaz inspirada en los primeros computadores personales.

## Desarrollo técnico

El proyecto contempla la programación de clases para botones y perillas, responsables de traducir las acciones físicas del usuario en interacciones digitales.
La clase Boton considera cinco variables y cinco funciones para gestionar el estado del botón, detectar las pulsaciones, medir su duración y ejecutar acciones según el contexto de uso.
Las perillas permiten controlar la posición del cursor en los ejes horizontal y vertical, mientras que la pantalla representa visualmente las acciones realizadas.
Se considera el uso de una Raspberry Pi como plataforma de procesamiento y almacenamiento, junto con una pantalla y controles físicos. Las imágenes se organizan en carpetas para facilitar su navegación y visualización.

## Diagrama de flujo

![imagenes](./imagenes/diagrama.png)

## Bom

| Componentes | Cantidad | Precio unitario | Link |
| --- | --- | --- | --- |
| Raspberry Pi Pico 2W | 1 | $14.990 | <https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers> |
| Botón pulsador | 2 | 200 | | <https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptos> |
| Potenciómetro b100k | 2 | $495 | <https://altronics.cl/potenciometro-lineal-100k-b100k> |
| LED | 1 | $100 | <https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes> |
| Resistencia 220 Ω | 2 | $495 | <https://altronics.cl/potenciometro-lineal-100k-b100k> |
| Pantalla | 1 | | |
| Protoboard | 1 | | |

## Pseudocódigo del rol de los componentes

**inicio**

```cpp
disponible pantalla
disponible perilla x
disponible perilla y
disponible botón 1
disponible botón 2

//debe estar visualizando la pantalla con las cuatro carpetas

estado = activo
```


**navegar**

```cpp
posición de perilla x
posición de perilla y

//si estamos ubicados en el escritorio podemos movernos vertical u horizontal
//gracias a las perillas

humanamente decidir sobre qué carpeta me quiero posicionar

seguro que quieres seleccionar esa carpeta? = presiona el botón 1 durante 1 segundo

            Seleccionar carpeta
            Abrir carpeta
            Mostrar primera fotografía de la carpeta
```

**carpeta**

```cpp
si la carpeta está abierta podemos continuar: true

nos mostrará directamente un frame representativo de la carpeta

    SI botón 2 se presiona 2 veces
        Avanzará a la siguiente fotografía
 //para poder
        Mostrar nueva fotografía

    SI botón 2 se presiona 3 veces
        Activar carrusel de fotografías
//para poder
        Reproducir fotografías automáticamente

    SI botón 2 se mantiene presionado durante 5 segundos
        Detener carrusel
 //para poder
        Volver al escritorio digital
//estará listo para poder volver a navegar en nuestros recuerdos de escritorio
```


**loop**

```cpp
si está encendido

podemos volver a navegar
ver diferentes carpetas
ver frames
ver carrusel

Fin y haz loop como quieras:)
```




## Carcasa
La propuesta considera una carcasa inspirada en el Macintosh 1984.
Su diseño busca representar visualmente el computador histórico mientras integra pantalla y controles físicos compuestos por dos perillas y dos botones.
La forma general toma como referencia la estética compacta del Macintosh, reinterpretándola como un objeto destinado a la exploración de recuerdos digitales.

![fotopropuesta](./imagenes/fotopropuesta.png)
![fotopropuesta2](./imagenes/fotopropuesta2.png)

## Referentes

Acá logramos observar el Macintosh por dentro, descubriendo los componentes y la arquitectura que hicieron posible su funcionamiento.

<p align="center">
  <img src="imagenes/refe.png" alt="refe" width="500">
  <br>
  <em>Interior del Macintosh original.</em>
</p>


> **Fuente:** [iFixit – Evertiq](https://evertiq.com/news/33666) · 24 de enero de 2014.


Susan Kare fue la diseñadora gráfica responsable de crear gran parte de los elementos visuales de la interfaz del Apple Macintosh. Su trabajo incluyó íconos, tipografías y símbolos que ayudaron a construir un lenguaje gráfico simple, reconocible y cercano para los usuarios.

<p align="center">
  <img src="imagenes/refesusankare.png" alt="refesusankare" width="500">
  <br>
  <em>Íconos creados por Susan Kare para el Macintosh.</em>
</p>

> **Fuente:** [99% Invisible – Designed with Kare](https://99percentinvisible.org/article/designed-with-kare-influential-macintosh-graphics-of-early-apple-computers/)


# Problemas y decisiones durante el proceso 
El viernes 30 de octubre nos quedamos trabajando hasta tarde en la universidad para intentar finalizar el proyecto.
Durante gran parte de la tarde, Sebastián Sáez nos ayudó revisando el código y orientándonos sobre cómo implementarlo utilizando la Raspberry Pi Pico 2W.
Hasta ese momento ya contábamos con una versión funcional del código y nuestro objetivo era transferirlo a la placa física para comenzar las pruebas finales.
Alrededor de las 18:00 horas, Sebastián detectó un problema importante. El código había sido desarrollado considerando una configuración distinta a la del hardware que teníamos físicamente. Las placas utilizadas durante el proceso no correspondían exactamente a la misma configuración, generando incompatibilidades.
Al descubrir esta situación entendimos que gran parte del trabajo realizado no podía trasladarse directamente a la Raspberry Pi Pico 2W. Además, adaptar el proyecto y traspasar correctamente el código al entorno de Visual Studio Code resultó mucho más complejo de lo esperado.
En ese momento nos encontrábamos cansados y preocupados, ya que habíamos dedicado varias horas de trabajo antes de detectar el problema.
Después de analizar distintas alternativas, decidimos presentar el funcionamiento mediante una simulación en Wokwi, lo que nos permitía demostrar la lógica de navegación, las interacciones y el comportamiento esperado del sistema.
Finalmente, también se tomó la decisión de construir una carcasa representativa para la entrega final. Aunque no incluiría los componentes electrónicos funcionando en su interior, permitiría mostrar la propuesta formal, la experiencia de uso y la referencia al Macintosh original.

# Prompts utilizados
*(Agregar aquí los prompts utilizados para los códigos.)*

# Esquemáticos
*(Agregar aquí los esquemáticos kicad.)*

## Bibliografía

- Wikipedia. Macintosh 128K. Wikipedia, la enciclopedia libre.<https://es.wikipedia.org/wiki/Macintosh_128K>

- Staff Editor. (2014, 24 de enero). *Blast from the past: Mac 128K Teardown*. Evertiq. https://evertiq.com/news/33666

- Kohlstedt, K. (2018, 6 de julio). *Designed with Kare: Influential graphics of Apple’s early Macintosh computers*. 99% Invisible. https://99percentinvisible.org/article/designed-with-kare-influential-macintosh-graphics-of-early-apple-computers/


