# sesion-13b

## apuntes sesión

En esta sesión nos enfocamos en revisar los avances de cada grupo para entender el contexto curso e intentar desarrollar en conjunto las propuestas.

En base a esto nos percatamos que como grupo tenemos que profundizar más en la conceptualización del proyecto, ya que existían multiples contradicciones en algunos aspectos, es por ello que hoy despues de clases nos enfocamos en desarrollar de mejor manera y definir elementos que aún eran una incógnita.

### Conceptualización

El proyecto busca desarrollar un instrumento no convencional que responde a la sobreproducción que existe actualmente en la industria musical y como esta genera debate entorno a la definición de 3 terminos: el ruido, el sonido y la música. Es por ello que queremos explorar como se puede transitar entre estos 3 conceptos

<br>

### pseudo - código

- Se establece que `sonido` es una grabación sin ninguna modificación, la cual al editar sus parámetros la entendemos como `audio` y una vez que se guarda, se añade a las demás y forma un `conjuntoDeAudios`. Todos los `audios` guardados se reproducen en nuestro `canvas`, es decir, nuestro lienzo que podemos reproducir en cualquier momento pero no editar

- Se inicia la máquina con el interruptor

```cpp

bool interruptorGeneral; // valor asociado a la lectura del switch o botón 
bool funcionamientoMaquina; // depende del interruptorEncendido
// si es true la maquina realiza sus funciones con normalidad
// si es false, la maquina debe tener un led encendido que indica que recibe corriente

if (interruptorGeneral){
funcionamientoMaquina = 1;}

```

- Se consulta si hay `conjuntoDeAudios`

- En caso de haber, se encienden 3 leds que indican la posibilidad de realizar 3 acciones (es decir que cada `led` es un indicador de uso de cada modo), estos corresponden a `reproduccion`, `grabacion` y `borrado`

    - `reproduccion` permite escuchar el `conjuntoDeAudios`

        - Al activar esta opción, se inhabiltan los demás modos meintras dure la reproducción (se apagan sus leds indicadores)

        - Si se vuelve a presionar `reproduccion` mientras suena el `conjuntoDeAudios` se cancela el modo

        - Si se hace `dobleClick` al momento de activar `reproduccion`, se habilita el modo bucle
        
    - `grabacion` permite guardar sonidos de hasta un máximo de 10 segundos

        - Estos sonidos luego se pueden editar variando velocidad, tono...

        - Mientras esto ocurre se bloquea cualquier otro modo

        - Solo se permite salir guardando el `audio`

        - Una vez guardado el `audio` se le asigna una posición "aleatoria" en la que va a sonar en el `conjuntoDeAudios`

    - `borrado` elimina `conjuntoDeAudios`, dejando la memoria vacia esperando nuevos `audios`

        - Una vez ocurre esto se está forzado a solo poder grabar un `sonido`

- En caso de no haber `conjuntoDeAudios` se bloquean todas las funciones a exepción de `grabar`, la cual al iniciarse ocurre con normalidad tal como se describio anteriormente

- Si la máquina es apagada desde el `interruptorGeneral`, el `conjuntoDeAudios` debe quedar almancenado

#### Estructura

Se considera ordenar el código en distintas clases, a continuación se listan algunas a considerar

- Boton (lectura de botones)

- Perilla (lectura de perillas)

- Multiplexor (pensado en la un multiplexor para optimizar la lecutra de perillas)

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

### [Wokwi](https://wokwi.com/projects/480724591872061441)


## encargos

## lectura
