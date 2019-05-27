#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "estructuraUno.h"
#include "funcionesArchivos.h"

int main()
{
    FILE* pArchivo;
    eEstructuraUno persona;

    generarArchivo(pArchivo);

    printf("Ingrese nombre:\n");
    scanf("%s",persona.name);
    printf("Ingrese salario:\n");
    scanf("%f",&persona.salary);

    arrayMovie_escribirArchivo(&persona,"ERROR",1);



    return 0;
}
