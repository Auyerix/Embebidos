#include <stdint.h>
#include <stdbool.h>


typedef uint32_t tick_t;
typedef bool bool_t;

/*---------------------------------------------------------------------------------------------------*/
/*Estructura para alojar:                                                                            */
/* startTime  = la marca de tiempo de inicio del contador                                            */
/* duration = el tiempo de período del contador                                                      */
/* running = la marca que indica si el tiempo se agotó                                               */
/*---------------------------------------------------------------------------------------------------*/
typedef struct{
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;

/*Definición de funcion delayInit:-------------------------------------------------------------------*/
/*Recibirá un puntero de la estructura definida con nombre delay_t para que la fución se encarge     */
/*de cargar el valor de la segunda variable recibida que define el tiempo de cuenta alojada duration */
/*del timer no bloqueante que se quiere contar en milisegundos                                       */
/*---------------------------------------------------------------------------------------------------*/
void delayInit( delay_t * delay, tick_t duration );

/*Definición de funcion delayRead:--------------------------------------------------------------------*/
/*Recibe el puntero a la estructura definida con nombre delay_t y verfica que el tiempo cargado en    */
/*duration se haya o no cumplido                                                                      */
/*también esta funcion evalúa si running está true de tal manera de poder comenzar la cuenta o        */
/*continuear la cuenta según el estado de la variable running                                         */
/*la función devuelve false si no se cumplió el tiempo y true si el tiempo se ha cumplido             */
/*----------------------------------------------------------------------------------------------------*/
bool_t delayRead( delay_t * delay );

/*Definición de funcion delayWrite:-------------------------------------------------------------------*/
/*Esta función permite el cambio de la variable duration en cualquier momento del programa            */
/*Recibe el puntero a la estructura y el nuevo valor de la variable duration                          */
/*----------------------------------------------------------------------------------------------------*/
void delayWrite( delay_t * delay, tick_t duration );
