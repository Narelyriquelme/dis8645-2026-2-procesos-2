# sesion-14a → 17/11/26

## apuntes sesión

Tener:

- pseudocódigo

- Diagrama de flujo
  
- esqueleto en wokwi

---

Wokwi → Color pin	y qué hace

Rojo → GP2	Mover la nave a la izquierda

Azul	→ GP3	→ Mover la nave a la derecha

Amarillo	→ GP4	→ Disparar

Verde	→ GP5	→ Iniciar, pausar y reanudar la partida (y reiniciar después del game over)

---

### Corrección en clases (profes)

Está más acotado, bien
necesitan ser capaces de utilizar dos parlantes, y repartirlos entre izquierda y derecha. El PAM8403 ya es estereo Así pueden jugar con los porcentajes de cuanto se va un sonido para cada lado.

eso en los mixers se llama control de panorámica
en el primer párrafo ocuparía la palabra que descubrimos: "audiojuego"
el sonido podría ser de tipo "radar", con el sonido de lo que se van acercando más insistentes.

Considerar como se van a cargar los audios, existen modulos distintos donde uno de los mas utilizados es el "dfplayer mini", en este mismo punto como es que irian a lograr el audio binaural con 1 solo reproductor en su BOM? Creo que no es posible con solo 1 parlante.

Creo que les falta un claro referente de la jugabilidad, me refiero que existen un monton de scrollers infinitos, pero este tiene un poco de similitud a temple run o subway surfers segun lo que comprendo en lo que han escrito. Pueden destacar algun aspecto en especifico.


### Que vamos a incluir:

1. led (para avisar la proximidad de los obstaculos y enemigos, no por el lado que viene la amenaza).

2. Pantalla: cuantas vidas me quedan, animación de inicio, animación de leven up (en que nivel voy), animación game over.

3. Sonidos al perder y al subir de nivel, con el fin de molestar al usuario y no pueda avanzar.

el punto de asistencia sera reemplaxado por un ensayo en las bitacoras de mi timepo y yo, tengo que hablar del tiempo y porque he faltado a las clases (una pagina de google docs).

### Actualización BOM

