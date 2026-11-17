# sesion-13a
Martes 10 de Noviembre

## apuntes sesión

### Exploración conceptual
Durante la sesión comenzamos explorando los conceptos de paisaje sonoro y ritual como posibles ejes para desarrollar nuestro proyecto.

Inicialmente, pensamos en construir un hidrófono que permitiera escuchar los sonidos del agua, tomando como inspiración algunos aspectos de la cosmovisión mapuche y su relación ceremonial con la naturaleza. Sin embargo, luego de reflexionar sobre la propuesta y recibir las correcciones de Misa, decidimos replantear esta idea. Nos dimos cuenta de que era delicado utilizar elementos de una cosmovisión que no nos pertenece y que, además, el hidrófono funcionaba principalmente como un sensor y no como una máquina interactiva.

A partir de esto, decidimos mantener el interés por la relación entre las personas, la naturaleza y los rituales, pero abordándolo desde una perspectiva más amplia.

### Desarrollo de la idea
Nuestra primera propuesta consistía en crear una máquina que funcionara como un archivo de sonidos cotidianos de Chile, al que las personas pudieran acceder mediante la pausa y la contemplación.

Consideramos diferentes categorías de sonidos:
- **Territorios:** viento, lluvia, mar, ríos, bosques y animales.
- **Vida cotidiana:** ferias, transporte, calles, conversaciones y oficios.
- **Expresiones culturales:** música, celebraciones, instrumentos y encuentros comunitarios.
- **Memorias:** sonidos del hogar, cocina, juegos, relatos y recuerdos personales.

Después de profundizar en estas posibilidades, decidimos enfocar el proyecto exclusivamente en los sonidos de la biodiversidad de nuestro territorio, especialmente en aquellas especies que se encuentran amenazadas.

Nos interesa visibilizar su existencia a través del sonido, generando una experiencia que permita conocerlas y reflexionar sobre su cuidado. Partimos de la idea de que no se puede proteger aquello que no se conoce.

### Concepto: Ecos en extinción
La propuesta consiste en desarrollar un instrumento interactivo que permita escuchar, activar, silenciar y superponer los sonidos de diferentes especies de animales mediante controles físicos.

Cada especie contará con un canal independiente, permitiendo modificar su volumen y combinar distintas grabaciones para construir composiciones sonoras.

De esta manera, la máquina funcionará como un archivo de biodiversidad sonora y, al mismo tiempo, como una herramienta de exploración y composición colectiva.

### Funcionamiento
- Encendido: la persona presiona el botón de la esquina superior, suena un sonido que indica que esta encendido.
- Lectura de controles: al terminar el sonido, la máquina lee la posición de las 4 perillas de especie y de las 4 perillas de volumen, carga la especie que marca cada perilla de especie.
- Inicio en silencio: si las perillas de volumen están al mínimo, no se oye nada y el paisaje sonoro parte desde el silencio.
- Activar una especie: la persona sube una perilla de volumen y esa especie aparece en el paisaje. Las 4 categorías (mamíferos, aves, anfibios, insectos) suenan en loop, así que al subir el volumen entran en sincronía con las demás.
- Cambiar de especie: al girar una perilla de especie, el canal cambia a otra especie de su categoría y se escucha directamente el nuevo sonido (si el volumen está arriba de cero). 
- Ajustar volumen: con cada perilla de volumen, la persona sube o baja el volumen de cada sonido, creando distintos ritmos, intensidades y relaciones entre sonidos.
- Silenciar una especie: al bajar una perilla de volumen a cero, esa especie desaparece del paisaje. Su ausencia transforma la composición y permite notar la importancia de cada voz.
- Componer: la persona combina, suma y quita voces libremente, construyendo y transformando el paisaje sonoro de forma activa.
- Apagado: al presionar de nuevo el botón, se silencian todos los canales y la máquina queda en reposo.

### Bill of Materials (BOM)

| Componente | Cantidad |
|---|---:|
| Raspberry Pi Pico 2 W | 1 |
| Potenciómetros | 8 |
| Botón pulsador | 1 |

Esta lista todavía se encuentra en desarrollo y podría modificarse según las necesidades técnicas del proyecto.

### Experiencia de usuario
La experiencia comienza cuando la persona enciende la máquina mediante un botón pulsador. Al hacerlo, un sonido confirmará que el instrumento se encuentra encendido.

Para explorar y construir su propio paisaje sonoro, se consideran cinco categorías de biodiversidad:
- Aves.
- Mamíferos.
- Anfibios.
- Insectos.

Cada categoría contará con diferentes especies y sus respectivas grabaciones, las cuales todavía se encuentran pendientes de selección y definición.

### Pendientes
- Definir las especies que formarán parte de cada categoría.
- Investigar y recopilar grabaciones de sus sonidos.
- Definir cómo se distribuirán los controles físicos.
- Establecer la función de cada uno de los ocho potenciómetros.
- Continuar desarrollando la experiencia de usuario.
- Revisar los componentes electrónicos necesarios para reproducir y mezclar los sonidos.

## encargos

## lectura
