#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i=0, cantidad;
    char var1[25],var2[25],var3[25],var4[25];
    int retorno=-1;

    pFile= fopen("data.csv","r");

    if(pFile!=NULL)
    {
        cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

        do
        {
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if(cantidad==4)
            {
               // pArrayListEmployee.pFirstNode->pElement
            }
        }while(!feof(pFile));

        retorno=0;
        fclose(pFile);
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i=0, cantidad;
    char var1[25],var2[25],var3[25],var4[25];
    int retorno=-1;

    pFile= fopen("data.csv","rb");

    if(pFile!=NULL)
    {
        cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

        do
        {
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if(cantidad==4)
            {
               // pArrayListEmployee.pFirstNode->pElement
            }
        }while(!feof(pFile));

        retorno=0;
        fclose(pFile);
    }


    return retorno;
}

/*

int parseData(char* fileName,Persona* arrayPersonas, int len){
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
            i++;
        }
        else
            break;
    }while(!feof(pFile) && i<len);

    fclose(pFile);

    return i;
}
*/
