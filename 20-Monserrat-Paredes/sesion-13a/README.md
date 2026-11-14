# sesion-13a → 10/11/26

## apuntes sesión

- Ver fechas nuevas en base al curso.
- Bajar el proyecto-03 y ver todas las cosas que el proyecto puede hacer y las que no (10 ideas cortas).
- Avanzar en el bill of materials y diagrama de flujo.
- Texto descriptivo del proyecto.


sesión-13b (viernes 13):
- descripción total del proyecto
- prototipos
- pseudocódigo
- esqueleto en wokwi

---
  
### 10 cosas que si queremos para el proyecto

1. samples de nuestras canciones favoritas (licencias).

2. grabar sonidos propios ya que todos los sonidos son unicos y que nunca sea el mismo
3. A partir de un sonido, puedo crear historias y sensaciones en  las personas 
4. Con diferentes sonidos rapidos y fugaces se generan diferentes sensaciones
5. generar una máquina que detecta si eres un humano con diferentes sonidos
6. que el usuario tenga que hacer un sonido que la máquina diga
7. ocupar sensores para generar un juego interactivo
8. usar la repetición 
9. generar vibraciones mediante la musica
10. con volumen regulable
11. que tenga luces


### 10 cosas que no queremos para el proyecto

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

---

Diagrama de flujo 

- ovalos = start/stop
- cuadrados = operación
- rombo = decisiones (if)

referentes → <https://www.visual-paradigm.com/tutorials/flowchart-tutorial/>

Ejemplo de discord:

inicio → dormir? ─sí→ ¿estímulo? ─no→ seguir durmiendo

                         │sí→ despertar (sonido)
                         
leer sensores → ¿qué sensor?

   ├ panza → reír
   
   ├ espalda → ronronear
   
   ├ volteado → quejarse
   
   └ oscuridad → bostezar → dormir
  
  → ¿tiempo sin estímulo? ─sí→ dormir
  
inicio → ¿tarjeta acercada? —no→ esperar

            │sí
            
   ¿es bancaria? —sí→ ¿es bus Red? —sí→ rechazar (sonido error)
   
            │no                    │no→ cobrar → sonido OK
            
   ¿saldo suficiente? —sí→ cobrar → sonido OK → fin}
   
            │no
            
   ¿es bus y hay saldo de emergencia? —sí→ cobrar → sonido OK
   
            │no→ rechazar (sonido error)


---

# Texto descriptivo del proyecto

Nuestro proyecto n°3 se basará en crear un juego donde el jugador debe interactuar con el sistema mediante botones pulsadores y utilizar el sonido como principal medio de comunicación para comprender lo que sucede durante la partida.

El juego consiste en controlar una nave espacial que debe sobrevivir a diferentes ataques enemigos, esquivando obstáculos y eliminando adversarios mediante disparos. A medida que transcurre el tiempo, la dificultad aumenta progresivamente, generando nuevos desafíos que exigen mayor atención y capacidad de reacción. A través de diferentes señales sonoras, el jugador podrá identificar la ubicación de los enemigos, anticipar ataques, reconocer daños en su nave y recibir información sobre su desempeño.

El jugador deberá interpretar las señales auditivas para tomar decisiones, desplazarse entre diferentes posiciones y disparar contra los enemigos antes de recibir un ataque.  La partida termina cuando la nave pierde todas sus vidas. El sistema comunica el resultado mediante una secuencia sonora y permite iniciar una nueva partida. 


## 1. **Mecánica y funcionamiento** 

El videojuego funciona mediante tres posiciones imaginarias: izquierda, centro y derecha. Estas posiciones representan los diferentes sectores del espacio por los que pueden aparecer los enemigos y desplazarse la nave del jugador. Durante la partida, los enemigos aparecen aleatoriamente en cualquiera de estos sectores. El jugador debe reconocer su ubicación mediante las señales emitidas por el parlante y utilizar los botones para desplazarse o disparar. 


## El funcionamiento general se desarrolla de la siguiente manera:

1. **Inicio:** el jugador presiona el botón de inicio y el sistema reproduce una señal sonora que indica que la partida ha comenzado.  
2. **Desarrollo:** aparecen enemigos y obstáculos en diferentes posiciones.  
3. **Identificación:** el parlante reproduce señales específicas que permiten reconocer la ubicación y proximidad de los enemigos.  
4. **Interacción:** el jugador utiliza los botones para desplazarse y disparar.  
5. **Supervivencia:** debe evitar los ataques enemigos y eliminar adversarios para conseguir puntos.  
6. **Dificultad progresiva:** a medida que aumenta el tiempo de juego, los enemigos aparecen con mayor frecuencia y velocidad.  
7. **Finalización:** cuando el jugador pierde todas sus vidas, se reproduce una señal de derrota y se comunica la puntuación final.


## Cada sonido tendrá un significado específico:

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


## Bill of Materials (BOM)