| N.º | Componente | Especificaciones | Cantidad | Precio | Enlace |
|:---:|---|---|:---:|---:|---|
| 1 | Raspberry Pi Pico RP2040 | Microcontrolador | 1 | $11.290 | [Comprar](https://raspberrypi.cl/products/raspberry-pi-pico-w-con-conexion-wifi) |
| 2 | Parlante | 8 Ω / 0,5 W | 1 | $2.890 | [Comprar](https://mcielectronics.cl/shop/product/mini-parlante-altavoz-8-ohms-0-5w/) |
| 3 | Amplificador PAM8403 | Amplificador de audio 3 W × 2 | 1 | $2.500 | [Comprar](https://afel.cl/products/amplificador-pam8403-3w-x-2-con-potenciometro) |
| 4 | Botones pulsadores | Táctiles 6 × 6 × 5 mm | 4 | $500 | [Comprar](https://afel.cl/products/kit-boton-tactil-6x6x5-interruptor-5-unidades) |
| 5 | Resistencias | 10 kΩ | 4 | $20 | [Comprar](https://afel.cl/products/kit-500-resistencias-1-2w-50-valores) |
| 6 | Protoboard | 400 puntos | 2 | $1.500 | [Comprar](https://afel.cl/products/mini-protoboard-400-puntos) |
| 7 | Cables jumper | Cables de conexión | Variable | $2.000 | [Comprar](https://afel.cl/products/pack-60-cables-de-conexion) |
| 8 | Alimentación USB | Fuente de alimentación de 5 V | 1 | — | Por definir |
| 9 | Lector de tarjeta SD | Módulo lector de tarjeta SD | 1 | $1.000 | [Comprar](https://afel.cl/products/modulo-lector-tarjetas-sd) |
| 10 | Módulo de carga TP4056 | Cargador USB-C para batería LiPo de 3,7 V | 1 | $1.990 | [Comprar](https://www.mechatronicstore.cl/controlador-tp4056-para-bat-litio-5v-1a-mini-usb/?attribute_conector-usb=Tipo+C) |
| 11 | Sensor MPU6050 | Acelerómetro y giroscopio GY-521 | 1 | $4.000 | [Comprar](https://afel.cl/products/sensor-giroscopio-acelerometro-gy-521-mpu6050/) |
| 12 | Batería LiPo | 3,7 V / 2000 mAh – Modelo 103450 | 1 | $7.990 | [Comprar](https://maxelectronica.cl/fuentes-de-alimentacion/910-bateria-li-po-37v-74wh-2000mah-modelo-103450-con-conector-jst-ph20.html) |
| 13 | Potenciómetro | 10 kΩ | 1 | $500 | [Comprar](https://afel.cl/products/potenciometro-10k-ohm) |
| 14 | Pantalla | LCD 1602 I2C | 1 | $4633 | [Comprar]([https://afel.cl/products/potenciometro-10k-ohm](https://www.mercadolibre.cl/modulo-lcd-20x4-con-interfaz-2004-para-display/p/MLC2035293542)) |


## encargos

Escribir una página en el formato similar a este texto. Es decir, Times New Roman 12, con interlineado 1,15. 

El objetivo del texto es narrar una visión personal sobre la idea del tiempo. Narrar sobre su relación con el tiempo, sobre la mañana y la hora de clases, sobre el paso del tiempo, el uso del tiempo, la política y el tiempo. 

El texto debe estar escrito en Google Docs de principio a fin. Evitar escribir en otra parte y pegarlo acá. Recordar dar acceso de comentador con mail UDP.

Bibliografía  →  Pueden usar el sistema de citas que prefieran: Chicago, MLA, APA, IEEE, etc.


## lectura

Libro: A New Program for Graphic Design

Autor: David Reinfurt

El libro está dividido en 3 grandes capítulos.

I. T--Y-P-O-G-R-A-P-H-Y

II. G-E-S-T-A-L-T

III. I-N-T-E-R-F-A-C-E

El autor plantea las bases de lo que significa enseñar diseño gráfico hoy. Introduce la idea de que el diseño no se trata de "estilo" o decoración, sino de sistemas, reglas y tecnología aplicadas a la comunicación.


### Bloque 9 · Typography (pp. 91-97)


1. Tema central

Reinfurt cuenta cómo Metafont rehabilitado se volvió una fuente “viva” que se reutiliza y cambia en cada proyecto (exposiciones, catálogos, logo, película). La sección Typography cierra con su lista de lecturas.


2. Análisis directo
   
- Meta-the-difference-between-the-two-Font nace de una invitación del Queens Museum. Luego se reutiliza en Gallery 400, Dot Dot Dot, Bulletins of the Serving Library, una feria en Turín y el MoMA. Cada encargo la hace avanzar un poco.

- El texto habla de la fuente: ensayos como “A Note on the Type” están compuestos con la misma tipografía que describen. Junto a “A Note on the Time” (cómo los computadores acuerdan la hora en red) vinculan tipografía, tiempo y sistemas.

- En vez de vender la fuente, proponen a Kadist usarla como logo por 10 años, mientras cambia muy despacio. El logo deja de ser una imagen fija y pasa a ser un sistema que evoluciona.

- Peso, inclinación y “superness” funcionan como tres ejes de un cubo, y una bolita hace un recorrido aleatorio entre ellos. De ahí sale la versión 4-D, que además mueve el tipo de pluma.

- La película “Letter & Spirit” (18 min) se graba en 35 mm con una máquina de Jürg Lehni, usando una tecnología antigua para animar tipografía digital.

- La conclusión es que la fuente es casi idéntica a Metafont, pero su historia enredada queda incrustada en ella. Para Reinfurt, esas historias son lo que da sentido a lo que hacemos.


3. Glosario

| Término (Inglés) | Traducción (Español) | Explicación |
|---|---|---|
| Parameter | Parámetro | Valor ajustable que cambia el comportamiento de la fuente. |
| Slant | Inclinación | Ángulo de las letras hacia adelante o hacia atrás. |
| Superness | Superelipticidad | Medida de la redondez de la "O", que afecta al resto de letras. |
| Random walk | Recorrido aleatorio | Movimiento por pasos al azar dentro de un espacio de posibilidades. |
| Nib | Plumilla | Punta de la pluma que determina el trazo de la letra. |
| House font | Fuente de la casa | Tipografía propia que un estudio usa en sus publicaciones. |
| Exhibition catalogue | Catálogo de exposición | Publicación que acompaña y documenta una muestra. |
| Anachronistic | Anacrónico | Que pertenece a otra época y ya quedó fuera de contexto. |


4. Citas

**Cita 1 (p. 91)**

INGLÉS: “It took a lot of work to get to that point, many wrong turns, and no shortage of digressions. I suppose this is also the point.”

ESPAÑOL: “Costó mucho trabajo llegar a ese punto, con muchos giros equivocados y sin falta de digresiones. Supongo que ese también es el punto.”

Análisis: El rodeo y el error se presentan como parte del método, no como fallas. El diseño especulativo avanza por desvíos.


**Cita 2 (p. 93)**

INGLÉS: “We would use the invitation as an excuse to develop an aspect of this project we’d been interested in—to make the typeface explicitly change over time.”

ESPAÑOL: “Usaríamos la invitación como excusa para desarrollar un aspecto de este proyecto que nos interesaba: hacer que la tipografía cambiara explícitamente con el tiempo.”

Análisis: Los encargos funcionan como pretexto para investigar. El tiempo se vuelve un parámetro del diseño.


**Cita 3 (p. 96)**

INGLÉS: “when so much is so readily available, these stories are how we make coherent sense of what we do.”

ESPAÑOL: “cuando hay tanto tan fácilmente disponible, estas historias son la manera en que damos un sentido coherente a lo que hacemos.”

Análisis: Con tanta información a mano, contar el proceso es lo que da sentido al trabajo. Es la idea de cierre de la sección.
