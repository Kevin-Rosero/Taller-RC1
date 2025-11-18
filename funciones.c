#include <stdio.h>
#include <string.h>
#include "funciones.h"
int Menu()
{
    int opciones;
    printf("----------------------Menu----------------------\n");
    printf("1. Mostrar Stock\n");               // hecho
    printf("2. Ingreso de datos del pedido\n"); // hecho
    printf("3.Editar producto\n");              // hecho
    printf("4. Buscar el producto\n");          // medio echo
    printf("5. Eliminar producto\n");           // echo
    printf("6. Reabastecimiento del STOCK \n"); // echo
    printf("7. Agregar prodcuto\n");
    printf("Seleccione una opcion:\n");
    scanf("%d", &opciones);
    fflush(stdin);
    return opciones;
}
// salto de linea
void SaltodeLinea(char *cadena, int n)
{
    fgets(cadena, n, stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

// INVENTARIO
void MostrarInventario(int *pantallas, int *baterias, int *chips, int *tarjetagrafica, int *teclados, int *mouses)
{
    printf("=========== INVENTARIO ACTUAL ===========\n");
    printf("Pantallas: %d\n", *pantallas);
    printf("Baterias: %d\n", *baterias);
    printf("Chips: %d\n", *chips);
    printf("Tarjetas Graficas: %d\n", *tarjetagrafica);
    printf("Teclados: %d\n", *teclados);
    printf("Mouses:%d\n", *mouses);
}

void RealizarPedido(char nombreproducto[5][50], int contador, int *pantallas, int *teclados,
                    int *mouses, int *baterias, int *chips, int *tarjetagrafica, int opcionproducto, int cantidadpedido, int respuestaRP)
{
    printf("Seleccione el producto que desea pedir:\n");

    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\n", i + 1, nombreproducto[i]);
    }

    while (respuestaRP == 1)
    {
        printf("Seleccione un producto (1-%d): ", contador);
        scanf("%d", &opcionproducto);

        while (opcionproducto < 1 || opcionproducto > contador)
        {
            printf("ERROR, INGRESE UNA OPCION VALIDA (1-%d)\n", contador);
            scanf("%d", &opcionproducto);
        }

        opcionproducto--;

        printf("Ingrese la cantidad a pedir: ");
        scanf("%d", &cantidadpedido);

        while (cantidadpedido <= 0)
        {
            printf("Ingrese una cantidad valida (mayor que 0): ");
            scanf("%d", &cantidadpedido);
        }

        int recursosSuficientes = 1;

        switch (opcionproducto)
        {
        case 0: // Producto 1 (Laptop)
            if (*pantallas >= cantidadpedido && *teclados >= cantidadpedido && *mouses >= cantidadpedido &&
                *baterias >= cantidadpedido && *chips >= cantidadpedido && *tarjetagrafica >= cantidadpedido)
            {
                pantallas[opcionproducto] -= cantidadpedido;
                teclados[opcionproducto] -= cantidadpedido;
                mouses[opcionproducto] -= cantidadpedido;
                baterias[opcionproducto] -= cantidadpedido;
                chips[opcionproducto] -= cantidadpedido;
                tarjetagrafica[opcionproducto] -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 1: // Producto 2 (Celulares)
            if (*pantallas >= cantidadpedido && *baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                pantallas[opcionproducto] -= cantidadpedido;
                baterias[opcionproducto] -= cantidadpedido;
                chips[opcionproducto] -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 2: // Producto 3 (Tablets)
            if (*pantallas >= cantidadpedido && *baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                pantallas[opcionproducto] -= cantidadpedido;
                baterias[opcionproducto] -= cantidadpedido;
                chips[opcionproducto] -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 3: // Producto 4 (Smartwatches)
            if (*baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                baterias[opcionproducto] -= cantidadpedido;
                chips[opcionproducto] -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 4: // Producto 5 (Gafas VR)
            if (*pantallas >= cantidadpedido && *chips >= cantidadpedido && *tarjetagrafica >= cantidadpedido)
            {
                pantallas[opcionproducto] -= cantidadpedido;
                chips[opcionproducto] -= cantidadpedido;
                tarjetagrafica[opcionproducto] -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        default:
            printf("Opción invalida. Seleccione un producto valido entre 1 y %d.\n", contador);
            recursosSuficientes = 0;
            break;
        }
        if (recursosSuficientes)
        {
            printf("Pedido realizado con exito. Tiempo total de fabricacion: %d minutos.\n", cantidadpedido * 10);
        }
        else
        {
            printf("No hay suficientes recursos para realizar el pedido.\n");
            break;
        }

        printf("Desea seleccionar otro producto (1)Si (2)No\n");
        scanf("%d", &respuestaRP);
        if (respuestaRP != 1)
        {
            break;
        }
    }
}
void EditarProducto(int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica, int respuestaEP)
{
    int recurso;
    printf("Que recurso desea editar?\n");
    printf("1. Pantallas\n");
    printf("2. chips\n");
    printf("3. Tarjetas graficas\n");
    printf("4. Baterias\n");
    printf("5. Teclados\n");
    printf("6. Mouses\n");
    printf("Seleccione un recurso (1-6): ");
    scanf("%d", &recurso);
    while (respuestaEP == 1)
    {
        switch (recurso)
        {
        case 1:
            printf("Ingrese la nueva cantidad para pantallas: ");
            scanf("%d", pantallas);
            while (*pantallas < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", pantallas);
            }
            printf("Recurso editado con exito.\n");
            break;
        case 2:
            printf("Ingrese la nueva cantidad para chips: ");
            scanf("%d", chips);

            while (*chips < 0)
            {
                printf("Ingrese un valor valido:\n");
                scanf("%d", chips);
            }
            printf("Recurso editado con exito.\n");

            break;
        case 3:
            printf("Ingrese la nueva cantidad para tarjetas graficas: ");
            scanf("%d", tarjetagrafica);
            while (*tarjetagrafica < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", tarjetagrafica);
            }
            printf("Recurso editado con exito.\n");
            break;
        case 4:
            printf("Ingrese la nueva cantidad para baterias: ");
            scanf("%d", baterias);

            while (*baterias < 0)
            {
                printf("Ingrese un valor valido:\n");
                scanf("%d", baterias);
            }
            printf("Recurso editado con exito.\n");
            break;
        case 5:
            printf("Ingrese la nueva cantidad para teclados: ");
            scanf("%d", teclados);

            while (*teclados < 0)
            {
                printf("Ingrese un valor valido:\n");
                scanf("%d", teclados);
            }
            printf("Recurso editado con exito.\n");

            break;
        case 6:
            printf("Ingrese la nueva cantidad para mouses: ");
            scanf("%d", mouses);

            while (*mouses < 0)
            {
                printf("Ingrese un valor valido:\n");
                scanf("%d", mouses);
            }
            printf("Recurso editado con exito.\n");

            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        printf("Desea editar otro producto 1. Si  2. No \n");
        scanf("%d", &respuestaEP);
        if (respuestaEP == 1)
        {
            printf("Que recurso desea editar?\n");
            printf("1. Pantallas\n");
            printf("2. chips\n");
            printf("3. Tarjetas graficas\n");
            printf("4. Baterias\n");
            printf("5. Teclados\n");
            printf("6. Mouses\n");
            printf("Seleccione un recurso (1-6): ");
            scanf("%d", &recurso);
        }
        else
        {
            break;
        }
    }
}
int BuscarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica, int contador)
{
    char productoBuscar[50];
    printf("------------------------Productos que puede buscar----------------------------------\n");
    // Mostrar los productos disponibles
    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\n", i + 1, nombreproducto[i]);
    }

    printf("Ingrese el nombre del producto a buscar(Ponga el nombre): ");
    SaltodeLinea(productoBuscar, 50);

    // Buscar el producto en el inventario
    for (int i = 0; i < contador; i++)
    {
        int j = 0;
        while (nombreproducto[i][j] == productoBuscar[j] && nombreproducto[i][j] != '\0' && productoBuscar[j] != '\0')
        {
            j++;
        }

        if (nombreproducto[i][j] == '\0' && productoBuscar[j] == '\0')
        {
            // El producto fue encontrado
            printf("Producto encontrado: %s\n", nombreproducto[i]);
            printf("Pantallas: %d\n", pantallas[i]);
            printf("Teclados: %d\n", teclados[i]);
            printf("Mouses: %d\n", mouses[i]);
            printf("Baterias: %d\n", baterias[i]);
            printf("Chips: %d\n", chips[i]);
            printf("Tarjetas graficas: %d\n", tarjetagrafica[i]);
            return 0;
        }
    }

    printf("Producto no encontrado\n");
    return -1;
}
void EliminarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses,
                      int *baterias, int *chips, int *tarjetagrafica, int *contador, int respuestaEliminar)
{
    int opcionx;
    printf("----Productos disponibles para eliminar----\n");
    for (int i = 0; i < *contador; i++)
    {
        printf("%d\t%s\n", i + 1, nombreproducto[i]);
    }
    printf("Seleccione el producto que desea eliminar (1-%d): ", *contador);
    scanf("%d", &opcionx);
    opcionx--;

    if (opcionx < 0 || opcionx >= *contador)
    {
        printf("Opción invalida.\n");
        return;
    }

    for (int i = opcionx; i < *contador - 1; i++)
    {
        // Desplazamos el nombre del producto
        for (int j = 0; j < 50; j++)
        {
            nombreproducto[i][j] = nombreproducto[i + 1][j];
            if (nombreproducto[i + 1][j] == '\0')
            {
                break;
            }
        }
        pantallas[i] = pantallas[i + 1];
        teclados[i] = teclados[i + 1];
        mouses[i] = mouses[i + 1];
        baterias[i] = baterias[i + 1];
        chips[i] = chips[i + 1];
        tarjetagrafica[i] = tarjetagrafica[i + 1];
    }
    for (int j = 0; j < 50; j++)
    {
        nombreproducto[*contador - 1][j] = '\0';
    }
    pantallas[*contador - 1] = 0;
    teclados[*contador - 1] = 0;
    mouses[*contador - 1] = 0;
    baterias[*contador - 1] = 0;
    chips[*contador - 1] = 0;
    tarjetagrafica[*contador - 1] = 0;
    (*contador)--;
    printf("Producto eliminado con exito.\n");
    printf("Desea eliminar otro producto (1. Si / 2. No): ");
    scanf("%d", &respuestaEliminar);

    while (respuestaEliminar != 1 && respuestaEliminar != 2)
    {
        printf("Opción invalida. Ingrese 1 para sí o 2 para no: ");
        scanf("%d", &respuestaEliminar);
    }

    if (respuestaEliminar == 1)
    {
        EliminarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, contador, respuestaEliminar);
    }
}
// Funcion 4
void Reabastecerstock(int *pantallas, int *teclados, int *mouses, int *tarjetagrafica, int *baterias, int *chips, int respuestaR, int opcionesR)
{
    int cantidadPantallas, cantidadTeclados, cantidadMouses, cantidadTarjeta, cantidadBaterias, cantidadChips;
    while (respuestaR == 1)
    {
        printf("1. Pantallas: %d\n", *pantallas);
        printf("2.Baterias: %d\n", *baterias);
        printf("3.Chips:%d\n", *chips);
        printf("4. Tarjetas Graficas: %d\n", *tarjetagrafica);
        printf("5. Teclados: %d\n", *teclados);
        printf("6. Mouses: %d\n", *mouses);
        printf("Seleccione que desea reabastecer:\n");
        scanf("%d", &opcionesR);
        switch (opcionesR)
        {
        case 1:
            printf("Ingrese la cantidad de pantallas que desea agregar: \n");
            scanf("%d", &cantidadPantallas);
            while (cantidadPantallas < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadPantallas);
            }
            *pantallas += cantidadPantallas;
            break;
        case 2:
            printf("Ingrese la cantidad de baterias que desea agregar: \n");
            scanf("%d", &cantidadBaterias);
            while (cantidadBaterias < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadBaterias);
            }
            *baterias += cantidadBaterias;
            break;
        case 3:
            printf("Ingrese la cantidad de chips que desea agregar: \n");
            scanf("%d", &cantidadChips);
            while (cantidadChips < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadChips);
            }
            *chips += cantidadChips;
            break;
        case 4:
            printf("Ingrese la cantidad de tarjetas graficas que desea agregar: \n");
            scanf("%d", &cantidadTarjeta);
            while (cantidadTarjeta < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadTarjeta);
            }
            *tarjetagrafica += cantidadTarjeta;
            break;
        case 5:
            printf("Ingrese la cantidad de teclados que desea agregar: \n");
            scanf("%d", &cantidadTeclados);
            while (cantidadTeclados < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadTeclados);
            }
            *teclados += cantidadTeclados;

            break;
        case 6:
            printf("Ingrese la cantidad de mouses que desea agregar: \n");
            scanf("%d", &cantidadMouses);
            while (cantidadMouses < 0)
            {
                printf("Ingrese un valor valido\n");
                scanf("%d", &cantidadMouses);
            }
            *mouses += cantidadMouses;
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
        printf("Desea reabastecer otro producto? 1.Si 2.No: \n");
        scanf("%d", &respuestaR);
    }
}
// FUNCION 7
void AgregarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses,
                     int *baterias, int *chips, int *tarjetagrafica, int *contador)
{
    char nuevoProducto[50];
    int nuevaPantalla, nuevoTeclado, nuevoMouse, nuevaBateria, nuevoChip, nuevaTarjeta;
    printf("Ingrese el nombre del nuevo producto: ");
    SaltodeLinea(nuevoProducto, 50);
    int productoExistente = -1;
    for (int i = 0; i < *contador; i++)
    {
        if (strcmp(nombreproducto[i], nuevoProducto) == 0)
        {
            productoExistente = i;
            break;
        }
    }
    if (productoExistente != -1)
    {
        printf("El producto ya existe. Ingrese la cantidad adicional para %s: ", nuevoProducto);
        scanf("%d", &nuevaPantalla);

        pantallas[productoExistente] += nuevaPantalla;
        printf("Se ha agregado %d unidades al stock de %s.\n", nuevaPantalla, nuevoProducto);
    }
    else
    {
        if (*contador < 5)
        {
            printf("Ingrese la cantidad de pantallas para %s: ", nuevoProducto);
            scanf("%d", &nuevaPantalla);
            printf("Ingrese la cantidad de teclados para %s: ", nuevoProducto);
            scanf("%d", &nuevoTeclado);
            printf("Ingrese la cantidad de mouses para %s: ", nuevoProducto);
            scanf("%d", &nuevoMouse);
            printf("Ingrese la cantidad de baterías para %s: ", nuevoProducto);
            scanf("%d", &nuevaBateria);
            printf("Ingrese la cantidad de chips para %s: ", nuevoProducto);
            scanf("%d", &nuevoChip);
            printf("Ingrese la cantidad de tarjetas gráficas para %s: ", nuevoProducto);
            scanf("%d", &nuevaTarjeta);

            // Agregar el nuevo producto al inventario
            for (int i = 0; i < 50; i++) // Copiar el nombre manualmente
            {
                nombreproducto[*contador][i] = nuevoProducto[i];
                if (nuevoProducto[i] == '\0')
                {
                    break;
                }
            }

            pantallas[*contador] = nuevaPantalla;
            teclados[*contador] = nuevoTeclado;
            mouses[*contador] = nuevoMouse;
            baterias[*contador] = nuevaBateria;
            chips[*contador] = nuevoChip;
            tarjetagrafica[*contador] = nuevaTarjeta;

            (*contador)++;
            printf("Producto agregado exitosamente!\n");
        }
        else
        {
            printf("No hay espacio para agregar más productos. El inventario está lleno.\n");
        }
    }
}