| # | Cantidad | Componente | Descripción / Función | Precio unitario | Subtotal | Proveedor | Enlace |
|---|:--------:|------------|------------------------|:---------------:|:--------:|-----------|--------|
| 1 | 1 | Raspberry Pi Pico RP2040 | Controlador principal del videojuego | $ | $ | | [Link]() |
| 2 | 1 | Parlante de 8 Ω | Reproducción de señales y efectos sonoros | $ | $ | | [Link]() |
| 3 | 1 | Amplificador PAM8302 | Amplificación de las señales de audio | $ | $ | | [Link]() |
| 4 | 4 | Pulsadores electrónicos | Control de movimiento, disparo e inicio | $ | $ | | [Link]() |
| 5 | 4 | Resistencias de 10 kΩ | Opcionales, según la configuración de los botones | $ | $ | | [Link]() |
| 6 | 1 | Protoboard | Montaje y conexión de los componentes | $ | $ | | [Link]() |
| 7 | Variable | Cables Dupont | Conexiones eléctricas | $ | $ | | [Link]() |
| 8 | 1 | Fuente de alimentación USB de 5 V | Suministro de energía | $ | $ | | [Link]() |
| | | | **Total** | | **$** | | |


## encargos

sesión-13b (viernes 13):

- descripción total del proyecto
  
- prototipos
  
- pseudocódigo
  
- esqueleto en wokwi

  
## lectura

Libro: A New Program for Graphic Design

Autor: David Reinfurt

El libro está dividido en 3 grandes capítulos.

I. T--Y-P-O-G-R-A-P-H-Y

II. G-E-S-T-A-L-T

III. I-N-T-E-R-F-A-C-E

El autor plantea las bases de lo que significa enseñar diseño gráfico hoy. Introduce la idea de que el diseño no se trata de "estilo" o decoración, sino de sistemas, reglas y tecnología aplicadas a la comunicación.


### Bloque 8 · Typography (paginas 81-90)

1. Tema central

Donald Knuth trata la tipografía como un problema matemático y programable. De esa idea nacen TeX (composición de página) y Metafont (diseño de letras mediante ecuaciones).


2. Análisis directo

- Knuth da una conferencia de prestigio y en vez de hablar de matemática habla de tipografía.
  
- Una cuadrícula donde cada cuadro es tinta o no tinta (1 o 0). Ahí el diseño se vuelve algo que un programa puede resolver.
  
- El autor etiqueta títulos, cursivas y fórmulas (como en HTML) y el sistema hace el trabajo de formato. Sus algoritmos de justificación terminaron en software como PageMaker, QuarkXPress e InDesign.
  
- En Metafont cada letra es un esqueleto definido por ecuaciones paramétricas. Cambiando la “pluma” o los parámetros, el mismo esqueleto da serif, sans serif, versiones inclinadas o incluso letras que se achican hasta el infinito.
  
- El diario manuscrito de Knuth y el artículo “The Letter S” muestran el diseño como ensayo y error técnico, contado con humor. Software, tipo y artículo son obra de un mismo autor.
  
- Metafont no despegó (curva matemática alta para diseñadores, poco interés tipográfico de los matemáticos). Reinfurt tardó unos seis meses en rehabilitarlo junto a Stuart Bertolotti-Bailey y lo ve como una posibilidad que quedó abierta.


3. Glosario técnico

| Término (Inglés) | Traducción (Español) | Explicación |
|---|---|---|
| Typesetting | Composición tipográfica | Organizar texto en página usando tipos o software. |
| Phototypesetting | Fotocomposición | Composición por medios fotográficos, que reemplazó al metal. |
| Galley proofs | Galeradas | Pruebas de impresión previas a la edición final. |
| Markup language | Lenguaje de marcado | Texto con etiquetas que indican estructura, como HTML. |
| Parametric equations | Ecuaciones paramétricas | Ecuaciones con parámetros que definen la forma de la letra. |
| Skeleton | Esqueleto | Forma base de una letra antes de dibujarla con una pluma. |
| Ligature | Ligadura | Dos o más letras unidas en un solo glifo. |
| Bitmap | Mapa de bits | Imagen formada por una cuadrícula de píxeles encendidos o apagados. |


4. Citas

**Cita 1 (p. 85)**

INGLÉS: “Knuth was horrified by the quality of the new phototype. He also realized that setting a page of type is a discrete problem. Divide the page into a fine grid of squares—each box is either black or white, ink or no ink, 1 or 0.”

ESPAÑOL: “Knuth quedó horrorizado por la calidad del nuevo fototipo. También se dio cuenta de que componer una página de tipos es un problema discreto. Divide la página en una cuadrícula fina de cuadrados: cada casilla es negra o blanca, tinta o no tinta, 1 o 0.”

Análisis: Aquí la tipografía pasa de oficio visual a problema computable. Esa lógica binaria es la base de toda la tipografía digital.


**Cita 2 (p. 86)**

INGLÉS: “Metafont is a tool for designing and generating typefaces by describing them mathematically. TeX puts type on a page and Metafont draws that type.”

ESPAÑOL: “Metafont es una herramienta para diseñar y generar tipografías describiéndolas matemáticamente. TeX pone el tipo en la página y Metafont dibuja ese tipo.”

Análisis: Reparte el trabajo en dos sistemas: uno compone y otro dibuja. La letra deja de ser un dibujo fijo y pasa a ser una descripción.


**Cita 3 (p. 88)**

INGLÉS: “Metafont, however, never really took off. Its mathematical learning curve proved a bit steep for type designers. And mathematicians were not necessarily so interested in designing typefaces. It remains an alternate typographic future.”

ESPAÑOL: “Sin embargo, Metafont nunca despegó realmente. Su curva de aprendizaje matemática resultó algo empinada para los diseñadores de tipos. Y los matemáticos no estaban necesariamente tan interesados en diseñar tipografías. Sigue siendo un futuro tipográfico alternativo.”

Análisis: Una buena idea técnica puede fracasar por quedar entre dos comunidades. Reinfurt la rescata como camino posible que no se tomó.
