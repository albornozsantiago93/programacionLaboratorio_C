#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesGet.h"
#include "funciones.h"


int main()
{
    int edad;
    char nombre[20];

        persona_initLista();

    do
    {
        Persona* persona = persona_newPersona();

        edad= getValidIntOpcion("INGRESE EDAD:\n","ERROR",1,120);
        if(persona_setEdad(persona,edad))
            printf("LA EDAD NO ES VALIDA\n");

        getValidString("INGRESE NOMBRE:\n","ERROR",nombre);
        if(persona_setNombre(persona,nombre))
            printf("EL NOMBRE NO ES VALIDO");

        persona_addPersona(persona);

    }while(preguntarSalir()!='S');

    persona_toString(*lista);
}


/*
Persona* persona_newParametros(char* nombre,int edad,int id)
{
    Persona* this = persona_newPersona();
    if( !persona_setNombre(this,nombre) && !persona_setEdad(this,edad) && !alumno_setId(this, id))
    {
        return this;
    }
    alumno_delete(this);
    return NULL;
}


*/
