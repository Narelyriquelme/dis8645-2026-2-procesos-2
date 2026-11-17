# sesion-13b

## apuntes sesión

# Proyecto 3 — definición de la idea

Hoy revisamos las **dos ideas que teníamos para el Proyecto 3** y empezamos a aterrizar cuál tenía más sentido seguir desarrollando.

Primero conversamos sobre **Fan Connect**, pero quedaron hartas preguntas dando vueltas.

Por ejemplo:

- ¿De dónde sacaríamos la música?
- ¿Qué biblioteca musical podríamos usar?
- ¿Para quién sería realmente el dispositivo?
- ¿Cómo sabríamos si a la otra persona le va a gustar lo que le mandamos?
- ¿Cómo mostraríamos todo este intercambio en Diseño Abierto?

También revisamos la posibilidad de usar bibliotecas gratuitas de música, pero se hizo bastante obvio que no eran muy bueeenas JAJJA.

Así que después de darle hartas vueltas decidimos:

# NOS QUEDAMOS CON Dispositivo sonoro para niños!!

La idea sigue siendo hacer un **dispositivo sonoro para niños**, que pueda acompañarlos a través de cuentos, música y mensajes grabados por personas cercanas.

Ahora empezamos a pensar un poco más en **cuándo aparecería cada contenido**, porque no necesariamente tiene sentido escuchar lo mismo durante todo el día.

Por ejemplo:

- En la tarde podría aparecer una canción o una fábula.
- Antes de dormir podría aparecer un cuento más tranquilo.
- En otros momentos podrían existir distintos contenidos dependiendo de lo que necesite el niño.

Todavía tenemos que definir qué tendría sentido escuchar en cada momento y cómo vamos a organizar esa biblioteca.

También pensamos si dividir los contenidos por edades, pero por ahora decidimos trabajar con un usuario mucho más específico.

Y MUY IMPORTANTE:

**hay que cambiarle el nombre al proyecto.** ya que es una palabra que arrastra una connotación negativa y preocupante.

**dispositivo sonoro para niños** será su nombre temporal.

# Idea general

El proyecto sería un **dispositivo sonoro portátil pensado para acompañar a infantes de 3 a 4 años** que puedan sentirse solos, asustados o simplemente necesitar un poquito de contención en distintos momentos del día.

La idea es que puedan acceder de forma relativamente autónoma a:

- Cuentos.
- Música.
- Mensajes grabados por una persona cercana.

Todo esto mediante **botones físicos** y una **pantalla de apoyo**.

La pantalla no sería lo principal de la interacción, porque queremos que la experiencia sea principalmente física y sonora.

El nombre del dispositivo y del proyecto todavía está por definir.

# Usuario y biblioteca

Nuestro público objetivo serán **infancias de 3 a 4 años que necesiten acompañamiento**.

Decidimos no separar la biblioteca en distintos rangos de edad porque terminaríamos diseñando varias versiones del mismo proyecto y queremos concentrarnos en un usuario más específico.

Entonces:

```text
usuario → infantes de 3 a 4 años
```

## Cuentos y música

Los cuentos y la música serán audios que tengan **licencias que permitan utilizarlos**.

La biblioteca inicial quedará cerrada con los contenidos que nosotros seleccionemos.

O sea, por ahora no estamos pensando en una biblioteca que vaya creciendo infinitamente después de entregar el proyecto.

Sería más bien:

```text
seleccionamos contenidos
        ↓
los guardamos
        ↓
quedan disponibles en el dispositivo
```

## Grabaciones

Las grabaciones funcionan distinto.

Este contenido vendrá directamente de una **persona cercana o cuidador**.

La idea es que pueda grabar **un mensaje nuevo cada día** para el infante.

Por ejemplo podría ser algo tipo:

> "Que tengas un lindo día, te quiero mucho."

o cualquier mensaje que el cuidador quiera dejar.

Queremos guardar **un solo mensaje familiar a la vez**.

Entonces el mensaje anterior:

- Se reemplaza cuando se graba uno nuevo.
- O se elimina después de un día.

Todavía tenemos que definir exactamente cuál de esas dos opciones funcionará mejor.

