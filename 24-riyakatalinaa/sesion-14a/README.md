# sesion-14a

## apuntes sesión

martes 2026-11-17

- mandar link al discord del avance que llevamos del proyecto-03
- seguir avanzando en proyecto-03
- [Wokwi - proyecto-03](https://wokwi.com/projects/480722608786043905) pasado
- [Wokwi - proyecto-03](https://wokwi.com/projects/481081755198213121) **nuevo**
- realizar diagrama de flujo
- el punto de asistencia sera reemplazado por un ensayo en las bitacoras de mi timepo y yo, tengo que hablar del tiempo y porque he faltado a las clases (una pagina de google docs)


### corrección en clases (profes)

Está más acotado, bien
necesitan ser capaces de utilizar dos parlantes, y repartirlos entre izquierda y derecha. El PAM8403 ya es estereo Así pueden jugar con los porcentajes de cuanto se va un sonido para cada lado.

eso en los mixers se llama control de panorámica
en el primer párrafo ocuparía la palabra que descubrimos: "audiojuego"
el sonido podría ser de tipo "radar", con el sonido de lo que se van acercando más insistentes.

Considerar como se van a cargar los audios, existen modulos distintos donde uno de los mas utilizados es el "dfplayer mini", en este mismo punto como es que irian a lograr el audio binaural con 1 solo reproductor en su BOM? Creo que no es posible con solo 1 parlante.

Creo que les falta un claro referente de la jugabilidad, me refiero que existen un monton de scrollers infinitos, pero este tiene un poco de similitud a temple run o subway surfers segun lo que comprendo en lo que han escrito. Pueden destacar algun aspecto en especifico.


### cosas que queremos incluir (no definitivo)
- led (para avisar la proximidad de los obstaculos y enemigos, no por el lado que viene la amenaza)
- pantallits: cuantas vidas me quedan, animación de inicio, animación de leven up (en que nivel voy), animación game over
- sonidos al perder y al subir de nivel, con el fin de molestar al usuario y no pueda avanzar


###  BOM actualizado (hasta el martes 17)

| N.º | Componente | Especificaciones | Cantidad | Precio | Enlace |
|:---:|---|---|:---:|---:|---|
| 1 | Raspberry Pi Pico RP2040 | Microcontrolador | 1 | $11.290 | [Comprar](https://raspberrypi.cl/products/raspberry-pi-pico-w-con-conexion-wifi) |
| 2 | Parlante | 8 Ω / 0,5 W | 1 | $2.890 | [Comprar](https://mcielectronics.cl/shop/product/mini-parlante-altavoz-8-ohms-0-5w/) |
| 3 | Amplificador PAM8403 | Amplificador de audio 3 W × 2 | 1 | $2.500 | [Comprar](https://afel.cl/products/amplificador-pam8403-3w-x-2-con-potenciometro) |
| 4 | Botones pulsadores | Táctiles 6 × 6 × 5 mm | 4 | $500 | [Comprar](https://afel.cl/products/kit-boton-tactil-6x6x5-interruptor-5-unidades) |
| 5 | Resistencias | 10 kΩ | 4 | $20 | [Comprar](https://afel.cl/products/kit-500-resistencias-1-2w-50-valores) |
| 6 | Protoboard | 400 puntos | 2 | $1.500 | [Comprar](https://afel.cl/products/mini-protoboard-400-puntos) |
| 7 | Cables jumper | Cables de conexión | Variable | $2.000 | [Comprar](https://afel.cl/products/pack-60-cables-de-conexion) |
| 8 | Alimentación USB | Fuente de alimentación de 5 V | 1 | — | — |
| 9 | Lector de tarjeta SD | Módulo lector de tarjeta SD | 1 | $1.000 | [Comprar](https://afel.cl/products/modulo-lector-tarjetas-sd) |
| 10 | Módulo de carga TP4056 | Cargador USB-C para batería LiPo de 3,7 V | 1 | $1.990 | [Comprar](https://www.mechatronicstore.cl/controlador-tp4056-para-bat-litio-5v-1a-mini-usb/?attribute_conector-usb=Tipo+C) |
| 11 | Sensor MPU6050 | Acelerómetro y giroscopio GY-521 | 1 | $4.000 | [Comprar](https://afel.cl/products/sensor-giroscopio-acelerometro-gy-521-mpu6050/) |
| 12 | Batería LiPo | 3,7 V / 2000 mAh – Modelo 103450 | 1 | $7.990 | [Comprar](https://maxelectronica.cl/fuentes-de-alimentacion/910-bateria-li-po-37v-74wh-2000mah-modelo-103450-con-conector-jst-ph20.html) |
| 13 | Potenciómetro | 10 kΩ | 1 | $500 | [Comprar](https://afel.cl/products/potenciometro-10k-ohm) |
| 14 | Pantalla | LCD 1602 I2C | 1 | $7.790 | [Comprar](https://www.mercadolibre.cl/modulo-lcd-20x4-con-interfaz-2004-para-display/p/MLC2035293542) |


## encargos

- subir 10 referentes
- mejorar redacción de README del proyecto-3

## lectura

nos dejaron elegir un libro para leer durante el semestre en el cual debemos dejar 2 citas por clase y leer mínimo 100 paginas durante el semestre

libro escogido **La Música electroacústica en Chile** de Federico Schumacher

en esta ocasión leí dos capítulos del libroiván pequeño y jorge arriagada se instalaron en francia; arriagada terminó haciendo música para películas (destacando las de raúl ruíz).

### capítulo 1 leído del libro 
- **...Que veinte años no es nada...**
    - de 75 obras chilenas hechas entre 1956 y 1977, solo 21 se compusieron acá
    - faltaban equipos y laboratorios, así que casi todos tuvieron que irse afuera a crear
    - el laboratorio de la U de Chile estuvo súper cerrado y casi no hubo conciertos abiertos
    - igual salieron compositores reconocidos mundialmente, un nivel que no volvió en 30 años
  

### capítulo 2 leído del libro 
- **Haciendo música con un computador**
   - en 1978 Asuar construyó el comdasuar, el primer computador dedicado solo a hacer música en el mundo
   - funcionaba con un chip intel 8080, cintas de cassette y costaba menos de mil dólares
   - tocaba partituras solo, generaba sonidos y proponía ideas musicales con algoritmos
   - de ahí salió el disco así habló el computador (1979) y obras como en el jardín
   - en los 80 Asuar se aisló en su estudio y desapareció de la escena, empezando los "años negros" de la electroacústica en Chile

### citas del libro

**cita 1**: 

**_"Acerquémonos entonces al bicho en cuestión..."_**

página 93

**opinión:** bicho = computador

**cita 2**: 

**_"Luego se hará el misterio respecto a su paradero"_**

página 97

**opinión:** se chateó y desapareció lol
