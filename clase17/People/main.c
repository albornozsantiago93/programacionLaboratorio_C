#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    Person* personArray[10];//puntero a estructura, 50 direcciones de memoria
    int i;

    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);//inicializa
    }


    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i+4);//setea,
    }

    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }

    scanf(" ");
    person_free(*personArray);
    return 0;
}

