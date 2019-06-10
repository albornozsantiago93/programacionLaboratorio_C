#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "funcionesGet.h"



char preguntarSalir()
{
    char opcion;

    printf("DESEA SALIR?");
    fflush(stdin);
    scanf("%c",&opcion);

    if(opcion=='s' || opcion== 'S')
    {
        return 'S';
    }
    return opcion;
}

void persona_toString(Persona* this)
{
    printf("%s\t%d",this->nombre,this->edad);
}



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
        if(validarStringLetras(nombre)==1)
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
        if(edad>0 && edad<99)
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
        return NULL;
}

void persona_initLista(void)
{
    size = 10;
    indice=0;

    lista= (Persona**)malloc(sizeof(Persona*)*size);
}

void persona_addPersona(Persona* this)
{
    lista[indice]= this;
    indice++;

    if(indice>=size)
    {
        printf("NO HAY MAS LUGAR, SE HA REDEFINIDO EL ARRAY\n");
        size= size+10;
        lista= (Persona**)realloc(lista,sizeof(Persona*)*size);
    }
}
