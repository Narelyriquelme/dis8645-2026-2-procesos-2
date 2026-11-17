# grupo-03

## integrantes

- Magdalena Balart [_(magdalenabalart)_](https://github.com/disenoUDP/dis8645-2026-2-procesos-2/tree/main/02-magdalenabalart)
- Catalina Oyanedel [_(catalinaoyanedel-01)_](https://github.com/disenoUDP/dis8645-2026-2-procesos-2/tree/main/17-catalinaoyanedel-01)
- Yaira Ruiz [_(yairaruiz)_](https://github.com/disenoUDP/dis8645-2026-2-procesos-2/tree/main/26-yairaruiz)
- Marcela Zuñiga [_(marcezm)_](https://github.com/disenoUDP/dis8645-2026-2-procesos-2/tree/main/32-marcezm)

## sobre el proyecto

El proyecto busca educar en cuanto a biodiversidad de especies que se encuentran amenazadas o en peligro de extinción en nuestro territorio. La máquina sonora constaría de 4 categorías: mamíferos, aves, anfibios e insectos. Dentro de cada categoría, van a haber 3 especies, una por cada parte del país: norte, centro y sur.

### funcionamento

Habrá un potenciómetro por cada categoría, donde a través de umbrales se reconocerá qué especie fue seleccionada. Además, las categorías irán acompañadas de otro potenciómetro para controlar el volumen de cada una. Así, cada usuario puede construir su paisaje sonoro de especies.

Boceto de la máquina:

![boceto](./imagenes/boceto.jpeg)

Paso a paso:

- Encendido: la persona presiona el botón de la esquina superior, suena un sonido que indica que esta encendido.
- Lectura de controles: al terminar el sonido, la máquina lee la posición de las 4 perillas de especie y de las 4 perillas de volumen, carga la especie que marca cada perilla de especie.
- Inicio en silencio: si las perillas de volumen están al mínimo, no se oye nada y el paisaje sonoro parte desde el silencio.
- Activar una especie: la persona sube una perilla de volumen y esa especie aparece en el paisaje. Las 4 categorías (mamíferos, aves, anfibios, insectos) suenan en loop, así que al subir el volumen entran en sincronía con las demás.
- Cambiar de especie: al girar una perilla de especie, el canal cambia a otra especie de su categoría y se escucha directamente el nuevo sonido (si el volumen está arriba de cero). 
- Ajustar volumen: con cada perilla de volumen, la persona sube o baja el volumen de cada sonido, creando distintos ritmos, intensidades y relaciones entre sonidos.
- Silenciar una especie: al bajar una perilla de volumen a cero, esa especie desaparece del paisaje. Su ausencia transforma la composición y permite notar la importancia de cada voz.
- Componer: la persona combina, suma y quita voces libremente, construyendo y transformando el paisaje sonoro de forma activa.
- Apagado: al presionar de nuevo el botón, se silencian todos los canales y la máquina queda en reposo.

### diagrama de flujo

```mermaid
---
config:
  theme: default
---
flowchart TD
    A([Inicio]) --> B[Presionar botón de encendido]
    B --> C[Reproducir sonido de encendido]
    C --> D[Leer posición de las 4 perillas de especie]
    D --> E[Cargar especie seleccionada en cada canal]
    E --> F[Leer posición de las 4 perillas de volumen]
    F --> G[Iniciar reproducción de los canales en loop]

    G --> H{¿Volumen mayor a cero?}
    H -->|No| I[Canal permanece en silencio]
    H -->|Sí| J[Reproducir sonido de la especie seleccionada]

    I --> K[Esperar interacción de la persona]
    J --> K

    K --> L{¿Qué control se modifica?}

    L -->|Perilla de especie| M[Cambiar especie de la categoría]
    M --> N[Cargar y reproducir nuevo sonido]
    N --> K

    L -->|Perilla de volumen| O[Ajustar volumen del canal]
    O --> P{¿Volumen está en cero?}
    P -->|Sí| Q[Silenciar especie]
    P -->|No| R[Reproducir especie con nuevo volumen]
    Q --> K
    R --> K

    L -->|Ninguno| K

    K --> S{¿Presiona botón de apagado?}
    S -->|No| L
    S -->|Sí| T[Silenciar todos los canales]
    T --> U[Detener reproducción]
    U --> V([Máquina en reposo])
```

### BOM – Lista de materiales

| N° | Componente | Descripción / Función | Cantidad |
|---:|---|---|---:|
| 1 | Multiplexor I2C | Permite conectar varios dispositivos I2C utilizando un mismo bus de comunicación. | 1 |
| 2 | Buzzer | Emite sonidos de aviso, como el sonido de encendido de la máquina. | 1 |
| 3 | MAX98357A – I2S Class-D Mono Amplifier | Amplifica la señal de audio digital I2S para reproducir sonidos mediante un parlante. | 1 |
| 4 | Potenciómetros | Permiten seleccionar especies y regular el volumen de cada canal. | 8 |
| 5 | Cables Dupont | Permiten realizar conexiones eléctricas entre componentes. | Según necesidad |
| 6 | Cables Dupont macho-hembra | Conexiones entre pines y módulos electrónicos. | Según necesidad |
| 7 | Cables Dupont hembra-hembra | Conexiones entre pines o módulos con terminales macho. | Según necesidad |
| 8 | Cables Dupont macho-macho | Conexiones en protoboard y otros puntos de conexión. | Según necesidad |
| 9 | Botón pulsador | Permite encender y apagar la máquina. | 1 |

### referentes

![referente](./imagenes/referente2.png)

Queremos rescatar de este referente la carcasa e interfaz, para realizar gráficas en vinilo o grabado láser. Por ejemplo, con la perilla, utilizar las siluetas de las especies para indicar donde se encuentra el usuario, hacer que la interacción sea más fácil de entender y permita la exploración autónoma.

- [PercuSynth - GC Lab](https://youtube.com/shorts/DbD2s_9ED9s)
- [Proto-Synth V2.0 - GC Lab](https://youtube.com/shorts/6owidjx-n7g)

Estos son nuestros referentes sonoros, son sintetizadores de GC Lab, los cuales trabajan con la construcción de paisajes sonoros de ambientes naturales y pájaros.

### pseudocódigo

```cpp
// ============ DATOS ============

categorias = [mamiferos, aves, anfibios, insectos]
especiesPorCategoria = 3

// Un audio por especie (todos preparados para repetirse en loop)
audios[categoria][especie] = "mamiferos/huemul", "aves/...", etc.
sonidoEncendido = "sistema/encendido"
sonidoApagado = "sistema/apagado"

// Estado general
maquinaEncendida = falso

// Estado de cada categoría
para cada categoria:
    especieActual[categoria] = ninguna
    volumenActual[categoria] = 0


// ============ PROGRAMA PRINCIPAL ============

inicio:
    prepararMaquina()
    quedarEnReposo()

    repetir siempre:
        si botonEncendidoPresionado():
            si maquinaEncendida:
                apagarMaquina()
            sino:
                encenderMaquina()

        si maquinaEncendida:
            para cada categoria en categorias:
                revisarEspecie(categoria)
                revisarVolumen(categoria)


// ============ ENCENDIDO Y APAGADO ============

funcion encenderMaquina():
    maquinaEncendida = verdadero
    reproducir(sonidoEncendido)
    esperarFinDelSonido()

    para cada categoria en categorias:
        especieActual[categoria] = ninguna
        volumenActual[categoria] = ninguno
        revisarEspecie(categoria)          // carga la especie que marca la perilla
        revisarVolumen(categoria)          // aplica el volumen que marca la perilla

funcion apagarMaquina():
    reproducir(sonidoApagado)
    esperarFinDelSonido()
    maquinaEncendida = falso
    quedarEnReposo()

funcion quedarEnReposo():
    para cada categoria en categorias:
        detenerSonido(categoria)
        fijarVolumen(categoria, 0)


// ============ CONTROLES ============

funcion revisarEspecie(categoria):
    posicion = leerPerillaEspecie(categoria)
    nuevaEspecie = convertirAEspecie(posicion, especiesPorCategoria)

    si nuevaEspecie es distinta de especieActual[categoria]:
        cambiarEspecie(categoria, nuevaEspecie)

funcion revisarVolumen(categoria):
    posicion = leerPerillaVolumen(categoria)
    nuevoVolumen = convertirAVolumen(posicion)       // de 0 a 100

    si nuevoVolumen es distinto de volumenActual[categoria]:
        volumenActual[categoria] = nuevoVolumen
        fijarVolumen(categoria, nuevoVolumen)


// ============ CAMBIO DE ESPECIE ============

funcion cambiarEspecie(categoria, nuevaEspecie):
    especieActual[categoria] = nuevaEspecie
    detenerSonido(categoria)
    cargarAudio(categoria, audios[categoria][nuevaEspecie])
    reproducirEnLoop(categoria)                      // siempre suena, el volumen decide si se oye
    fijarVolumen(categoria, volumenActual[categoria])
```

### wokwi
El simulador se trabajó con IA para hacer pruebas de las conexiones que necesitabamos.

Prompt:
> "Para este examen vamos a trabajar con C++. Necesito desarrollar un código de prueba para controlar 8 potenciómetros y un botón de encendido/apagado. Los primeros 4 potenciómetros serán para seleccionar especies. Cada uno tendrá 3 rangos de valores, correspondientes a Especie 01, Especie 02 y Especie 03, dependiendo de cuánto se gire. Los otros 4 potenciómetros controlarán el volumen de cada uno de los selectores, de forma independiente. Además, necesitamos un botón que permita encender y apagar todo el sistema, deteniendo la reproducción de los sonidos cuando esté apagado. La idea es probar primero esta lógica de funcionamiento en C++, utilizando sonidos de prueba y dejando el código preparado para integrar posteriormente los audios definitivos."

https://wokwi.com/projects/479334243939894273



