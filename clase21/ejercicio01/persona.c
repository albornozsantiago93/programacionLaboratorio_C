#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesGet.h"
#include "persona.h"

char preguntarSalir()
{
    char opcion;

    opcion= getChar("DESEA SALIR\n    (s/n)\n");

    if(opcion=='s' || opcion== 'S')
    {
        return 'S';
    }
    return opcion;
}
/*
void persona_toString(Persona* this)
{
    printf("%s\t%d\n",this->lista,this->edad);
}
*/


Persona* persona_newPersona(void)
{
     Persona* persona = (Persona*)malloc(sizeof(Persona));
     return persona;
}


int persona_setNombre(Persona* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        if(validarStringLetras(nombre)!=0)
        {
            if(strlen(nombre)>3)
            {
                retorno = 0;
                strcpy(this->nombre,nombre);
            }
        }
    }
    return retorno;
}

char* persona_getNombre(Persona* this)
{

    if(this!=NULL)
    {
        return this->nombre;
    }
    return NULL;
}

int persona_setEdad(Persona* this,int edad)
{
    int retorno=-1;

    if(this!=NULL)
        if(edad>0 && edad<120)
        {
            retorno=0;
            this->edad= edad;
        }
    return retorno;
}

int persona_getEdad(Persona* this)
{
    if(this!=NULL)
    {
        return this->edad;
    }
        return -1;
}
/*
void persona_initLista(void)
{
    size=10;
    indice=0;

    lista= (Persona**)malloc(sizeof(Persona*)*size);
}
*/
void persona_addPersona(ListaPersona* lista,Persona* persona)
{
    lista->lista[lista->indice]= persona;
    lista->indice++;

    if(lista->indice>=lista->size)
    {
        printf("NO HAY MAS LUGAR, SE HA REDEFINIDO EL ARRAY\n");
        lista->size+=10;
        lista->lista= (Persona**)realloc(lista->lista,sizeof(Persona*)*lista->size);
    }
}


ListaPersona* lista_initLista()
{
    ListaPersona* peopleList = (ListaPersona*)malloc(sizeof(ListaPersona));

    peopleList->indice=0;
    peopleList->size=2;
    peopleList->lista= (Persona**)malloc(sizeof(Persona*)*peopleList->size);

    return peopleList;
}