# Biblioteca de día y noche

Una de las decisiones que tomamos fue dividir la biblioteca según el momento del día.

Por ahora tenemos:

```text
DÍA
+
NOCHE
```

Durante el día podrían aparecer contenidos más activos, por ejemplo:

- Música.
- Fábulas.
- Cuentos.
- Contenidos para acompañar distintos momentos.

Mientras que durante la noche podríamos priorizar:

- Cuentos más tranquilos.
- Música más suave.
- Contenidos relacionados con dormir.

La idea es que el dispositivo no entregue exactamente la misma experiencia a las 3 de la tarde que justo antes de acostarse.

## ¿Cómo sabe si es de día o de noche?

ESTO TODAVÍA HAY QUE RESOLVERLO.

Tenemos varias posibilidades:

- Usar la hora de Santiago.
- Utilizar algún temporizador.
- Que el cuidador configure el momento.
- Encontrar otra forma de definir el cambio entre día y noche.

Entonces:

**la división día/noche ya está definida.**

Lo que falta es decidir **cómo técnicamente el dispositivo va a saber en qué momento está**.

# Funcionamiento para el niño

El dispositivo principal será utilizado por el niño.

Tendrá **tres botones físicos duros**:

```text
CUENTOS

MÚSICA

GRABACIONES
```

Cada botón corresponde a una categoría.

## Primera presión

Cuando el niño presiona un botón por primera vez se activa esa categoría.

Por ejemplo:

```text
presiona CUENTOS
      ↓
suena un cuento
```

## Segunda presión

Si vuelve a presionar el mismo botón, cambia al siguiente contenido de esa categoría.

Por ejemplo:

```text
presiona CUENTOS
      ↓
cuento 1

presiona nuevamente
      ↓
cuento 2

presiona nuevamente
      ↓
cuento 3
```

Y así sucesivamente.

# Evitar que siempre reproduzca lo mismo

Tenemos que evitar que cada vez que el niño apriete el botón vuelva a escuchar siempre el mismo audio.

Por eso tenemos que definir cómo el dispositivo va a **recordar cuál fue el último contenido reproducido**.

También tenemos que pensar cómo interpretar las pulsaciones.

Porque claramente un niño podría hacer:

```text
CLICK CLICK CLICK CLICK CLICK
```
en medio segundo jejeje.

Y no queremos que eso cambie diez canciones de una.

Entonces podríamos hacer que:

- Una presión larga cuente como una sola pulsación.
- Varias presiones demasiado rápidas se interpreten de alguna manera controlada.
- Exista un pequeño tiempo entre cambios.

Esto todavía hay que probarlo.

# Pantalla

La pantalla va a acompañar la interacción.

Todavía no tenemos completamente definido **qué va a mostrar**, pero podría mostrar cosas como:

- La categoría activa.
- El personaje relacionado con el contenido.
- Qué audio está sonando.
- El estado del dispositivo.

Por ejemplo:

```text
CUENTOS
🐻
"Cuento 02"
```

Pero esto sigue abierto y lo tenemos que definir mejor cuando resolvamos qué pantalla vamos a utilizar.

# Grabación y control parental

La parte de grabación está pensada para el **cuidador**, no para que el niño la utilice normalmente.

Queremos evitar que el niño pueda:

- Grabar sin querer.
- Borrar mensajes.
- Cambiar configuraciones importantes.

Durante el proceso pensamos **tres formas distintas** de resolverlo.

# Primera alternativa — perilla encoder

La primera opción era utilizar una **perilla encoder**.

La perilla tendría dos valores principales:

```text
NO ←────────→ SÍ
```

Si el dispositivo no está haciendo nada, después de unos 15 segundos volvería automáticamente a:

```text
NO
```

Para activar la grabación habría que mover la perilla hasta `SÍ` y mantenerla presionada durante cinco segundos.

En la pantalla aparecería algo como:

```text
mantener apretado 1

mantener apretado 2

mantener apretado 3

mantener apretado 4

mantener apretado 5

GRABANDO
```

Al soltar la perilla terminaría la grabación.

Después aparecería durante unos segundos:

```text
MENSAJE GUARDADO
```

