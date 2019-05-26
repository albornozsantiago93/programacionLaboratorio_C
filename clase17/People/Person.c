#include <stdlib.h>
#include "Person.h"

static void initialize(Person* this, int age, int something);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new (int age, int something)
{
    Person* this = malloc(sizeof(Person));//declara e inicializa
    if(this != NULL)
    {
        printf("Ingrese edad:\n");
        scanf("%d",&age);
        initialize(this,age,something);//direccion,edad,otro dato


    }

    return this;
}

/** \brief  Inicializa a una persona recibida como parametro, coloca los datos a los campos de la estructura
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Person* this, int age, int something)
{
    this->age = age;//asigna la edad que recibe como parametro
    this->something = something;
}

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
    if(age > 0)
        this->age = age;
}

/** \brief Obtiene la edad de una persona recibida como parametro, devuelve el dato
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this)
{
    return this->age;
}


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
    // Do any other freeing required here.
    free(this);
}
