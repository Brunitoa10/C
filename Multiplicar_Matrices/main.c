#include <stdio.h>
#include <stdlib.h>



typedef struct {
    double **elementos;
    unsigned int filas;
    unsigned int columnas;
} matriz_t;

int checkNull(void *ptr){
    return (ptr==NULL) ? 0 : 1;
}

/*Metodos genericos de matrices crear, liberar e imprimir*/
matriz_t* crear_matriz(unsigned int filas, unsigned int columnas) {
    matriz_t *matriz = (matriz_t *)malloc(sizeof(matriz_t));
    if (!checkNull(matriz)) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la matriz.\n");
        return NULL;
    }

    matriz->filas = filas;
    matriz->columnas = columnas;
    matriz->elementos = (double **)malloc(filas * sizeof(double *));

    if (!checkNull(matriz->elementos)) {
        fprintf(stderr, "Error: No se pudo asignar memoria para las filas.\n");
        free(matriz);
        return NULL;
    }

    for (unsigned int i = 0; i < filas; i++) {
        matriz->elementos[i] = (double *)malloc(columnas * sizeof(double));
        if (!checkNull(matriz->elementos[i])) {
            fprintf(stderr, "Error: No se pudo asignar memoria para las columnas.\n");
            for (unsigned int j = 0; j < i; j++) {
                free(matriz->elementos[j]);
            }
            free(matriz->elementos);
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}


void liberar_matriz(matriz_t *matriz) {
    for (unsigned int i = 0; i < matriz->filas; i++) {
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
    free(matriz);
}


void imprimir_matriz(matriz_t *matriz) {
    for (unsigned int i = 0; i < matriz->filas; i++) {
        for (unsigned int j = 0; j < matriz->columnas; j++) {
            printf("%.2f ", matriz->elementos[i][j]);
        }
        printf("\n");
    }
}

/*Desarrollo Ejercicio A*/

typedef double (*Operacion)(double, double);


double producto(double a, double b) {
    return a * b;
}


// Calcula el valor de un elemento de la matriz resultante
double multi_elemento(matriz_t *matriz_a, matriz_t *matriz_b, unsigned int i, unsigned int j, Operacion operacion) {
    double resultado = 0.0;
    for (unsigned int pos = 0; pos < matriz_a->columnas; pos++) {
        resultado += operacion(matriz_a->elementos[i][pos], matriz_b->elementos[pos][j]);
    }
    return resultado;
}

/*Desarrollo Ejercicio B*/

int verificarDimensionMatriz(matriz_t *matriz_a, matriz_t *matriz_b){
    return (matriz_a->columnas != matriz_b->filas) ? 0 : 1;
}

// Multiplica dos matrices y devuelve la matriz resultante
matriz_t* matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b, Operacion operacion) {

    if (!verificarDimensionMatriz(matriz_a, matriz_b)) {
        fprintf(stderr, "Error: Dimensiones incompatibles para multiplicación.\n");
        return NULL;
    }

    matriz_t *matriz_resultante = crear_matriz(matriz_a->filas, matriz_b->columnas);
    if (!checkNull(matriz_resultante)){
        return NULL;
    }

    // Multiplicar las matrices elemento por elemento
    for (unsigned int i = 0; i < matriz_resultante->filas; i++) {
        for (unsigned int j = 0; j < matriz_resultante->columnas; j++) {
            matriz_resultante->elementos[i][j] = multi_elemento(matriz_a, matriz_b, i, j, operacion);
        }
    }

    return matriz_resultante;
}

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
    matriz_t *matriz_c_1 = matriz_multiplicar(&matriz_a_1, &matriz_b_1, producto);
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
    matriz_t *matriz_c_2 = matriz_multiplicar(&matriz_a_2, &matriz_b_2, producto);
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
    matriz_t *matriz_c_3 = matriz_multiplicar(&matriz_a_3, &matriz_b_3, producto);
    if (matriz_c_3 != NULL) {
        imprimir_matriz(matriz_c_3);
        liberar_matriz(matriz_c_3);
    }

    return 0;
}