También pensamos que quizás volviendo a presionar se podría borrar el mensaje anterior.

### Problema

Esta opción nos permitía mantener una interacción completamente física, lo cual nos gustaba.

PERO se estaba poniendo demasiado enredada jajaja.

Había que:

```text
mover
+
presionar
+
mantener
+
esperar
+
soltar
```

para hacer algo que debería ser relativamente simple para el cuidador.

Así que seguimos buscando.

# Segunda alternativa — pantalla touch

La segunda idea era utilizar una **pantalla touch con lápiz** como control parental.

Dentro de la interfaz habría un pequeño ícono en una esquina.

Para entrar al modo cuidador habría que mantener ese ícono presionado durante cinco segundos.

Después aparecería una pantalla para ingresar una clave.

Si todavía no existiera una clave:

```text
crear clave
```

Si ya existe:

```text
ingresar clave
```

Y también se podría cambiar.

Después de ingresar correctamente aparecería una pantalla especial para grabar el mensaje.

La idea era que **solamente ese botón o sector de la pantalla fuera touch**, para que el niño no pudiera entrar fácilmente por accidente.

Pero acá aparecieron varias preguntas:

- ¿Podemos hacer que solamente una parte de la pantalla responda al touch?
- ¿Funcionará correctamente con lápiz?
- ¿No estaremos agregando demasiada complejidad?
- ¿Vale la pena tener una pantalla touch solamente para esta función?

Así que tampoco nos convenció completamente.

# Tercera alternativa — módulo desmontable

Y finalmente llegamos a la alternativa que MÁS NOS GUSTÓ.

## Una pieza separable :)

Una parte del producto se podrá **separar físicamente del dispositivo principal**.

Esta pieza tendrá:

- El micrófono.
- El botón de grabación.
- La función relacionada con grabar.

Se conectará al dispositivo utilizando **conectores JST**.

Entonces tendríamos algo como:

```text
DISPOSITIVO DEL NIÑO
        +
MÓDULO DE GRABACIÓN
```

Cuando el cuidador conecte el módulo:

```text
attach
   ↓
aparece modo de grabación
```

## ¿Cómo se graba?

Queremos que sea bastante simple.

El cuidador:

```text
presiona
   ↓
empieza a grabar
   ↓
mantiene presionado
   ↓
aparece en la pantalla un conteo
   ↓
suelta
   ↓
termina la grabación
```

Después aparece:

```text
MENSAJE GUARDADO
```

Si ocurre algún problema, aparecería un mensaje de error.

## LED de grabación

El módulo también tendrá un **LED** que nos indique claramente cuándo se está grabando.

```text
LED ENCENDIDO → grabando

LED APAGADO → no está grabando
```

Así no dependemos solamente de la pantalla para entender qué está ocurriendo.


# ¿Por qué elegimos la pieza desmontable?

Esta solución nos gustó porque funciona como una **restricción física**.

El dispositivo principal queda pensado para el niño y contiene:

- Botones de cuentos.
- Botón de música.
- Botón de grabaciones.
- Pantalla.
- Parlante.

Mientras que las funciones más delicadas quedan en una pieza aparte.

Así el niño no puede llegar fácilmente y:

```text
borrar el mensaje
grabar cualquier cosa
cambiar configuraciones
```

por accidente.

Para entrar a esa función necesitas literalmente **tener otra pieza física y conectarla**.

Y siento que eso tiene mucho más sentido que esconder todo detrás de una contraseña o una secuencia rara de botones.

# Componentes y almacenamiento

Para poder grabar necesitamos encontrar un **micrófono barato pero funcional**.

No queremos agregar una complejidad enorme si realmente no es necesaria.

Tenemos que buscar un modelo que sea compatible con la Raspi y revisar cómo entrega la información.

Dependiendo del micrófono podría funcionar mediante:

- USB.
- Entrada analógica mediante ADC.

Esto todavía tenemos que investigarlo y probarlo.

# Tarjeta SD

También vamos a agregar:

- Lector SD.
- Tarjeta SD.

Ahí podríamos almacenar:

```text
CUENTOS
+
MÚSICA
+
MENSAJE DEL CUIDADOR
```

