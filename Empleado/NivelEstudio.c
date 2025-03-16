#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NivelEstudios.h"
#include "Errores.h"

NivelEstudios *crearNivelEstudios(){
    NivelEstudios *nuevoNivelEstudios = (NivelEstudios *)(malloc(sizeof(NivelEstudios)));
    if(!nuevoNivelEstudios){
        printf("Error al reservar memoria para nivel estudios");
        free(nuevoNivelEstudios);
        exit(ERROR_RESERVAR_MEMORIA_ESTADO_CIVIL);
    }
    nuevoNivelEstudios->descripcion = (char *)(malloc(20 * sizeof(char)));
    if(!nuevoNivelEstudios->descripcion){
        printf("Error al reservar memoria para nivel estudios");
        free(nuevoNivelEstudios);
        exit(ERROR_RESERVAR_MEMORIA_ESTADO_CIVIL);
    }
    return nuevoNivelEstudios;
}

void ingresarNivelEstudios(NivelEstudios *nivelEstudios){
    int opcion;
    do{
        printf("Ingrese opcion de nivel de estudio alcanzado \n");
        printf("0: Primario 1: Secundario 2: Terciario 3: Universitario 4: Magister 5: PostGrado :: ");
        scanf("%d", &opcion);
    }while(opcion < 0 || opcion > 5);
    nivelEstudios->codigo = opcion;

    char *nivel[] = {"Primario","Secundario","Terciario","Universitario","Magister","PostGrado"};
    strcpy(nivelEstudios->descripcion, nivel[nivelEstudios->codigo]);
}

void mostrarNivelEstudios(const NivelEstudios *nivelEstudios){
    printf("Nivel de estudio alcanzado: %s\n", nivelEstudios->descripcion);
}

void liberarNivelEstudios(NivelEstudios *nivelEstudios){
    if(nivelEstudios){
        free(nivelEstudios->descripcion);
        free(nivelEstudios);
    }
}
