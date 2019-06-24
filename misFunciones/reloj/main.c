#include <LiquidCrystal.h>

/******************************************************************
* Programa: Ejemplo de uso del LCD Keypad Shield
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento del LCD Keypad Shield
*   Manejar una entrada analógica
*
* Aspectos a destacar:
*   -Lectura de la entrada analogica
*
* Versión: 0.6 del 19 de Junio de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

//#include "reloj.h"
void reloj_setup(void);
void reloj_loop(void);
int read_LCD_buttons(void);
void incrementarSegundos();
//#include "reloj.h"

//#include "timer.h"

    #define TIMERS_QTY 4
    #define TIMERS_INCREMENT 50
    #define RELOJ_TIMER_0 0
    #define RELOJ_TIMER_1 1
    #define RELOJ_TIMER_2 2
    #define __TIMER_3 3

    typedef struct
    {
        unsigned long delayValue;
        char running;
    }S_timerData;


int timer_waitMs(int delayNumber,int delayMs);
void timer_resetWait(int delayNumber);
void timer_setup();
void timer_tick(int lapsedTime);
int timer_loop();
//#include "timer.h"




/** \brief  Se invoca una sola vez cuando el programa empieza.
 *          Se utiliza para inicializar los modos de trabajo
 *          de los pines, el puerto serie, etc...
 * \param void
 * \return void
 */
void setup(void)
{

  timer_setup();
  reloj_setup(); // inicializo el reloj

}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *
 * \param void
 * \return void
 */
void loop(void)
{
    timer_loop();
    reloj_loop();

}


//--------------------------------------------------------------------------------------------------------------
//"reloj.cpp"
//--------------------------------------------------------------------------------------------------------------
#define FALSE 0
#define TRUE 1

#define RELOJ_STATE_NONE 0
#define RELOJ_STATE_SHOW 1
#define RELOJ_STATE_SETUP 2

#define RELOJ_STATE_SETUP_SEG 0
#define RELOJ_STATE_SETUP_MIN 1


#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5


static int minutos;
static int segundos;
static int minutosSetup;
static int segundosSetup;
static int state_reloj = RELOJ_STATE_NONE;
static int state_reloj_setup = RELOJ_STATE_SETUP_SEG;
static int state_reloj_setup_mostrar = 0;
static int lastKey = btnNONE;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


/** \brief  Se invoca una sola vez cuando el programa empieza.
 *          Se utiliza para inicializar los modos de trabajo
 *          de los pines, el puerto serie, etc...
 * \param void
 * \return void
 */
void reloj_setup(void)
{
    minutos = 0;
    segundos = 0;
    state_reloj = RELOJ_STATE_SHOW;
    //Serial.begin(9600);
    lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}


/** \brief  Contiene el programa del reloj que se ejecutará cíclicamente
 *
 * \param void
 * \return void
 */
void reloj_loop(void)
{

    int tecla = btnNONE;
    char pantalla[21];

    if(timer_waitMs(RELOJ_TIMER_0,150))
        tecla = read_LCD_buttons();


    if(state_reloj == RELOJ_STATE_SHOW)
    {
        lcd.setCursor(0,0);
        sprintf(pantalla,"Rel - %02d:%02d",minutos,segundos);
        lcd.print(pantalla);

        if(tecla == btnSELECT)
        {
            state_reloj = RELOJ_STATE_SETUP;
            state_reloj_setup = RELOJ_STATE_SETUP_SEG;
            minutosSetup = minutos;
            segundosSetup = segundos;
        }

    }
    else if(state_reloj == RELOJ_STATE_SETUP)
    {
        if(tecla == btnUP)
        {
            if(state_reloj_setup == RELOJ_STATE_SETUP_SEG)
                segundosSetup++;
            else
                minutosSetup++;

        }


        if(tecla == btnLEFT)
        {
            if(state_reloj_setup == RELOJ_STATE_SETUP_SEG)
                state_reloj_setup = RELOJ_STATE_SETUP_MIN;
            else
                state_reloj_setup = RELOJ_STATE_SETUP_SEG;
        }

        if(tecla == btnSELECT)
        {
            state_reloj = RELOJ_STATE_SHOW;
            minutos = minutosSetup;
            segundos = segundosSetup;
        }

        lcd.setCursor(0,0);

        if(timer_waitMs(RELOJ_TIMER_2,500))
        {
            if(state_reloj_setup_mostrar == 0)
                state_reloj_setup_mostrar = 1;
            else
                state_reloj_setup_mostrar = 0;
        }

        if(state_reloj_setup == RELOJ_STATE_SETUP_SEG)
        {
            if(state_reloj_setup_mostrar)
                sprintf(pantalla,"Set - %02d:%02d",minutosSetup,segundosSetup);
            else
                sprintf(pantalla,"Set - %02d:__",minutosSetup);
        }
        else
        {
            if(state_reloj_setup_mostrar)
                sprintf(pantalla,"Set - %02d:%02d",minutosSetup,segundosSetup);
            else
                sprintf(pantalla,"Set - __:%02d",segundosSetup);
        }

        lcd.print(pantalla);
    }

    if(timer_waitMs(RELOJ_TIMER_1,1000))
        incrementarSegundos();



}

