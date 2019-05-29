#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(char* pFileName , Employee* pArrayListEmployee)
{
    FILE* pFile;
    int cantidad,i=0;
    char id[50],nombre[50],apellido[50],isEmpty[50];

    pFile= fopen(pFileName,"r");

    if(pFile==NULL)
    {
        return -1;
    }

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,isEmpty);

    do
    {
        cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,isEmpty);

        if(cantidad==4)
        {
            pArrayListEmployee[i].id= atoi(id);
            strcpy(pArrayListEmployee[i].name,nombre);
            strcpy(pArrayListEmployee[i].lastName,apellido);

            //strncpy(pArrayListEmployee[i].name,nombre,sizeof(pArrayListEmployee[i].name));
            //strncpy(pArrayListEmployee[i].lastName,apellido,sizeof(pArrayListEmployee[i].lastName));
            pArrayListEmployee[i].isEmpty = atoi(isEmpty);
            i++;
        }
        else
            break;


    }while(!feof(pFile));


    fclose(pFile);


    return i;
}

