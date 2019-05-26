#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define CANTIDAD 3

int main()
{
    int i,auxiliarNota;
    char auxiliarNombre[50];
    struct alumno arrayAlumnos[CANTIDAD];
    struct alumno* arrayPunterosAlumnos[CANTIDAD];

    for(i=0; i<CANTIDAD; i++){

        arrayPunterosAlumnos[i] = &arrayAlumnos[i];// Copiamos la posición de memoria de cada elemento

    printf("\nIngrese el nombre: ");
    scanf("%s",auxiliarNombre);
    strcpy(arrayAlumnos[i].nombre, auxiliarNombre);
    printf("\nIngrese la Nota: ");
    scanf("%i",&auxiliarNota);
    arrayAlumnos[i].nota = auxiliarNota;
}

    printf("\n\t-MOSTRAMOS EL SIN ORDENAR ARRAY-\n");
    puntero_imprimir(arrayPunterosAlumnos,CANTIDAD);
    puntero_ordenar(arrayPunterosAlumnos, CANTIDAD);

    printf("\n\n\t-MOSTRAMOS EL ARRAY ORDENADO-\n");
    puntero_imprimir(arrayPunterosAlumnos,CANTIDAD);

    return 0;
}

