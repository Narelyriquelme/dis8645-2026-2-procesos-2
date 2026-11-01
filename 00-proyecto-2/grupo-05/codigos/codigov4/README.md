# Altiro Hero — codigo ordenado con sonido

Proyecto C++ para **Raspberry Pi Pico 2 W / ARM**, con **Pico SDK**.
Conserva el juego, int main(), while (true), las animaciones y los controles.
La reorganizacion no cambia main.cpp, Boton, Perilla, Matriz ni los dos
archivos conservados de Wokwi.

## Archivos que se comparten

| Archivo | Funcion |
| --- | --- |
| main.cpp | Coordina el juego, lee controles y pide los sonidos de cada evento. |
| Boton.h / Boton.cpp | Botones, interruptor, pulsaciones y antirrebote. |
| Perilla.h / Perilla.cpp | Velocidad y seleccion del camino. |
| Matriz.h / Matriz.cpp | LEDs, colores, numeros, textos y animaciones. |
| Sonido.h | Declara las funciones de sonido y contiene el ajuste de amplitud. |
| Sonido.cpp | Melodias, efectos y motor I2S nativo, incluyendo las instrucciones PIO. |
| CMakeLists.txt | Configura la compilacion con Pico SDK para Pico 2 W / ARM. |
| diagram.json | Conserva el circuito virtual de Wokwi con los botones en GP2 y GP3. |
| wokwi-project.txt | Conserva el enlace al proyecto original de Wokwi. |
| README.md | Estas instrucciones de preparacion, compilacion y carga. |

Los archivos .h declaran lo que puede hacer cada parte; los .cpp contienen
las implementaciones. El programa PIO del sonido esta incluido en Sonido.cpp,
igual que el de los LEDs esta incluido en Matriz.cpp.
La licencia del programa PIO esta incorporada como comentario en Sonido.cpp.

No se necesitan Volumen.h, audio_i2s.pio, pico_sdk_import.cmake local,
compilar-sdk.ps1 ni una carpeta .vscode. Las antiguas tareas Compile Project
y Run Project se retiraron al simplificar. Ahora se compila con CMake.
Pico SDK sigue siendo necesario y se instala fuera de esta carpeta.

## Requisitos para otra persona

Instalar:

- Pico SDK. Version comprobada: 2.3.1, con sus submodulos, incluido TinyUSB.
- Compilador GNU Arm Embedded para Cortex-M33. Comprobado: GCC 15.2.1.
- CMake y Ninja.
- picotool, que el SDK utiliza para generar el UF2. Comprobado: 2.3.1.

En Windows, la extension oficial **Raspberry Pi Pico** de Visual Studio Code
puede instalar estas herramientas. El editor es opcional para compilar.
No hacen falta Arduino IDE ni Arduino-Pico.

Pico SDK: https://github.com/raspberrypi/pico-sdk
Extension Pico: https://github.com/raspberrypi/pico-vscode

## Compilar en Windows con las herramientas de la extension Pico

1. Extraer o copiar toda esta carpeta.
2. Abrir una terminal PowerShell **dentro de la carpeta que contiene
   CMakeLists.txt**. Tambien puede usarse Terminal > Nuevo terminal en VS Code.
3. Ejecutar lo siguiente. Si las herramientas instaladas tienen otras
   versiones, ajustar los nombres de sus carpetas.

~~~powershell
$picoTools = Join-Path $env:USERPROFILE '.pico-sdk'
$env:PICO_SDK_PATH = Join-Path $picoTools 'sdk/2.3.1'
$env:PICO_TOOLCHAIN_PATH = Join-Path $picoTools 'toolchain/15_2_Rel1'
$env:Path = "$picoTools/toolchain/15_2_Rel1/bin;$picoTools/cmake/v4.3.4/bin;$picoTools/ninja/v1.13.2;$env:Path"

cmake -S . -B build -G Ninja "-Dpicotool_DIR=$picoTools/picotool/2.3.1/picotool" -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 4
~~~

La placa y arquitectura ya se fijan en CMakeLists.txt:
**PICO_BOARD=pico2_w** y **PICO_PLATFORM=rp2350-arm-s**.

Si las herramientas se instalaron de otra forma, indicar sus rutas reales
en PICO_SDK_PATH, PICO_TOOLCHAIN_PATH y picotool_DIR. CMake, Ninja y el
compilador deben estar disponibles para la terminal.
CMakeLists.txt utiliza el importador que viene dentro del SDK instalado;
no necesita una copia de pico_sdk_import.cmake junto al juego.

