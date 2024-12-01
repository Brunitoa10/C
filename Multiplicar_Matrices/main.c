#include <stdio.h>
#include <stdlib.h>

#include "Matriz.h"

int main() {
    // Caso de prueba 1: Matrices 2x3 y 3x2
    matriz_t matriz_a_1 = {
        .elementos = (double *[]){(double[]){1, 2, 3}, (double[]){4, 5, 6}} ,
        .filas = 2,
        .columnas = 3
    };

    matriz_t matriz_b_1 = {
        .elementos = (double *[]){(double[]){7, 8}, (double[]){9, 10}, (double[]){11, 12}},
        .filas = 3,
        .columnas = 2
    };

    printf("Resultado de la multiplicación 2x3 y 3x2:\n");
    matriz_t *matriz_c_1 = matriz_multiplicar(&matriz_a_1, &matriz_b_1);
    if (matriz_c_1 != NULL) {
        imprimir_matriz(matriz_c_1);
        liberar_matriz(matriz_c_1);
    }

    // Caso de prueba 2: Matrices 3x2 y 2x3
    matriz_t matriz_a_2 = {
        .elementos = (double *[]){(double[]){1, 2}, (double[]){3, 4}, (double[]){5, 6}},
        .filas = 3,
        .columnas = 2
    };

    matriz_t matriz_b_2 = {
        .elementos = (double *[]){(double[]){7, 8, 9}, (double[]){10, 11, 12}},
        .filas = 2,
        .columnas = 3
    };

    printf("\nResultado de la multiplicación 3x2 y 2x3:\n");
    matriz_t *matriz_c_2 = matriz_multiplicar(&matriz_a_2, &matriz_b_2);
    if (matriz_c_2 != NULL) {
        imprimir_matriz(matriz_c_2);
        liberar_matriz(matriz_c_2);
    }

    // Caso de prueba 3: Matrizes incompatibles (2x3 y 2x3)
    matriz_t matriz_a_3 = {
        .elementos = (double *[]){(double[]){1, 2, 3}, (double[]){4, 5, 6}},
        .filas = 2,
        .columnas = 3
    };

    matriz_t matriz_b_3 = {
        .elementos = (double *[]){(double[]){7, 8, 9}, (double[]){10, 11, 12}},
        .filas = 2,
        .columnas = 3
    };

    printf("\nIntentando multiplicar matrices incompatibles (2x3 y 2x3):\n");
    matriz_t *matriz_c_3 = matriz_multiplicar(&matriz_a_3, &matriz_b_3);
    if (matriz_c_3 != NULL) {
        imprimir_matriz(matriz_c_3);
        liberar_matriz(matriz_c_3);
    }

    return 0;
}