void incrementarSegundos()
{
        if(segundos<59)
        {
            segundos++;
        }
        else
        {
            segundos=0;
            if(minutos<59)
            {
                minutos++;
            }
            else
            {
                minutos = 0;
            }
        }

}

/** \brief  Realiza la lectura de la entrada analogica y determina según su valor
 *          a que botón hace referencia.
 * \param void
 * \return int: Que representa el botón pulsado
 */
int read_LCD_buttons(void)
{
  int lcd_key = btnNONE; // el valor inicial es NONE
  int adc_key_in = 0;
  adc_key_in = analogRead(0); // lectura de la entrada analogica

  if (adc_key_in > 1000)
    lcd_key = btnNONE;
  else if (adc_key_in < 50)
    lcd_key = btnRIGHT;
  else if (adc_key_in < 195)
    lcd_key = btnUP;
  else if (adc_key_in < 380)
    lcd_key = btnDOWN;
  else if (adc_key_in < 555)
    lcd_key = btnLEFT;
  else if (adc_key_in < 790)
    lcd_key = btnSELECT;

  return lcd_key;
}
//--------------------------------------------------------------------------------------------------------------
//"reloj.cpp"
//--------------------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------------------
//"timer.cpp"
//--------------------------------------------------------------------------------------------------------------
static S_timerData timersArray[TIMERS_QTY];
static int anterior;
static int actual;

/** \brief  Evalua si pasaron 10ms si es asi llama al tick()
 *
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_loop()
{
    actual = millis();
    int diff = actual-anterior;
    if(diff>TIMERS_INCREMENT)
    {
      	timer_tick(TIMERS_INCREMENT);
        Serial.println(diff);
        anterior=anterior+TIMERS_INCREMENT;
    }
}

/** \brief  Si el timer no esta corriendo setea el contador del timer caso contrario evalua si finalizo
 *
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_waitMs(int delayNumber,int delayMs)
{
	if(timersArray[delayNumber].running==0)
	{
		timersArray[delayNumber].delayValue = delayMs;
		timersArray[delayNumber].running=1;
	}
	else
	{
		if(timersArray[delayNumber].delayValue<=0)
		{
			timersArray[delayNumber].running=0;
			return 1;
		}
	}
	return 0;
}

/** \brief  Baja el flag running
 *
 * \param void
 * \return void
 */
void timer_resetWait(int delayNumber)
{
	timersArray[delayNumber].running=0;
}

/** \brief  Inicializa el array de timers
 *
 * \param void
 * \return void
 */
void timer_setup()
{
  int i;
  anterior = 0;
  for(i=0;i<TIMERS_QTY;i++) // inicializo array de timers
        timersArray[i].running=0;

}
/** \brief  Decrementa los contadores de los timers
 *
 * \param void
 * \return void
 */
void timer_tick(int lapsedTime)
{
  int i;
  for(i=0;i<TIMERS_QTY;i++)
        if(timersArray[i].running && timersArray[i].delayValue > 0)
            timersArray[i].delayValue = timersArray[i].delayValue - lapsedTime;
}


//--------------------------------------------------------------------------------------------------------------
//"timer.cpp"
//--------------------------------------------------------------------------------------------------------------

