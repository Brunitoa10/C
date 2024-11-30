#ifndef MATRIZ_H_H_INCLUDED
#define MATRIZ_H_H_INCLUDED


typedef struct {
    double **elementos;
    unsigned int filas;
    unsigned int columnas;
} matriz_t;

// Funciones básicas para trabajar con matrices
matriz_t* crear_matriz(unsigned int filas, unsigned int columnas);
void liberar_matriz(matriz_t *matriz);
void imprimir_matriz(matriz_t *matriz);

#endif // MATRIZ_H_H_INCLUDED
