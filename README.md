                                Enunciado

Para multiplicar dos matrices A de tama ̃no m × n por una matriz B de tamano n × p, se
calcula una nueva matriz C de tama ̃no m × p. En esta nueva matriz, cada elemento ci,j ,
en la fila i, columna j, est ́a determinado por ci,j = ai,1 × b1,j + ai,2 × b2,j + · · · + ai,k × bk,j
donde ai,j son los elementos de la matriz A y bi,j son los elementos de la matriz B, con 1 ≤ i ≤ m, 1 ≤ j ≤ p, 1 ≤ k ≤ n
Dada una estructura de datos

typedef struct {
  double **elementos;
  unsigned int filas;
  unsigned int columnas;
} matriz_t;

donde para una variable matriz t *matriz, el elemento mi,j es accedido como matriz->elementos[i][j]
donde i tiene un n ́umero desde 0 hasta filas - 1, j es un valor entero desde 0 hasta
columnas - 1, con las variables filas y columnas designando la cantidad de filas y
columnas de la matriz.

a) Implemente en lenguaje C una funcion
double multi_elemento(matriz_t *matriz_a,matriz_t *matriz_b, unsigned int i, unsigned int j)
que tomando como par ́ametro dos matrices matriz t * a y matriz t *b, la fila i
y la columna j, retorne como resultado el t ́ermino ci,j de la matriz C que resultar ́ıa
de multiplicar A × B.

b) Implemente en lenguaje C una funcion
matriz t *matriz multiplicar(matriz t *matriz a, matriz t *matriz b)
que retorne un puntero a una nueva matriz con el resultado de multiplicar las matrices matriz a y matriz b.
Puede utilizar la funcion implementada en el punto anterior para calcular cada termino.
