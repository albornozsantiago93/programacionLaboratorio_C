#ifndef ALMUERZOS_H_INCLUDED
#define ALMUERZOS_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFechaAlmuerzo;

typedef struct{
        int idAlmuerzo;//AutoIncrementable
        int idMenu;//LISTAR.CODIGO MENU-DAR DE ALTA MOSTRANDO CODIGO DESCRIPCION. CARGO CON CODIGO
        int idEmpleado;//LISTAR TODOS LOS EMPLEADOS CON SU ID Y CARGO EL LEJADO DE EMPLEADO
        eFechaAlmuerzo fechaAlmuerzo;//CUANDO COMIO
        int isEmpty;
}eAlmuerzo;
#endif // ALMUERZOS_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "menues.h"
#include "employee.h"

int array_generarProximoIdAlmuerzos(void);
int initAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos);
int almuerzo_findIsEmpty(eAlmuerzo* almuerzos,int cantidadAlmuerzos);


void printListMenues(eMenu* menues,int cantidadMenues);
void altaAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos,eMenu* menues,eEmployee* empleados,int cantidadMenues,int cantidadEmpleados);
int menuesMayores125(eMenu* menues,int cantidadMenues);
int menuesMenores125(eMenu* menues,int cantidadMenues);

void administrarAlmuerzos(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,int cantidadAlmuerzos);

void listadoEmpleadoMenu(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues);
void menuesConsumidosEmpleados(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,int idEmpleado);


void hardcodearAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos);
void menuesConsumidosFecha(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,eFechaAlmuerzo fecha);

void empleadosConsumieronFecha(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,eFechaAlmuerzo fecha);
