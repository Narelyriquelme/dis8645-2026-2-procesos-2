# convertirRaw.py
# transforma los arreglos de sonido .h (Sonido0.h, Sonido1.h, ...) en archivos .raw
# para copiarlos a la tarjeta SD y leerlos con la clase LectorSD
#
# formato del .raw que se genera:
# PCM de 16 bits con signo, little-endian, mono, sin cabecera
# la frecuencia no se guarda en el archivo, sigue siendo la del .h (11025 Hz)
#
# como se usa (desde la carpeta codigos/convertir-raw):
#   python convertirRaw.py
#       convierte los sonidos del catalogo (Sonido0.h a Sonido4.h) de ../proyecto-03-v01
#       y los deja en ./raw, listos para copiar a la tarjeta SD
#       SonidoSistema.h no se convierte porque ese sonido sigue en la flash
#   python convertirRaw.py carpetaEntrada carpetaSalida
#       usa otras carpetas
#   python convertirRaw.py ../proyecto-03-v01/Sonido2.h
#       convierte un solo archivo
#
# el nombre del .raw es el nombre del arreglo: sonido0[] -> sonido0.raw
# esos nombres son los que busca Audio.cpp en la tarjeta SD
#
# solo usa librerias que vienen con python, no hay que instalar nada

import re
import sys
from pathlib import Path

# carpeta donde esta este script
CARPETA_SCRIPT = Path(__file__).resolve().parent
# carpeta del proyecto donde estan los .h, por defecto
CARPETA_ENTRADA = CARPETA_SCRIPT.parent / "proyecto-03-v01"
# carpeta donde se guardan los .raw, por defecto
CARPETA_SALIDA = CARPETA_SCRIPT / "raw"

# busca la declaracion del arreglo, por ejemplo:
#   static const uint16_t sonido0[] = {
# y captura el nombre del arreglo y todo lo que esta entre las llaves
PATRON_ARREGLO = re.compile(
    r"uint16_t\s+(\w+)\s*\[\s*\]\s*=\s*\{(.*?)\}\s*;", re.DOTALL
)
# busca cada numero hexadecimal del arreglo, por ejemplo 0xfff4
PATRON_HEX = re.compile(r"0[xX]([0-9a-fA-F]{1,4})")
# busca el comentario con la cantidad de muestras, por ejemplo:
#   // 26568 muestras de 16 bits, mono, 11025 Hz
PATRON_CANTIDAD = re.compile(r"//\s*(\d+)\s+muestras")


def convertirArchivo(rutaH, carpetaSalida):
    """lee un archivo .h, saca su arreglo de muestras y lo guarda como .raw"""
    texto = rutaH.read_text(encoding="utf-8", errors="replace")

    # busca el arreglo de 16 bits dentro del .h
    arreglo = PATRON_ARREGLO.search(texto)
    if arreglo is None:
        print(f"  {rutaH.name}: no tiene un arreglo uint16_t, se salta")
        return False

    nombreArreglo = arreglo.group(1)
    contenido = arreglo.group(2)

    # convierte cada numero hexadecimal en un entero de 0 a 65535
    muestras = [int(valor, 16) for valor in PATRON_HEX.findall(contenido)]
    if len(muestras) == 0:
        print(f"  {rutaH.name}: el arreglo esta vacio, se salta")
        return False

    # revisa que la cantidad de muestras coincida con el comentario del .h
    # si no coincide, probablemente el .h esta cortado o mal generado
    cantidadEsperada = PATRON_CANTIDAD.search(texto)
    if cantidadEsperada and int(cantidadEsperada.group(1)) != len(muestras):
        print(f"  ojo, {rutaH.name}: el comentario dice {cantidadEsperada.group(1)} muestras"
              f" pero el arreglo tiene {len(muestras)}")

    # el .h guarda los bits del PCM con signo tal cual (0xfff4 es -12)
    # por eso basta con escribir cada valor como 2 bytes en little-endian:
    # primero el byte bajo y despues el byte alto, igual que la pico
    datos = bytearray()
    for muestra in muestras:
        datos += muestra.to_bytes(2, "little")

    # guarda el archivo .raw con el nombre del arreglo
    rutaRaw = carpetaSalida / f"{nombreArreglo}.raw"
    rutaRaw.write_bytes(datos)

    # muestra un resumen: muestras, bytes y duracion a 11025 Hz
    duracion = len(muestras) / 11025
    print(f"  {rutaH.name} -> {rutaRaw.name}: {len(muestras)} muestras,"
          f" {len(datos)} bytes, {duracion:.2f} s")

    # FatFs acepta nombres largos, pero los de 8 letras + .raw son los mas seguros
    if len(nombreArreglo) > 8:
        print(f"  ojo, {rutaRaw.name} tiene un nombre de mas de 8 letras")
    return True


def main():
    # lee los argumentos de la linea de comandos
    argumentos = sys.argv[1:]
    entrada = Path(argumentos[0]) if len(argumentos) >= 1 else CARPETA_ENTRADA
    carpetaSalida = Path(argumentos[1]) if len(argumentos) >= 2 else CARPETA_SALIDA

    # arma la lista de archivos .h a convertir
    if entrada.is_file():
        archivos = [entrada]
    elif entrada.is_dir():
        # solo los sonidos del catalogo: Sonido seguido de un numero (Sonido0.h, Sonido1.h, ...)
        # asi se salta SonidoSistema.h, que no va en la SD
        archivos = sorted(entrada.glob("Sonido[0-9]*.h"))
    else:
        print(f"no existe: {entrada}")
        sys.exit(1)

    if len(archivos) == 0:
        print(f"no hay archivos Sonido0.h, Sonido1.h, ... en {entrada}")
        sys.exit(1)

    # crea la carpeta de salida si no existe
    carpetaSalida.mkdir(parents=True, exist_ok=True)

    print(f"convirtiendo {len(archivos)} archivo(s) a {carpetaSalida}")
    convertidos = 0
    for rutaH in archivos:
        if convertirArchivo(rutaH, carpetaSalida):
            convertidos += 1

    print(f"listo: {convertidos} archivo(s) .raw")
    print("copia los .raw a la raiz de la tarjeta SD (formateada en FAT32)")


if __name__ == "__main__":
    main()
