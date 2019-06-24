#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad.h"
#include "funcionesGet.h"

Entidad* entidad_new()
{
    return (Entidad*)malloc(sizeof(Entidad));
}

void entidad_delete(Entidad* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int entidad_setNombre(Entidad* this, char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=0;
    }
    return retorno;
}

int entidad_getNombre(Entidad* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int entidad_setApellido(Entidad* this,char* apellido)
{
    int retorno=-1;

    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int entidad_getApellido(Entidad* this, char* apellido)
{
    int retorno=-1;

    if(this!=NULL && apellido!= NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int entidad_setId(Entidad* this, int id)
{
    int retorno=-1;
    static int idAutoincrementable=0;

    if(this!=NULL)
    {
        if(idAutoincrementable>=0)
        {
            idAutoincrementable++;
            this->idUnico= idAutoincrementable;
        }
        retorno=0;
    }
    return retorno;
}

int entidad_getId(Entidad* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id= this->idUnico;
        retorno=0;
    }
    return retorno;
}

int entidad_setHorasTrabajadas(Entidad* this,int horasTrabajadas)
{
    int retorno=-1;

    if(this!= NULL)
        if(horasTrabajadas>0)
        {
            this->horasTrabajadas= horasTrabajadas;
            retorno= 0;
        }

    return retorno;
}

int entidad_getHorasTrabajadas(Entidad* this,int* horasTrabajadas)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        retorno= 0;
    }
    return retorno;
}

int entidad_setSueldo(Entidad* this,int sueldo)
{
    int retorno=-1;

    if(this!= NULL)
        if(sueldo>1)
        {
            this->sueldo= sueldo;
            retorno= 0;
        }

    return retorno;
}


int entidad_getSueldo(Entidad* this,int* sueldo)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *sueldo= this->sueldo;
        retorno=0;
    }
    return retorno;
}

Entidad* entidad_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Entidad* entidadAux;

    entidadAux= entidad_new();

    if(validarInt(idStr)==0)
    {
        if(validarString(nombreStr)==0)
        {
            if(validarString(apellidoStr)==0)
            {
                if(validarInt(horasTrabajadasStr)==0)
                {
                    if(validarInt(sueldoStr)==0)
                    {
                        entidad_setNombre(entidadAux,nombreStr);
                        entidad_setApellido(entidadAux,apellidoStr);
                        entidad_setHorasTrabajadas(entidadAux,atoi(horasTrabajadasStr));
                        entidad_setId(entidadAux,atoi(idStr));
                        entidad_setSueldo(entidadAux,atoi(sueldoStr));
                        return entidadAux;
                    }
                }
            }
        }
    }
    entidad_delete(entidadAux);

    return NULL;
}
