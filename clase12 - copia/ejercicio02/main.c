#include <stdio.h>
#include <stdlib.h>
#include "almuerzos.h"
#include "employee.h"
#include "menues.h"
#include "funcionesGet.h"
#define CANTIDAD_EMPLEADOS 15
#define CANTIDAD_MENUES 10
#define CANTIDAD_ALMUERZOS 15

int main()
{
    int opcion,i,debajoPromedio=0,encimaPromedio=0,mayores125=0,menores125=0;
    float promedio=0,total;

    eEmployee arrayEmpleados[CANTIDAD_EMPLEADOS];
    eSector arraySectores[3]={{1,"COMPRAS"},{2,"VENTAS"},{3,"RRHH"}};
    eMenu arrayMenues[CANTIDAD_MENUES];
    eAlmuerzo arrayAlmuerzos[CANTIDAD_ALMUERZOS];

    initAlmuerzos(arrayAlmuerzos,CANTIDAD_ALMUERZOS);
    initEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS);
    initMenues(arrayMenues,CANTIDAD_MENUES);

    hardcodearDatosEmpleados(arrayEmpleados,6);
    hardcodearMenu(arrayMenues,6);
    hardcodearAlmuerzos(arrayAlmuerzos,6);

    do
    {
        system("cls");
        printf("\t-MENU PRINCIPAL-\n");
        opcion= getValidIntOpcion("\n1-ADMINISTRAR EMPLEADOS\n2-ADMINISTRAR MENUES\n3-ADMINISTRAR ALMUERZOS\n4-INFORMAR\n5-SALIR\n","ERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://administrar empleados
            system("cls");
            administrarEmpleado(arrayEmpleados,arraySectores,CANTIDAD_EMPLEADOS);
            break;

        case 2://administrar menues
            system("cls");
            administrarMenues(arrayMenues,CANTIDAD_MENUES);
            break;

        case 3://administrar almuerzos
            system("cls");
            administrarAlmuerzos(arrayEmpleados,arrayMenues,arrayAlmuerzos,CANTIDAD_EMPLEADOS,CANTIDAD_MENUES,CANTIDAD_ALMUERZOS);
            break;

        case 4://INFORMAR
            system("cls");
            printf("\t\tINFORME\n\n");

            promedio= promedioImporteMenues(arrayMenues,CANTIDAD_MENUES);
            total= totalImporteMenues(arrayMenues,CANTIDAD_MENUES);
            menores125= menuesMenores125(arrayMenues,CANTIDAD_MENUES);
            mayores125= menuesMayores125(arrayMenues,CANTIDAD_MENUES);
            for(i=0;i<CANTIDAD_MENUES;i++)
            {
                if(arrayMenues[i].isEmpty==ESTADO_OCUPADO && promedio<arrayMenues[i].importe)
                    debajoPromedio++;

                if(arrayMenues[i].isEmpty==ESTADO_OCUPADO && promedio>arrayMenues[i].importe)
                    encimaPromedio++;

            }
                printf("TOTAL IMPORTES: %.2f\nPROMEDIO TOTAL: %.2f\nMENUES SUPERIORES AL PROMEDIO: %d\nMENUES INFERIORES AL PROMEDIO: %d\n",total,promedio,encimaPromedio,debajoPromedio);
                printf("MAYORES A $125: %d\nMENORES A $125: %d\n",mayores125,menores125);
                getChar("");
                break;
        }
    }while(opcion!=5);
    return 0;
}
