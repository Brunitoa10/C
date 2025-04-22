#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de estructuras
typedef struct celda {
    char *palabra;
    struct celda *siguiente;
}celda_t;

typedef struct {
    celda_t *primera;
} lista_t;

// A) Insertar palabra al comienzo de la lista
int lista_insertar(lista_t *lista, const char *palabra) {
    if (lista == NULL || palabra == NULL) {
        return -1;
    }

    struct celda *nuevaCelda = malloc(sizeof(struct celda));
    if (nuevaCelda == NULL) {
        return -1;
    }

    nuevaCelda->palabra = malloc(strlen(palabra) + 1);
    if (nuevaCelda->palabra == NULL) {
        free(nuevaCelda);
        return -1;
    }

    strcpy(nuevaCelda->palabra, palabra);
    nuevaCelda->siguiente = lista->primera;
    lista->primera = nuevaCelda;

    return 0;
}

// B) Liberar toda la memoria asociada a la lista
int lista_destruir(lista_t **lista) {
    if (lista == NULL || *lista == NULL) {
        return -1;
    }

    struct celda *actual = (*lista)->primera;
    while (actual != NULL) {
        struct celda *temp = actual;
        actual = actual->siguiente;
        free(temp->palabra);
        free(temp);
    }

    free(*lista);
    *lista = NULL;

    return 0;
}

// Función para imprimir la lista (para debug/testing)
void lista_imprimir(const lista_t *lista) {
    if (lista == NULL) {
        return;
    }

    struct celda *actual = lista->primera;
    while (actual != NULL) {
        printf("%s\n", actual->palabra);
        actual = actual->siguiente;
    }
}

// Programa principal
int main() {
    lista_t *lista = malloc(sizeof(lista_t));
    if (lista == NULL) {
        fprintf(stderr, "Error al crear la lista.\n");
        return 1;
    }
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
