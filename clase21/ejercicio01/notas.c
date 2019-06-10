PeopleList* persona_initLista(void)
{
    PeopleList* pl = (PeopleList*)malloc(sizeof(PeopleList));//crea la la estructura de la lista
    pl->index=0;
    pl->size=2;
    pl->lista = (Persona**)malloc(sizeof(Persona*)*pl->size);//pide memoria para los campos de las estructura de la lista
    return pl;
}

void persona_addPersona(PeopleList* pl, Persona* p)//direccion de lista y direccion de puntero al elemento
{
    pl->lista[pl->index]=p;//p es el elemento.
    pl->index++;
    // si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(pl->index>=pl->size)
    {
        printf("no hay mas lugar, redefinimos el array\r\n");
        pl->size+=10;
        pl->lista = (Persona**)realloc(pl->lista,sizeof(Persona*)*pl->size);
    }
}


#include "Persona.h"

PeopleList* pl = persona_initLista();
do
{
    Persona* persona = persona_newPersona();
    char nombreAux[20];
    preguntarNombre(nombreAux);
    if(persona_setName(persona,nombreAux))
        printf("El nombre no es valido");

    int edadAux = preguntarEdad();

    if(persona_setEdad(persona,edadAux))
        printf("La edad no es válida");

    persona_addPersona(pl,persona);
}
while(preguntarSalir()!='S')
