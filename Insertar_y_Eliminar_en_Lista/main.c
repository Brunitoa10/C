#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos_lista.h"

// Función para imprimir la lista (para probar)
void lista_imprimir(const lista_t *lista) {
    struct celda *actual = lista->primera;
    while (actual != NULL) {
        printf("%s\n", actual->palabra);
        actual = actual->siguiente;
    }
}

int main() {
    lista_t *lista = malloc(sizeof(lista_t));
    lista->primera = NULL;

    lista_insertar(lista, "Hola");
    lista_insertar(lista, "Mundo");
    lista_insertar(lista, "C");


    printf("Lista antes de destruir:\n");
    lista_imprimir(lista);


    lista_destruir(&lista);


    if (lista == NULL) {
        printf("\nLista destruida correctamente.\n");
    } else {
        printf("\nError al destruir la lista.\n");
    }

    return 0;
}
