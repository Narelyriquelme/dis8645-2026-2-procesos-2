#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    while (true) {
        // Tu código aquí
        sleep_ms(10);
    }
    return 0;
}