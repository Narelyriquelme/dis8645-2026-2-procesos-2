# grupo-06

## integrantes

- Belén Castillo / [bombobby](https://github.com/bombobby) 


- Martina Fernandez / [pumpkinguurl](https://github.com/pumpkinguurl) 

- Maite Villarroel / [maiteev](https://github.com/maiteev) 


- Nacha Zamudio / [nachazamudio](https://github.com/nachazamudio)



## Entregables

# Una vida en sonidos 

## Lista de materiales (BOM)

| # | Componente | Cant. | Precio unitario | Subtotal | Enlace |
|:-:|------------|:-----:|----------------:|---------:|--------|
| 1 | Raspberry Pi Pico W | 1 | $14.990 | $14.990 | [raspberrypi.cl](https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers) |
| 2 | Módulo reproductor MP3-TF-16P V3.0 (tipo DFPlayer Mini) | 1 | $2.990 | $2.990 | [afel.cl](https://afel.cl/products/modulo-reproductor-mp3-tf-16p-v3-0) |
| 3 | Tarjeta microSD 2–32 GB  | 1 | $3.500 | $3.500 | [mercadolibre.cl](https://www.mercadolibre.cl/tarjeta-de-memoria-maxell-micro-sd-32gb-clase-10-90mbs/p/MLC19813155) |
| 4 | Mini parlante 3 W | 1 | — | — | [afel.cl](https://afel.cl/products/mini-parlante-altavoz-de-3w) |
| 5 | Potenciómetro | 2 | $500 | $1.000 | [afel.cl](https://afel.cl/products/potenciometro-10k-ohm) |
| 6 | Pulsador | 6 | $100 | $600 | [afel.cl](https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptor) |
| 7 | Pantalla OLED 2,42" 128×64 SPI (controlador SSD1309) | 1 | $23.000 | $23.000 | [afel.cl](https://afel.cl/products/pantalla-oled-2-42-128x64-spi-controlador-ssd1309) |

## Diagrama de flujo

## Texto descriptivo del proyecto

“Una vida en sonidos” es una máquina interactiva que recorre, a través del sonido, la vida promedio de una persona chilena, desde el llanto de una guagua hasta el final de la vejez. En un inicio, el usuario escoge un personaje entre cuatro opciones: Giuliano, Ana María, Nicole y Sofía, mientras una pantalla muestra la etapa en la que se encuentra.

El usuario puede avanzar y retroceder por las etapas, y para cada ciclo se presenta un conjunto de botones que activan distintas capas sonoras (el hogar, la calle, la escuela o el trabajo y los hitos del país), de modo que cada persona construye su propia mezcla de recuerdos.

Además, existen situaciones durante la interacción donde el audio se distorsiona, volviendo “borrosos” los recuerdos presentes en la vejez de algunos personajes.

El proyecto busca generar una experiencia de nostalgia y reflexión sobre el paso del tiempo, combinando programación, electrónica y diseño sonoro.

# Descripción total del proyecto

## 1.  Selección de personajes
Los personajes fueron separados según las generaciones descritas en:

Lampert, M. P. (2025). Baby Boomers, Generación X, Millennials y Generación Z: Caracterización generacional en trabajo, familia y tecnología. Biblioteca del Congreso Nacional de Chile, Asesoría Técnica Parlamentaria. [Obtiene Archivo](https://obtienearchivo.bcn.cl/obtienearchivo?id=repositorio%2F10221%2F37179%2F1%2FBCN__caracterizacion__Baby_Boomers__X__Millennials_y___Z__FINAL.pdf)

Giliano (1956) 

Ana María (1972)

Nicole (1987) 

Sofía (2004) 

## 2.   Perilla Línea de tiempo
- Girar la perilla avanza según rangos por edad definidos como grupo según cambios importantes en la interacción con el mundo.
- La pantalla muestra el rango de edad y el nombre de la etapa en la que se encuentra (primera infancia, infancia, adolescencia, juventud, adultez, vejez)
- El usuario puede ir hacia adelante y hacia atrás, como rebobinar un recuerdo. 
- Dependiendo del personaje, la perilla podrá reproducir audio hasta la última etapa o no.

## 3.  Perilla Volumen
- Sirve para subir y bajar el volumen.

 ## 4. Botones que son capas del recuerdo
 - Cada etapa tiene un paisaje sonoro armado con capas que el usuario activa o apaga:
- Casa: tele de fondo, olla a presión, radio, el “ya po, ven a comer”.
- Calle: micro, el pan amasado, el camión de la basura, el gas, ferias, perros.
- Escuela/trabajo: timbre, patio, recreo, oficina, metro.
- País: hitos colectivos, como un partido de la Roja, un terremoto, un 18 de septiembre, la pandemia.

 ## 5.  Botón Encendido
- Encendido y Apagado del sistema.
- Inicio y Pausa del audio.

 ## 6. Botón Selector
- El botón sirve para seleccionar la preferencia de personaje
- Si durante la interacción con uno de los personajes, el usuario desea cambiarlo, puede mantener presionado este botón y reiniciar la interacción.

 ## 7.  Botón Recordar
- Para Giliano y Ana María existe una intervención en el audio, el cual representa la nitidez de los recuerdos por el paso de los años, es decir, en la etapa de la vejez y adultez cercana a la vejez de estos personajes es posible que el audio se distorsione, imitando un recuerdo borroso.   
- Para recuperar la “nitidez” de la etapa se puede presionar el botón de “recordar”. 

 ## 8.  El final (sólo con Giliano)
- Ciclo de la vida: el latido se hace lento, hay un silencio, y vuelve el llanto de guagua (otra vida empieza). Es decir, al finalizar el audio de la última etapa de Giliano, se vuelve al inicio (primer rango de vida), escuchando nuevamente el primer llanto. 

 ## 9.  Rangos etarios
- Los rangos fueron definidos de acuerdo a cuando creíamos que ocurrían los cambios más importantes en la vida de una persona chilena y como era su interacción con el mundo y les demás.

| Etapa | Edad | Qué cambia |
| --- | --- | --- |
| Lactante | 0–2 | Mundo centrado en el cuerpo y la familia |
| Primera infancia | 3–5 | Entrada al jardín; primeros pares |
| Infancia | 6–11 | Colegio; muchos más niños y adultos alrededor |
| Adolescencia | 12–18 | Grupos de pares; círculos más allá de la familia |
| Juventud | 19–29 | Universidad, trabajo, autonomía |
| Adultez | 30–59 | Trabajo estable, familia, hijos |
| Vejez | 60–80 | Jubilación, cuerpo, memoria |

- Según esto, los personajes:
  
Giliano (1956) Tiene todas las etapas

Ana María (1972) 6 etapas, llega a la adultez

Nicole (1987) 6 etapas, llega a la adultez

Sofía (2004) 5 etapas, llega  a la juventud        

# Pseudocódigo

```
//Botón 1: 

//El botón se presiona una sola vez
//Toque corto, cortisimo
//Se inicia o se pausa el audio

//Si se mantiene presionado
//Por >=2sg
//Se prende o se apaga el sistema

//Botón 2 seleccionar, reiniciar

//Se presiona una vez
//Toque corto
//Selecciona personaje
//Inicia reproducción de audio

//Si se mantiene presionado por
//Por >=2 seg
//Se reinicia (vuelve a menú de personajes)

//Botón 3
//En el caso de Giliano
//Si la etapa que se está reproduciendo es vejez
//Y el audio está distorsionado
//Se presiona el botón, toque corto
//Y se recupera la claridad/nitidez del sonido
//En el caso de Ana María
//El audio se distorsiona
//Llegando al final de la adultez


//Botón 4
//Se presiona una vez
//Se activa la capa de CASA
//Si se presiona de nuevo
//Se desactiva la capa 

//Botón 5
//Se presiona una vez
//Se activa la capa de CALLE
//Si se presiona de nuevo
//Se desactiva la capa 

//Botón 6
//Se presiona una vez
//Se activa la capa de TRABAJO
//Si se presiona de nuevo
//Se desactiva la capa 

//Botón 7
//Se presiona una vez
//Se activa la capa de PAÍS
//Si se presiona de nuevo
//Se desactiva la capa 
```

```
//Perilla 1

//Si se encuentra en MENU- PERSONAJES
//La perilla funciona para cambiar la opción de personajes
//Se dividen los valores de la perilla en cuatro opciones
//De izquierda a derecha en este orden
//Giliano
//Ana María
//Nicole
//Sofia

//Si ya se escogió personaje 
//Y se encuentra reproduciendo las etapas del personaje
//La perilla se usa para navegar 
//Como una línea de tiempo
//Se divide en 7 etapas
//Si el personaje tiene menos etapas
//Se deja de reproducir el audio
//En los ciclos que restan


//Perilla 2

//Volumen 
//Es lo mismo que el volumen de la radio
//Perilla todo a la izquierda -> volumen 0 (silencio)
//Perilla todo a la derecha -> volumen  (máximo)
```

```
//Personajes

//Existen 4 personajes
//Giliano
//Ana María 
//Nicole
//Sofía

//Cada uno tendrá su audio 
//Para representar 
//El paso de su vida
//Controlado por una Perilla
```
# Esqueleto en wokwi
https://wokwi.com/projects/480888554413867009 

