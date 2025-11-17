#include <stdio.h>
#include <string.h>
int Menu();
void SaltodeLinea(char *cadena, int n);
void MostrarInventario(int *pantallas, int *baterias, int *chips, int *tarjetagrafica, int *teclados);
void RealizarPedido(char nombreproducto[5][50], int contador, int *pantallas, int *teclados,
                    int *mouses, int *baterias, int *chips, int *tarjetagrafica, int opcionproducto, int cantidadpedido, int respuestaRP);
void EditarProducto(int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica);
void BuscarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, int *baterias,
                    int *chips, int *tarjetagrafica, int contador, int respuestaBP);
void EliminarProducto (char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, 
                    int *baterias, int *chips, int *tarjetagrafica, int contador, int respuestaEliminar);
void Reabastecerstock(int *pantallas,int *teclados,int *mouses,int *tarjetagrafica,int *baterias,int *chips,int respuestaR, int opcionesR);
int main(int argc, char *argv[])
{
    int opciones, contador = 5, respuesta = 1, respuestaRP = 1, respuestaBP = 1, respuestaEliminar=1, respuestaR=1,opcionesR;
    int pantallas[5] = {400, 0, 0, 0, 0}, teclados[5] = {300, 0, 0, 0, 0}, mouses[5] = {150, 0, 0, 0, 0}, baterias[5] = {100, 0, 0, 0, 0},
        chips[5] = {300, 0, 0, 0, 0}, tarjetagrafica[5] = {80, 0, 0, 0, 0}, opcionproducto, cantidadpedido;
    char nombreproducto[5][50] = {"Laptop", "Celulares", "Tablets", "Smartwatchs", "Gafas VR"};
    while (respuesta == 1)
    {
        opciones = Menu();
        switch (opciones)
        {
        case 1:
            MostrarInventario(pantallas, baterias, chips, tarjetagrafica, teclados);
            break;
        case 2:
            RealizarPedido(nombreproducto, contador, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, opcionproducto, cantidadpedido, respuestaRP);
            break;
        case 3:
            EditarProducto(pantallas, teclados, mouses, baterias, chips, tarjetagrafica);
            break;
        default:
            printf("Opcion invalida\n");
            break;
        case 4:
            BuscarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, contador, respuestaBP);
            break;
        case 5: 
            EliminarProducto(nombreproducto, pantallas,teclados,mouses,baterias, chips, tarjetagrafica, contador, respuestaEliminar);
            break;
        case 6:
            Reabastecerstock(pantallas,teclados, mouses, baterias, chips, tarjetagrafica, respuestaR, opcionesR);
        }
        printf("Desea seguir en el programa (1)Si, (2)No\n");
        scanf("%d", &respuesta);
    }
}
int Menu()
{
    int opciones;
    printf("----------------------Menu----------------------\n");
    printf("1. Mostrar Stock\n");               // hecho
    printf("2. Ingreso de datos del pedido\n"); // hecho
    printf("3.Editar producto\n");              // hecho
    printf("4. Buscar el producto\n");             //medio echo
    printf("5. Eliminar producto\n");           //echo
    printf("6. Reabastecimiento del STOCK \n");  //echo
    printf("Seleccione una opcion:\n");
    scanf("%d", &opciones);
    fflush(stdin);
    return opciones;
}
// isalto de linea
void SaltodeLinea(char *cadena, int n)
{
    fgets(cadena, n, stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

// INVENTARIO
void MostrarInventario(int *pantallas, int *baterias, int *chips, int *tarjetagrafica, int *teclados)
{
    printf("\n=========== INVENTARIO ACTUAL ===========\n");
    printf("Pantallas: %d\n", *pantallas);
    printf("Baterías: %d\n", *baterias);
    printf("Chips: %d\n", *chips);
    printf("Tarjetas Graficas: %d\n", *tarjetagrafica);
    printf("Teclados: %d\n", *teclados);
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
        printf("Seleccione un producto (1-5): ");
        scanf("%d", &opcionproducto);

        while (opcionproducto < 1 || opcionproducto > 5)
        {
            // poner otra vez el menu
            printf("ERROR, INGRESE UNA OPCION VALIDA (1-5)\n");
            scanf("%d", &opcionproducto);
        }
        opcionproducto--;
        // validar
        printf("Ingrese la cantidad a pedir: ");
        scanf("%d", &cantidadpedido);

        int recursosSuficientes = 1;

        switch (opcionproducto)
        {
        case 1:
            if (*pantallas >= cantidadpedido && *teclados >= cantidadpedido && *mouses >= cantidadpedido &&
                *baterias >= cantidadpedido && *chips >= cantidadpedido && *tarjetagrafica >= cantidadpedido)
            {
                *pantallas -= cantidadpedido;
                *teclados -= cantidadpedido;
                *mouses -= cantidadpedido;
                *baterias -= cantidadpedido;
                *chips -= cantidadpedido;
                *tarjetagrafica -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 2:
            if (*pantallas >= cantidadpedido && *baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                *pantallas -= cantidadpedido;
                *baterias -= cantidadpedido;
                *chips -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 3:
            if (*pantallas >= cantidadpedido && *baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                *pantallas -= cantidadpedido;
                *baterias -= cantidadpedido;
                *chips -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 4:
            if (*baterias >= cantidadpedido && *chips >= cantidadpedido)
            {
                *baterias -= cantidadpedido;
                *chips -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        case 5:
            if (*pantallas >= cantidadpedido && *chips >= cantidadpedido && *tarjetagrafica >= cantidadpedido)
            {
                *pantallas -= cantidadpedido;
                *chips -= cantidadpedido;
                *tarjetagrafica -= cantidadpedido;
            }
            else
            {
                recursosSuficientes = 0;
            }
            break;

        default:
            printf("Opción inválida. Seleccione un producto valido entre 1 y 5.\n");
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
        }
        printf("Desea seleccionar otro producto (1)Si (2)No\n");
        scanf("%d", &respuestaRP);
    }
}
void EditarProducto(int *pantallas, int *teclados, int *mouses, int *baterias, int *chips, int *tarjetagrafica)
{
    int recurso;
    printf("Que recurso desea editar?\n");
    printf("1. Pantallas\n");
    printf("2. Teclados\n");
    printf("3. Mouses\n");
    printf("4. Baterías\n");
    printf("5. Chips\n");
    printf("6. Tarjetas graficas\n");
    printf("Seleccione un recurso (1-6): ");
    scanf("%d", &recurso);
    switch (recurso)
    {
    case 1:
        printf("Ingrese la nueva cantidad para pantallas: ");
        scanf("%d", pantallas);
        break;
    case 2:
        printf("Ingrese la nueva cantidad para teclados: ");
        scanf("%d", teclados);
        break;
    case 3:
        printf("Ingrese la nueva cantidad para mouses: ");
        scanf("%d", mouses);
        break;
    case 4:
        printf("Ingrese la nueva cantidad para baterias: ");
        scanf("%d", baterias);
        break;
    case 5:
        printf("Ingrese la nueva cantidad para chips: ");
        scanf("%d", chips);
        break;
    case 6:
        printf("Ingrese la nueva cantidad para tarjetas graficas: ");
        scanf("%d", tarjetagrafica);
        break;
    default:
        printf("Opción invalida.\n");
        break;
    }
    printf("Recurso editado con exito.\n");
}
void BuscarProducto(char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, int *baterias, 
                    int *chips, int *tarjetagrafica, int contador, int respuestaBP)
{
    char productoBuscar[50];
    printf("----Productos que puede buscar---------\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\n", i + 1, nombreproducto[i]);
    }

    printf("Ingrese el nombre del producto a buscar (Ponga el nombre): ");
    SaltodeLinea(productoBuscar, 50);
    int encontrado = 0;
    for (int i = 0; i < contador; i++)
    {
        int j = 0;
        // Comparar carácter por carácter
        while (nombreproducto[i][j] == productoBuscar[j] && nombreproducto[i][j] != '\0' && productoBuscar[j] != '\0')
        {
            j++;
        }

        if (nombreproducto[i][j] == '\0' && productoBuscar[j] == '\0')
        {
            printf("Producto encontrado: %s\n", nombreproducto[i]);
            printf("Pantallas: %d\n", pantallas[i]);
            printf("Teclados: %d\n", teclados[i]);
            printf("Mouses: %d\n", mouses[i]);
            printf("Baterias: %d\n", baterias[i]);
            printf("Chips: %d\n", chips[i]);
            printf("Tarjetas graficas: %d\n", tarjetagrafica[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado\n");
    }

    // Preguntar si desea buscar otro producto
    printf("Desea volver a buscar otro producto (1. Si / 2. No): \n");
    scanf("%d", &respuestaBP);

    // Validar la entrada de respuesta
    while (respuestaBP != 1 && respuestaBP != 2)
    {
        printf("Opcion invalida. Ingrese 1 para si o 2 para no: \n");
        scanf("%d", &respuestaBP);
    }
    if (respuestaBP == 1){
        
    }
}

void EliminarProducto (char nombreproducto[5][50], int *pantallas, int *teclados, int *mouses, 
                      int *baterias, int *chips, int *tarjetagrafica, int contador, int respuestaEliminar){
    int opcionx;
    printf("----Productos disponibles para eliminar----\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\n", i + 1, nombreproducto[i]);
    }
    printf("Seleccione el producto que desea eliminar (1-5): ");
    scanf("%d", &opcionx);
    opcionx--;
    if (opcionx < 0 || opcionx >= contador)
    {
        printf("Opción invalida.\n");
        return;
    }
    //funcion que elimina el producto con el caracter nulo 
    nombreproducto[opcionx][0] = '\0';  // Limpiar el nombre del producto, poniendo el primer carácter como nulo ('\0')
    pantallas[opcionx] = 0;
    teclados[opcionx] = 0;
    mouses[opcionx] = 0;
    baterias[opcionx] = 0;
    chips[opcionx] = 0;
    tarjetagrafica[opcionx] = 0;
    printf("Producto %s eliminado con exito.\n", nombreproducto[opcionx]);
    //para que vuelva a preguntar si desea eliminar o no xDDDD
    printf("Desea eliminar otro producto (1. Si / 2. No): ");
    scanf("%d", &respuestaEliminar);

    while (respuestaEliminar != 1 && respuestaEliminar != 2)
    {
        printf("Opción invalida. Ingrese 1 para si o 2 para no: ");
        scanf("%d", &respuestaEliminar);
    }
    if (respuestaEliminar == 1)
    {
        EliminarProducto(nombreproducto, pantallas, teclados, mouses, baterias, chips, tarjetagrafica, contador, respuestaEliminar);
    }
}
//Funcion 4
void Reabastecerstock(int *pantallas,int *teclados,int *mouses,int *tarjetagrafica,int *baterias,int *chips,int respuestaR, int opcionesR){
    int cantidadPantallas, cantidadTeclados, cantidadMouses, cantidadTarjeta, cantidadBaterias, cantidadChips;
    while (respuestaR==1){
        printf("Seleccione que desea reabastecer:\n");
        printf("1. Pantallas\n2. Teclados\n3. Mouses\n4. Tarjetas gráficas\n5. Baterías\n6. Chips\n");
        scanf("%d",&opcionesR);
        switch (opcionesR){
        case 1:
            printf("Ingrese la cantidad de pantallas que desea agregar: \n");
            scanf("%d",&cantidadPantallas);
            *pantallas += cantidadPantallas;
            break;
        case 2:
            printf("Ingrese la cantidad de teclados que desea agregar: \n");
            scanf("%d",&cantidadTeclados);  
            *teclados += cantidadTeclados;
            break;
        case 3:
            printf("Ingrese la cantidad de mouses que desea agregar: \n");
            scanf("%d",&cantidadMouses);
            *mouses += cantidadMouses;  
            break;
        case 4:
            printf("Ingrese la cantidad de tarjetas graficas que desea agregar: \n");
            scanf("%d",&cantidadTarjeta);
            *tarjetagrafica += cantidadTarjeta;
            break;
        case 5:
            printf("Ingrese la cantidad de baterias que desea agregar: \n");  
            scanf("%d",&cantidadBaterias);
            *baterias += cantidadBaterias;
            break;
        case 6:
            printf("Ingrese la cantidad de chips que desea agregar: \n"); 
            scanf("%d",&cantidadChips);
            *chips += cantidadChips;
            break;
                                
        default:
            printf("Opcion invalida\n");
            break;
        }
        printf("Desea reabastecer otro producto? 1.Si 2.No: \n");
        scanf("%d",&respuestaR);
    }  
}