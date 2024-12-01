#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Estructura de la matriz
typedef struct {
    double **elementos;
    unsigned int filas;
    unsigned int columnas;
} matriz_t;

// Funciones genéricas
matriz_t* crear_matriz(unsigned int filas, unsigned int columnas);
void liberar_matriz(matriz_t *matriz);
void imprimir_matriz(matriz_t *matriz);

// Funciones auxiliares
int checkNull(void *ptr);
double** reservar_memoria_elementos(unsigned int filas, unsigned int columnas);

// Funciones específicas de operación
double producto(double a, double b);
double multi_elemento(matriz_t *matriz_a, matriz_t *matriz_b, unsigned int i, unsigned int j);
int verificarDimensionMatriz(matriz_t *matriz_a, matriz_t *matriz_b);
matriz_t* matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b);

#endif // MATRIZ_H_INCLUDED
