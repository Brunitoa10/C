#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *nombre;
    char *descripcion;
} renglon_t;

typedef struct {
    renglon_t *renglones;
    unsigned int cantidad;
} inventario_t;

inventario_t *inventario_crear(unsigned int const cantidad);
int inventario_destruir(inventario_t **inventario);

#endif // FUNCIONES_H_INCLUDED
