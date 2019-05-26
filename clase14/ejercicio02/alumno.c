#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

void puntero_ordenar(struct alumno* arrayPunterosAlumnos[], int longitudArray)
{
    struct alumno* punteroAuxiliarAlumno;//declaro como auxiliar un tipo de dato structura puntero alumno
    int i,j;
    for(i = 0; i < longitudArray -1 ; i++)
    {
        for(j = i+1; j < longitudArray ; j++)
        {
            if(arrayPunterosAlumnos[i]->nota > arrayPunterosAlumnos[j]->nota)
            {
                punteroAuxiliarAlumno = arrayPunterosAlumnos[i];
                arrayPunterosAlumnos[i] = arrayPunterosAlumnos[j];
                arrayPunterosAlumnos[j] = punteroAuxiliarAlumno;
            }
        }
    }
}

void puntero_imprimir(struct alumno* arrayPunterosAlumnos[], int longitudArray)
{
    int i;

    for(i=0;i<longitudArray;i++)
    {
        printf("\n%s\t%d",arrayPunterosAlumnos[i]->nombre,arrayPunterosAlumnos[i]->nota);
    }
}

/**
void puntero_cargarStruct(struct alumno* arrayPunteroAlumno[],int longitudArray)
{
    int i;

    for(i=0; i<longitudArray; i++)
    {
        arrayPunterosAlumnos[i] = &arrayAlumnos[i];// Copiamos la posición de memoria de cada elemento

        printf("\nIngrese el nombre: ");
        scanf("%s",auxiliarNombre);
        strcpy(arrayAlumnos[i].nombre, auxiliarNombre);
        printf("\nIngrese la Nota: ");
        scanf("%i",&auxiliarNota);
        arrayAlumnos[i].nota = auxiliarNota;
    }
}
*/
