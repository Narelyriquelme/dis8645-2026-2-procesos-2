# sesion-13a

## apuntes sesión

martes 2026-11-10

hoy llego tarde por culpa del tren

sesión-13a (hoy):
- bill of materials (BOM)
- diagrama de flujo
- texto descriptivo del proyecto

sesión-13b (viernes):
- descripción total del proyecto
- prototipos
- pseudocódigo
- esqueleto en wokwi


### lluvia de ideas

**10 cosas que **si** queremos que haga nuestro proyecto 03:**

 1. samples de nuestras canciones favoritas (licencias)
 2. grabar sonidos propios ya que todos los sonidos son unicos y que nunca sea el mismo
 3. a partir de un sonido, puedo crear historias y sensaciones en  las personas 
 4. con diferentes sonidos rapidos y fugaces se generan diferentes sensaciones
 5. generar una máquina que detecta si eres un humano con diferentes sonidos
 6. que el usuario tenga que hacer un sonido que la máquina diga
 7. ocupar sensores para generar un juego interactivo
 8. usar la repetición 
 9. generar vibraciones mediante la musica
 10. con volumen regulable
 11. que tenga luces

**10 cosas que **no** queremos que haya nuestro proyecto 03:**

 1. ocupar pantallas
 2. no interactividad
 3. sonido constante 
 4. sonidos fuertes 
 5. que sea de cartón
 6. que levite
 7. que explote (kriss, hablo de ti)
 8. que mida más de 50cm
 9. arduino
 10. caro

### texto descriptivo del proyecto

Nuestro proyecto n°3 se basará en crear un juego donde el jugador debe interactuar con el sistema mediante botones pulsadores y utilizar el sonido como principal medio de comunicación para comprender lo que sucede durante la partida.

El juego consiste en controlar una nave espacial que debe sobrevivir a diferentes ataques enemigos, esquivando obstáculos y eliminando adversarios mediante disparos. A medida que transcurre el tiempo, la dificultad aumenta progresivamente, generando nuevos desafíos que exigen mayor atención y capacidad de reacción. A través de diferentes señales sonoras, el jugador podrá identificar la ubicación de los enemigos, anticipar ataques, reconocer daños en su nave y recibir información sobre su desempeño.

El jugador deberá interpretar las señales auditivas para tomar decisiones, desplazarse entre diferentes posiciones y disparar contra los enemigos antes de recibir un ataque.  La partida termina cuando la nave pierde todas sus vidas. El sistema comunica el resultado mediante una secuencia sonora y permite iniciar una nueva partida. 

1. **Mecánica y funcionamiento** 

El videojuego funciona mediante tres posiciones imaginarias: izquierda, centro y derecha. Estas posiciones representan los diferentes sectores del espacio por los que pueden aparecer los enemigos y desplazarse la nave del jugador. Durante la partida, los enemigos aparecen aleatoriamente en cualquiera de estos sectores. El jugador debe reconocer su ubicación mediante las señales emitidas por el parlante y utilizar los botones para desplazarse o disparar. 

El funcionamiento general se desarrolla de la siguiente manera:

1. **Inicio:** el jugador presiona el botón de inicio y el sistema reproduce una señal sonora que indica que la partida ha comenzado.  
2. **Desarrollo:** aparecen enemigos y obstáculos en diferentes posiciones.  
3. **Identificación:** el parlante reproduce señales específicas que permiten reconocer la ubicación y proximidad de los enemigos.  
4. **Interacción:** el jugador utiliza los botones para desplazarse y disparar.  
5. **Supervivencia:** debe evitar los ataques enemigos y eliminar adversarios para conseguir puntos.  
6. **Dificultad progresiva:** a medida que aumenta el tiempo de juego, los enemigos aparecen con mayor frecuencia y velocidad.  
7. **Finalización:** cuando el jugador pierde todas sus vidas, se reproduce una señal de derrota y se comunica la puntuación final.

Cada sonido tendrá un significado específico:

* **Pitido hacia la izquierda:** indica la presencia de un enemigo en el sector izquierdo.  
* **Pitido hacia la derecha:** indica la presencia de un enemigo en el sector derecho.  
* **Dos pitidos rápidos:** advierten que un enemigo se está aproximando.  
* **Sonido grave:** indica un ataque enemigo.  
* **Sonido de explosión:** comunica que un enemigo ha sido eliminado.  
* **Sonido de impacto:** indica que la nave recibió un daño.  
* **Alerta repetitiva:** advierte que el jugador se encuentra en su última vida.  
* **Melodía de recompensa:** indica que se consiguió una puntuación adicional o una mejora.  
* **Secuencia de derrota:** comunica que la partida ha terminado.

**Botón 1 – Movimiento hacia la izquierda:** permite desplazar la nave desde el centro hacia el sector izquierdo.

**Botón 2 – Movimiento hacia la derecha:** permite desplazar la nave desde el centro hacia el sector derecho.

**Botón 3 – Disparo:** permite atacar a los enemigos que aparecen durante la partida.

**Botón 4 – Inicio y pausa:** permite comenzar el videojuego, pausar la partida y reiniciarla cuando corresponda.

## encargos

## lectura

nos dejaron elegir un libro para leer durante el semestre en el cual debemos dejar 2 citas por clase y leer mínimo 100 paginas durante el semestre

libro escogido **La Música electroacústica en Chile** de Federico Schumacher

en esta ocasión leí dos capítulos del libroiván pequeño y jorge arriagada se instalaron en francia; arriagada terminó haciendo música para películas (destacando las de raúl ruíz).

### capítulo 1 leído del libro 
- **Europa. El Computador Virtuoso**
    - Iván Pequeño y Jorge Arriagada se instalaron en Francia, donde Arriagada terminó haciendo música para películas (destacando las de raúl ruíz)
    - Schaeffer vino a chile en 1971 pero su visita pasó casi desapercibida por peleas de ego y estéticas
    - Gustavo Becerra se exilió en alemania tras el golpe del 73 y siguió creando obras con sensores y pcs
    - Asuar volvió de eeuu y usó un pc pdp-8 con sintetizadores arp y moog para grabar **el computador virtuoso (1973)**
    - ese disco metió arreglos de bach y hasta el himno del club de fútbol de la u de chile, anticipándose diez años al formato midi
  

### capítulo 2 leído del libro 
- **El golpe militar y la Música Electriacústica**
   - la dictadura no freno al toque la electroacustica en el 73
   - Asuar y Amenabar siguieron activos publicando discos y en la u de chile unos años mas
   - el freno real fue mas por peleas internas de ego: amenabar no quiso trabajar con asuar en tecnologia del sonido diciendo que el "no era segundo de nadie"
   - el exilio golpeo fuerte a la vanguardia porque referentes clave como becerra, brncic y ortega tuvieron que irse del pais
   - en dictadura las programaciones se volvieron ultra conservadoras (pura musica clasica/barroca) y sacaron la vanguardia de las salas oficiales
   - la escena sobrevivio a pulso por autogestion en los 80 con agrupaciones independientes como anacrusa y festivales en el instituto Goethe

### citas del libro

**cita 1**: 

**_"...esta última realizada por encargo del GMEB para la obra colectiva Les Saisons, la que también fue encargo de los Juegos Olímpicos realizados en Munich en 1973"_**

página 75

**opinión:** juegos olímpicos con ruidos raros de fondo

**cita 2**: 

**_"...desgraciadamente, se hace difícil distinguir dónde empieza la historia colectiva y dónde la personal"_**

página 85

**opinión:**  al final por mas genio que seas o pelees por puras tonteras de ego, la política siempre te estará presente  aunque no quieras
