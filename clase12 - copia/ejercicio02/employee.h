#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFecha;

typedef struct{
        int idSector;
        char descripcionSector[51];
}eSector;


typedef struct{
            int id;
            char name[51];
            char lastName[51];
            float salary;
            char sexo[15];
            int isEmpty;
            eFecha fechaIngreso;
            int idSector;
}eEmployee;

#endif // EMPLOYEE_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0

int array_generarProximoId(void);
int initEmployees(eEmployee* empleados,int cantidad);
int addEmployee(eEmployee* empleados,int cantidad);
int findEmployeeById(eEmployee* empleados,int cantidad,int id);
int findIsEmpty(eEmployee* empleados,int cantidad);
int removeEmployee(eEmployee* empleados,int cantidad,int id);
void printListEmployee(eEmployee* emplead,int cantidadEmpleados,eSector* sectores);
void printEmployee(eEmployee empleado,eSector* sectores,int cantidad);
void administrarEmpleado(eEmployee* empleado,eSector* sectores,int cantidad);
int addEmployee(eEmployee* empleados,int cantidad);
void hardcodearDatosEmpleados(eEmployee* empleado, int cantidad);

