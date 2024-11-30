#include "Operaciones_matriz.h"
#include <stdio.h>

double producto(double a, double b) {
    return a * b;
}

double multi_elemento(matriz_t *matriz_a, matriz_t *matriz_b, unsigned int i, unsigned int j, Operacion operacion) {
    double resultado = 0.0;
    for (unsigned int pos = 0; pos < matriz_a->columnas; pos++) {
        resultado += operacion(matriz_a->elementos[i][pos], matriz_b->elementos[pos][j]);
    }
    return resultado;
}

int verificarDimensionMatriz(matriz_t *matriz_a, matriz_t *matriz_b) {
    return (matriz_a->columnas != matriz_b->filas) ? 0 : 1;
}

matriz_t* matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b, Operacion operacion) {
    if (!verificarDimensionMatriz(matriz_a, matriz_b)) {
        fprintf(stderr, "Error: Dimensiones incompatibles para multiplicación.\n");
        return NULL;
    }

    matriz_t *matriz_resultante = crear_matriz(matriz_a->filas, matriz_b->columnas);
    if (!checkNull(matriz_resultante)) {
        return NULL;
    }

    for (unsigned int i = 0; i < matriz_resultante->filas; i++) {
        for (unsigned int j = 0; j < matriz_resultante->columnas; j++) {
            matriz_resultante->elementos[i][j] = multi_elemento(matriz_a, matriz_b, i, j, operacion);
        }
    }

    return matriz_resultante;
}
