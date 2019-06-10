#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesGet.h"
#include "persona.h"


int main()
{
    int edad;
    char nombre[20];

    ListaPersona* lista= lista_initLista();

    do
    {
        Persona* persona = persona_newPersona();

        getValidString("INGRESE NOMBRE:\n","ERROR\n",nombre);
        persona_setNombre(persona,nombre);

        edad=getValidIntOpcion("INGRESE EDAD:\n","ERROR CARACTER NO VALIDO\n",1,120);
        persona_setEdad(persona,edad);



        persona_addPersona(lista,persona);

    }while(preguntarSalir()!='S');

//    persona_toString(*lista);

    printf("%s\t%d",lista->lista->nombre,lista->lista->edad);

    return 0;
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
