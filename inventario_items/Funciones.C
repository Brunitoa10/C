#include "Funciones.h"


inventario_t *inventario_crear(unsigned int const cantidad){
    //Reserva memoria para el invetario
    inventario_t *nuevoInventario = (inventario_t *)malloc(sizeof(inventario_t));
    if(!nuevoInventario){
        return NULL;
    }
    //Reserva memoria para los renglones
    nuevoInventario->renglones = (renglon_t *)malloc(cantidad*sizeof(renglon_t));
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
