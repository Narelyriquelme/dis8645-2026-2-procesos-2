# sesion-14a

17-11-2026

## apuntes sesión

La clase pasada corregimos varias veces en la misma carpeta de la sesión-13b para ajustar el proyecto. El último que nos revisaron y vamos a ajustar es que él quedó ahí, pero ahora lo haremos de repertorio de sonidos personales para no tener que lidiar con temas de derechos y para poder hacerlo con una profundidad y especificidad que nosotros queramos, con sonidos específicos que elijamos de la universidad, como en un soundboard.

### Proyecto 03 · Grupo 8

Sound Board (con sonidos propios)

**Descripción del proyecto**

El proyecto consiste en construir un muestrario interactivo con nueve sonidos grabados por nosotros.

Habrá tres categorías, cada una asociada a un botón y compuesta por tres grabaciones distintas.

El equipo definirá las categorías y elegirá qué objetos, acciones o ambientes registrar. Cada pista tendrá una ficha breve con el nombre del sonido, qué lo produjo y quién lo grabó. Así, la selección final tendrá una relación directa con lo que el grupo decida explorar.

La consola tendrá tres botones, dos perillas y un parlante. Al presionar un botón, se escucha el primer sonido de su categoría. Las siguientes pulsaciones sobre ese mismo botón avanzan al segundo y al tercero, y después vuelven al primero. Cada botón conserva su posición en la secuencia.

Una perilla regula el volumen desde el silencio hasta el máximo configurado. La otra modifica la altura del sonido, desde más grave hasta más agudo, con el tono original en el centro.

La consola estará en una espera silenciosa (standby) hasta que se pulse un botón. Si se presiona otro botón, o se vuelve a presionar el mismo mientras suena una pista, la reproducción se corta y la siguiente comienza desde el principio después de una pausa breve de aproximadamente medio milisegundo.

Al terminar, la consola vuelve a quedar en silencio.

También se contempla una décima grabación sorpresa, integrada por el grupo, y se activa al presionar los tres botones juntos.

| Control | Función definida |
|---|---|
| **Botón 1** | Reproduce las tres grabaciones de la categoría 1 en orden: 1 , 2, 3 y 1. |
| **Botón 2** | Reproduce las tres grabaciones de la categoría 2 con su propia secuencia. |
| **Botón 3** | Reproduce las tres grabaciones de la categoría 3 con su propia secuencia. |
| **Perilla de volumen** | A la izquierda, silencio. Al girar hacia la derecha, el volumen aumenta progresivamente hasta el máximo configurado. El cambio se escucha mientras suena la pista. |
| **Perilla de tono** | A la izquierda, más grave. Al centro, tono original. A la derecha, más agudo. Se puede ajustar antes de pulsar cualquier botón y el ajuste se aplica a la pista que empieza. |
| **Tres botones juntos** | Reproducen la grabación sorpresa una vez, sin avanzar las secuencias. Para volver a activarla, se deben soltar los tres botones. |

### Código y simulación en Wokwi

[Ver el código completo y probar el Soundboard de sonidos propios en Wokwi](https://wokwi.com/projects/480948910221458433)

## encargos

## lectura

En la pág. 96 se explica cómo funcionan los bucles y la sangría en Python.

Los bucles permiten repetir instrucciones utilizando for y range(), en cambio, la sangría sirve para identificar qué instrucciones pertenecen al bucle.

También se muestra while True, que permite repetir una acción indefinidamente hasta detener el programa.

Después se explica cómo utilizar las variables y las condiciones.

Con input() se puede pedir información al usuario, con if y else permite que el programa responda según los datos ingresados. Esto se muestra con un ejemplo en donde el programa reconoce si el usuario escribe el nombre Clark Kent.

También se presentan los operadores de comparación, como ==, !=, >, <, >= y <=, con los que podemos comparar valores. Además, se explica la diferencia entre = para asignar valores y == para compararlos. Estos operadores también pueden utilizarse con while para repetir preguntas hasta poder tener una respuesta correcta.

Al final, en la página 102 se comienza el proyecto Copos de nieve con Turtle, donde se enseña a utilizar una biblioteca de Python para que se hagan dibujos a través de movimientos de una tortuga digital.

Entendí en parte cómo funcionan las repeticiones, las condiciones y las variables, además de mostrarme que Python también me deja crear proyectos gráficos de una manera interesante y entretenida.
