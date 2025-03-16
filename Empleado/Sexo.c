#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Sexo.h"
#include "Errores.h"

Sexo *crearSexo(){
    Sexo *nuevoSexo = (Sexo *)malloc(sizeof(Sexo));
    if(!nuevoSexo){
        printf("Error al reservar memoria para el sexo");
        free(nuevoSexo);
        exit(ERROR_RESERVAR_MEMORIA_SEXO);
    }
    nuevoSexo->descripcion = (char *) malloc(10 * sizeof(char));
    if(!nuevoSexo->descripcion){
        printf("Error al reservar memoria para el sexo");
        free(nuevoSexo);
        exit(ERROR_RESERVAR_MEMORIA_SEXO);
    }
    return nuevoSexo;
}

void ingresarSexo(Sexo *sexo){
    char opcion;
    do{
        printf("Ingrese opcion de genero F o M: ");
       scanf(" %c", &opcion);
    }while(opcion != 'F' && opcion != 'M');
    sexo->codigo = opcion;
   strcpy(sexo->descripcion, (sexo->codigo == 'F') ? "Femenino" : "Masculino");
}

void mostrarSexo(const Sexo *sexo) {
    printf("Sexo: %s\n", sexo->descripcion);
}

void liberarSexo(Sexo *sexo) {
    if(sexo){
        free(sexo->descripcion);
        free(sexo);
    }
}