La carpeta **build** se crea al compilar. Los resultados son:

- build/altiro_hero.uf2: programa que se copia a la Pico.
- build/altiro_hero.elf: programa con informacion para depuracion.
- Otros archivos de compilacion que no se necesitan compartir con el codigo.

Despues de cambiar el codigo o la amplitud, guardar y ejecutar otra vez:

~~~powershell
cmake --build build --parallel 4
~~~

## Cargar y ejecutar en la Pico

1. Hacer los cambios de cableado con la alimentacion desconectada.
2. Mantener BOOTSEL presionado mientras se conecta la Pico por USB.
3. Soltar BOOTSEL cuando aparezca la unidad RP2350.
4. Copiar **build/altiro_hero.uf2** a esa unidad.
5. La Pico se reinicia y ejecuta el juego. Activar el interruptor del montaje.

## Amplitud del sonido

Editar en **Sonido.h**:

~~~cpp
constexpr int AUDIO_AMPLITUDE{2000};
~~~

2000 es el valor probado. Reducir con enteros como 1000, 500, 200 o 100.
0 envia silencio digital. Guardar, volver a compilar y cargar el nuevo UF2.

El motor utiliza 16000 Hz, muestras de 16 bits con signo y onda cuadrada.
La misma muestra se envia a los dos canales. Sin una nota se transmiten
ceros. SD no se controla por software.
La matriz mantiene PIO0. El audio usa PIO1, DMA y el segundo nucleo con
una pila independiente de 8 KiB. El juego sigue funcionando en el nucleo 0.

## Conexiones

| Elemento | Pico 2 W | Pin fisico |
| --- | --- | --- |
| Boton 1: navegar | GP2 | 4 |
| Boton 2: seleccionar / atrapar | GP3 | 5 |
| Interruptor | GP9 | 12 |
| DIN de la matriz | GP10 | 14 |
| Senal perilla de velocidad | GP26 | 31 |
| Senal perilla de camino | GP27 | 32 |
| Alimentacion de controles y perillas | 3V3 OUT | 36 |
| Tierra comun | GND | 38 |

Los botones e interruptor son activos en HIGH, con resistencia externa
de 10 kOhm entre su entrada y GND. Al accionar conectan la entrada a 3V3.
Las perillas llevan sus extremos a 3V3/GND y la senal central al GPIO indicado.
Los botones que antes iban a GP7 y GP8 deben estar en GP2 y GP3.

| MAX98357A | Pico 2 W |
| --- | --- |
| BCLK | GP6, pin fisico 9 |
| LRC / LRCLK | GP7, pin fisico 10 |
| DIN | GP8, pin fisico 11 |
| VIN | VBUS, pin fisico 40; Pico alimentada por USB |
| GND | GND, pin fisico 38 |
| SD | Sin conectar |
| GAIN | Sin conectar |

Parlante de 8 ohmios / 1 W entre SPK+ y SPK-.
La matriz y todos los controles deben compartir GND con la Pico.

## Archivos de Wokwi conservados

diagram.json y wokwi-project.txt se mantienen exactamente como estaban
antes de esta reorganizacion. Conservan el esquema y el enlace de referencia.
El diagrama actual contiene una Pico RP2040; el firmware fisico se compila
para la Pico 2 W RP2350. Conservar los archivos no convierte el firmware
en una simulacion lista para ejecutar.

Wokwi documenta actualmente un solo nucleo simulado para Pico 2/2 W.
Esta version utiliza el segundo nucleo para el audio, por lo que no se
debe iniciar directamente como simulacion sin adaptar esa parte.
El juego para la placa fisica se mantiene con Pico SDK.
Referencia: https://docs.wokwi.com/parts/board-pi-pico-2#simulation-features

## Verificacion y pruebas fisicas

La reorganizacion se comprueba compilando desde cero para Pico 2 W / ARM.
Las instrucciones I2S integradas conservan 16 bits por canal, el retardo de
un bit y los mismos relojes: LRCLK 16000 Hz y BCLK 512000 Hz.

La compilacion y la comprobacion de instrucciones no sustituyen la escucha.
Queda verificar en el montaje fisico: controles, tres niveles, todos los
efectos, ritmo con la perilla, continuidad de audio, amplitud y silencio.

## Respaldo anterior

En la carpeta de trabajo original se conserva:
_validacion/respaldos/antes-ordenar-20261031-223518.zip

Las configuraciones, scripts y carpetas de compilacion anteriores se
guardaron en _validacion/archivo-antes-ordenar-20261031-223518.
