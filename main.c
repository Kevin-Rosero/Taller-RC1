#include <stdio.h>
#include <string.h>
#include "funciones.h"
int main(int argc, char *argv[])
{
    int opciones, contador = 5, respuesta = 1, respuestaRP = 1, respuestaBP = 1, respuestaEliminar = 1, respuestaR = 1, opcionesR, respuestaEP=1;
    int pantallas[5] = {400, 400, 400, 400, 400}, teclados[5] = {300, 300, 300, 300, 300}, mouses[5] = {150, 150, 150, 150, 150}, baterias[5] = {100, 100, 100, 100, 100},
        chips[5] = {300, 300, 300, 300, 300}, tarjetagrafica[5] = {80, 80, 80, 80, 80}, opcionproducto, cantidadpedido;
    char nombreproducto[5][50] = {"Laptop", "Celulares", "Tablets", "Smartwatchs", "Gafas VR"};
    while (respuesta == 1)
    {
        opciones = Menu();
        switch (opciones)
        {
        case 1:
            MostrarInventario(pantallas, baterias, chips, tarjetagrafica, teclados, mouses);
            break;
        case 2:
            RealizarPedido(nombreproducto, contador, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, opcionproducto, cantidadpedido, respuestaRP);
            break;
        case 3:
            EditarProducto(pantallas, teclados, mouses, baterias, chips, tarjetagrafica,respuestaEP);
            break;
        case 4:
            BuscarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, contador);
            break;
        case 5:
            EliminarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, &contador, respuestaEliminar);
            break;
        case 6:
            Reabastecerstock(pantallas,teclados, mouses,tarjetagrafica,baterias,chips,respuestaR, opcionesR);
            break;
        case 7:
            AgregarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, &contador);
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        printf("Desea seguir en el programa (1)Si, (2)No\n");
        scanf("%d", &respuesta);
    }
}
