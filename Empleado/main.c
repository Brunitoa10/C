#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main() {
    Empleado *emp = crearEmpleado();
    ingresarEmpleado(emp);
    mostrarEmpleado(emp);
    liberarEmpleado(emp);
    return 0;
}
