#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

//A
usuario_t *usuario_crear(const char* nombre, const char* password){
    //Asignacion de memoria para el nuevo usuario
    usuario_t *nuevoUsuario = malloc(sizeof(usuario_t));
    if(nuevoUsuario == NULL){
        return NULL;
    }
    //Asigancion de memoria y copiado para el nombre
    nuevoUsuario->nombre = malloc(strlen(nombre)+1);
    if(nuevoUsuario->nombre==NULL){
        free(nuevoUsuario);
        return NULL;
    }
    strcpy(nuevoUsuario->nombre,nombre);

    //Asigancion de memoria y copiado para el password
    nuevoUsuario->password = malloc(strlen(password)+1);

    if(nuevoUsuario->password == NULL){
        free(nuevoUsuario->nombre);
        free(nuevoUsuario);
        return NULL;
    }
    strcpy(nuevoUsuario->password,password);
    return nuevoUsuario;
}
//B
int usuario_eliminar(usuario_t *usuario){
    if(usuario==NULL){
        return -1;
    }
    free(usuario->nombre);
    free(usuario->password);
    free(usuario);
    return 0;
}
