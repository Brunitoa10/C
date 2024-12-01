#include "Matriz.h"

int checkNull(void *ptr) {
    return (ptr == NULL) ? 0 : 1;
}

double** reservar_memoria_elementos(unsigned int filas, unsigned int columnas) {
    double **elementos = (double **)malloc(filas * sizeof(double *));
    if (elementos == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < filas; i++) {
        elementos[i] = (double *)malloc(columnas * sizeof(double));
        if (elementos[i] == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free(elementos[j]);
            }
            free(elementos);
            return NULL;
        }
    }

    return elementos;
}

void liberar_matriz(matriz_t *matriz) {
    for (unsigned int i = 0; i < matriz->filas; i++) {
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
    free(matriz);
}

matriz_t* crear_matriz(unsigned int filas, unsigned int columnas) {
    matriz_t *matriz = (matriz_t *)malloc(sizeof(matriz_t));
    if (!checkNull(matriz)) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la matriz.\n");
        return NULL;
    }

    matriz->filas = filas;
    matriz->columnas = columnas;
    matriz->elementos = reservar_memoria_elementos(filas, columnas);
    if (!checkNull(matriz->elementos)) {
        fprintf(stderr, "Error: No se pudo asignar memoria para las filas.\n");
        free(matriz);
        return NULL;
    }

    return matriz;
}

void imprimir_matriz(matriz_t *matriz) {
    for (unsigned int i = 0; i < matriz->filas; i++) {
        for (unsigned int j = 0; j < matriz->columnas; j++) {
            printf("%.2f ", matriz->elementos[i][j]);
        }
        printf("\n");
    }
}

double producto(double a, double b) {
    return a * b;
}

double multi_elemento(matriz_t *matriz_a, matriz_t *matriz_b, unsigned int i, unsigned int j) {
    double resultado = 0.0;
    for (unsigned int pos = 0; pos < matriz_a->columnas; pos++) {
        resultado += producto(matriz_a->elementos[i][pos], matriz_b->elementos[pos][j]);
    }
    return resultado;
}

int verificarDimensionMatriz(matriz_t *matriz_a, matriz_t *matriz_b) {
    return (matriz_a->columnas != matriz_b->filas) ? 0 : 1;
}

matriz_t* matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b) {
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
            matriz_resultante->elementos[i][j] = multi_elemento(matriz_a, matriz_b, i, j);
        }
    }

    return matriz_resultante;
}