La biblioteca inicial estaría guardada en la tarjeta y también podríamos guardar ahí la grabación diaria.

# Parlante y amplificador

Seguimos manteniendo como referencia:

```text
PAM8403
+
parlante
```

Pero antes de cerrar completamente esta parte tenemos que probar la **cadena de audio completa con la Raspi**.

O sea:

```text
archivo de audio
      ↓
Raspi
      ↓
amplificador
      ↓
parlante
      ↓
SONIDO!!!
```

Porque mejor comprobar que todo funcione antes de diseñar una carcasa perfecta y después descubrir que algo no sirve jijij.

# Carcasa

La carcasa tiene que considerar tanto:

- El dispositivo principal.
- El módulo desmontable de grabación.

Y tiene que dejar espacio para:

- Pantalla.
- Parlante.
- Lector SD.
- Tarjeta SD.
- Batería.
- Conectores JST.
- Micrófono.
- Ventilación.
- Botones.

Los botones serán **duros y fáciles de distinguir**.

No queremos botones de goma porque:

**los niños se las comen.**

Así que descartadísimos.

También tenemos que tener mucho ojo con el módulo desmontable.

Tiene que poder separarse de forma sencilla para el cuidador, pero sin dejar:

- Cables expuestos.
- Conectores peligrosos.
- Piezas pequeñas fáciles de sacar.

# Cómo se empieza a dividir el producto

Por ahora siento que el proyecto empieza a ordenarse así:

```text
                    DISPOSITIVO
                         │
            ┌────────────┴────────────┐
            │                         │
      PARTE DEL NIÑO           PARTE DEL CUIDADOR
            │                         │
        cuentos                  micrófono
        música                   grabación
      grabaciones                    LED
        pantalla                módulo desmontable
        parlante
```

Y eso ayuda harto a entender **qué funciones le corresponden a cada usuario**.

El niño puede escuchar y elegir contenidos.

El cuidador puede crear el mensaje.

Y no tenemos que meter absolutamente todas las funciones en la misma interfaz.

# Pendientes reales

Ahora sí, nuestras cosas pendientes QUE NECESITAMOS TERMINAR pero vamos bien ejejej:

- [ ] Definir el nombre final del proyecto y del dispositivo.
- [ ] Definir el modelo de pantalla.
- [ ] Definir exactamente qué información mostrará la pantalla.
- [ ] Buscar cuentos con licencias compatibles.
- [ ] Buscar música con licencias compatibles.
- [ ] Definir qué contenidos corresponden al día.
- [ ] Definir qué contenidos corresponden a la noche.
- [ ] Resolver cómo la máquina reconocerá si es de día o de noche.
- [ ] Buscar un modelo de micrófono.
- [ ] Probar el micrófono con la Raspi.
- [ ] Confirmar cómo guardaremos el mensaje diario.
- [ ] Definir cómo evitaremos pulsaciones accidentales.
- [ ] Probar el lector y la tarjeta SD.
- [ ] Resolver cómo hacer un apagado seguro para no dañar la SD.
- [ ] Probar la cadena Raspi + PAM8403 + parlante.
- [ ] Definir cómo se conectará exactamente el módulo desmontable.
- [ ] Probar los conectores JST.
- [ ] Definir las medidas finales de la carcasa.
- [ ] Definir las medidas del módulo desmontable.

---

# Lo que definimos hoy

Siento que hoy pasamos de tener varias ideas dando vueltas a empezar a entender **qué queremos que sea realmente el proyecto**.

Primero descartamos seguir desarrollando Fan Connect porque todavía tenía demasiadas preguntas difíciles de resolver, sobre todo por la música, el usuario y cómo funcionaría realmente el intercambio.

Con el **dispositivo sonoro para niños** sentimos que tenemos un camino mucho más claro.

Ya tenemos:

```text
USUARIO
↓
niños de 3 a 4 años

INTERACCIÓN
↓
3 botones físicos

CONTENIDOS
↓
cuentos + música + mensajes

MOMENTOS
↓
día + noche

CUIDADOR
↓
módulo desmontable de grabación
```
## encargos

## lectura
