#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double **elementos;
    unsigned int filas;
    unsigned int columnas;
} matriz_t;

double multi_elemento(matriz_t *matriz_a,matriz_t *matriz_b, unsigned int i, unsigned int j){
    if(matriz_a == NULL || matriz_b == NULL){
        return -1;
    }
    if(matriz_a->columnas != matriz_b->filas){
        return 0.0;
    }
    double result = 0.0;
    for(int pos = 0; pos < matriz_a->filas; pos++){
        result += matriz_a->elementos[i][pos] * matriz_b->elementos[pos][j];
    }
    return result;
}

matriz t *matriz_multiplicar(matriz_t *matriz_a, matriz_t *matriz_b){
    if(matriz_a == NULL || matriz_b == NULL){
        return NULL;
    }
    matriz_t *nuevaMatriz = (matriz_t *)malloc(sizeof(matriz_t));
    if(nuevaMatriz == NULL){
        return NULL;
    }
    nuevaMatriz->filas = matriz_a->filas;
    nuevaMatriz->columnas = matriz_b->columnas;
    nuevaMatriz->elementos = malloc(matriz_a->filas*matriz_b->columnas*sizeof(double));

    if(nuevaMatriz->elementos == NULL){
        free(nuevaMatriz);
        return NULL;
    }

    for(int fila = 0; fila<matriz_a->filas;filas++){
        for(int columna = 0; columna<matriz_b->columnas;columna++){
            nuevaMatriz->elementos[fila][columna] = multi_elemento(matriz_a,matriz_b,fila,columna);
        }
    }

    return nuevaMatriz;
}

int main(){
    printf("Hello world!\n");
    return 0;
}
