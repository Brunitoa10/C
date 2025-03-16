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



inventario_t *inventario_crear(unsigned int const cantidad){
    //Reserva memoria para el invetario
    inventario_t *nuevoInventario = malloc(sizeof(inventario_t));
    if(!nuevoInventario){
        return NULL;
    }
    //Reserva memoria para los renglones
    nuevoInventario->renglones = malloc(cantidad*sizeof(renglon_t));
    if(!nuevoInventario->renglones){
        free(nuevoInventario);
        return NULL;
    }

    //Inicializar los renglos vacios
    for(int pos = 0; pos < cantidad; pos++){
        nuevoInventario->renglones[pos].nombre = NULL;
        nuevoInventario->renglones[pos].descripcion = NULL;
    }

    //Asignar la cantidad de renglones
    nuevoInventario->cantidad = cantidad;
    return nuevoInventario;
}

int inventario_destruir(inventario_t **inventario){
    if(!inventario || !*inventario){
        return NULL;
    }
    //liberar memoria en cada renglon
    for(int pos = 0; pos < (*inventario)->cantidad; pos++){
        free((*inventario)->renglones[pos].nombre);
        free((*inventario)->renglones[pos].descripcion);
    }
    free((*inventario)->renglones);
    free(*inventario);

    *inventario = NULL;
    return 0;
}

int main() {
    inventario_t *miInventario = inventario_crear(5);
    if (!miInventario) {
        printf("Error al crear el inventario\n");
        return 1;
    }

    printf("Inventario creado con Exito\n");

    // Destruir el inventario y verificar que se liberó correctamente
    if (inventario_destruir(&miInventario) == 0) {
        printf("Inventario destruido correctamente\n");
    } else {
        printf("Error al destruir el inventario\n");
    }

    return 0;
}
