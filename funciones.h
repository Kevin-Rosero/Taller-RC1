// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 10
#define MAX_NOMBRE 20

// Prototipos
void ingresarProducto(char nombres[][MAX_NOMBRE], float tiempos[], int recursos[], int cantidades[], int *cont);

int buscarProducto(char nombres[][MAX_NOMBRE], int cont, char buscado[]);

void editarProducto(char nombres[][MAX_NOMBRE], float tiempos[], int recursos[], int cantidades[], int cont);

void eliminarProducto(char nombres[][MAX_NOMBRE], float tiempos[], int recursos[], int cantidades[], int *cont);

float calcularTiempoTotal(float tiempos[], int cantidades[], int cont);

int calcularRecursosTotales(int recursos[], int cantidades[], int cont);

int verificarCapacidad(float tiempoTotal, float tiempoDisponible, int recursosTotales, int recursosDisponibles);

#endif
