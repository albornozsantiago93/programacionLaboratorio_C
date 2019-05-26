#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);
void mostrarCadenaDos(char* punteroCadena);

int main()
{
    char cadena[]={"hola"};
    char* puntero;

    puntero= cadena;//es equivalente a escribir puntero = &cadena[0]

    mostrarCadena(puntero);
    printf("\n");
    mostrarCadenaDos(puntero);

    return 0;
}

void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
    printf("\n%p",punteroCadena);
}

void mostrarCadenaDos(char* punteroCadena)
{
    int i=0;

    while(i!=5)
    {
        printf("%c",*(punteroCadena+i));
        i++;
    }
    printf("\n%p",punteroCadena);

}
