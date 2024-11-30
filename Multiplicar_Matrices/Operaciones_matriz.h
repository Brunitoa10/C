#ifndef OPERACIONES_MATRIZ_H_INCLUDED
#define OPERACIONES_MATRIZ_H_INCLUDED

#include "Matriz.h"

// Definición de tipo para operaciones entre elementos
typedef double (*Operacion)(double, double);

// Operaciones entre elementos
double producto(double a, double b);

// Función para calcular un elemento de la matriz resultante
double multi_elemento(matriz_t *matriz_a, matriz_t *matriz_b, unsigned int i, unsigned int j, Operacion operacion);

// Multiplicación de matrices
int verificarDimensionMatriz(matriz_t *matriz_a, matriz_t *matriz_b);
matriz_t* matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b, Operacion operacion);

#endif // OPERACIONES_MATRIZ_H_INCLUDED
