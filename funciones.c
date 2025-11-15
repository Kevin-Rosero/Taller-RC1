#include <stdio.h>
#include <string.h>
#include "funciones.h"







int buscarProducto(char nombres[][MAX_NOMBRE], int cont, char buscado[]) {
    for (int i = 0; i < cont; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            return i; // posicion/producto encontrado
        }
    }
    return -1; // no encontrado
}
