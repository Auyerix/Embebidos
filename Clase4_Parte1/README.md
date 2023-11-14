Gustavo Auyero

///////////////////////////////////////////////////////////////////////////////////////////////////////

Claes 04 Parte 1 se agregaron las estructuras y funciones para trabajar con antirebotes
En esta parte el botón pulsado enciende el LED y sin pulsar lo apaga usando las rutinas de antirebote

///////////////////////////////////////////////////////////////////////////////////////////////////////

Claes 04 se agregaron las estructuras y funciones para trabajar con antirebotes

/*---------------------------------------------------------------------------------------------------*/
/*Enumera los distintos estados de la máquina de elementos finito, dependiendo del estado toma       */
/*acciones                                                                                           */
/*---------------------------------------------------------------------------------------------------*/
typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

/*---------------------------------------------------------------------------------------------------*/
/*Definición de funcion debounceFSM_init                                                             */
/*Carga de estado inicial de la función antirebote                                                   */
/*---------------------------------------------------------------------------------------------------*/
void debounceFSM_init(void);

/*---------------------------------------------------------------------------------------------------*/
/*Leer las entradas, resuelve la lógica de transición de estados y actualiza las salidas             */
/*---------------------------------------------------------------------------------------------------*/
void debounceFSM_update(void);

/*---------------------------------------------------------------------------------------------------*/
/*Funciones que son llamadas cuando el botón es presionado o liberado, permitiendo realizar acciones */
/*o setear variables para detectar los flancos ascendentes o descendentes                            */
/*---------------------------------------------------------------------------------------------------*/
void buttonPressed(void);		// debe encender el LED
void buttonReleased(void);		// debe apagar el LED

/*---------------------------------------------------------------------------------------------------*/
/* La función readKey debe leer una variable interna del módulo y devolver true o false si la tecla  */
/* fue presionada.                                                                                   */
/* Si devuelve true, debe resetear (poner en false) el estado de la variable.                        */
/*---------------------------------------------------------------------------------------------------*/
bool_t readKey(void);






/////////////////////////////////////////////////////////////////////////////////////////////////////
Clase03 donde se trabajó en la modularización del ejemplo opcional de Clase02

Se agregaron comentarios en API_delay.h para que estas funciones y estructura sean utilizadas por un
usuario sin conocimientos de la función propiamente dicha
Se agregaron comentarios en main.c explicando los datos a ingrear y el duty cycle

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

