#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int cantidad,i;
    Employee pArrayEmpleados[9];

    cantidad= parserEmployee("datos.csv",pArrayEmpleados);

    for(i=0;i<cantidad;i++)
    {
        printf("%d,  %s  %s   ,%d\n",pArrayEmpleados[i].id,pArrayEmpleados[i].name,pArrayEmpleados[i].lastName,pArrayEmpleados[i].isEmpty);
    }
    return 0;
}
