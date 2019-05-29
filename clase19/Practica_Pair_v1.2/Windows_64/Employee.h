#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);
Employee* employee_new(void);
void employee_delete(Employee* this);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this);
#endif // _EMPLOYEE_H


