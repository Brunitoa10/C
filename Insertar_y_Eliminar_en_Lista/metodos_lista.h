#ifndef METODOS_LISTA_H_INCLUDED
#define METODOS_LISTA_H_INCLUDED

struct celda {
    char *palabra;
    struct celda *siguiente;
};

typedef struct {
    struct celda *primera;
} lista_t;


int lista_insertar(lista_t *lista, const char *palabra);

int lista_destruir(lista_t **lista);

#endif // METODOS_LISTA_H_INCLUDED
