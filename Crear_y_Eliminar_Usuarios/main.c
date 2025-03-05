#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int main(){
    usuario_t *usuario = usuario_crear("Bruno", "secreto123");

    if (usuario) {
        printf("Usuario creado: %s\n", usuario->nombre);
        usuario_eliminar(usuario);
        printf("Usuario eliminado.\n");
    } else {
        printf("Error al crear usuario.\n");
    }

    return 0;
}
