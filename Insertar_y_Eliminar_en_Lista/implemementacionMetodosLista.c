#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos_lista.h"

int lista_insertar(lista_t *lista, const char *palabra){

    struct celda *nuevaCelda = malloc(sizeof(struct celda));
    if(nuevaCelda == NULL){
        return -1;
    }
    nuevaCelda->palabra = malloc(strlen(palabra)+1);
    if(nuevaCelda->palabra == NULL){
        free(nuevaCelda);
        return -1;
    }
    strcpy(nuevaCelda->palabra,palabra);

    //Insertar el nuevo nodo al comienza de la lista
    nuevaCelda->siguiente = lista->primera;
    lista->primera = nuevaCelda;
    return 0;
}

//B

int lista_destruir(lista_t **lista){
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
