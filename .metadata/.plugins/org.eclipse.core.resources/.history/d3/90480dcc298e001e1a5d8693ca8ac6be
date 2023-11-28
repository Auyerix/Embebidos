#include <stdint.h>
#include <stdbool.h>

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
/*Función pública ofrecida como interface para encapusular el módulo de debounce.c                   */
/*El usuario deberá llamar a esta función periódicamente y la misma devolverá un pulso cada vez que  */
/*ocurra una flanco descendente del pulsador, posterior al filtrado de las funciones debounce        */
/*fuera del módulo ese pulso podrá activar determinada acción correspondiente a esta transición      */
 /* sin haber accedido al módulo debounce.c                                                          */
/*---------------------------------------------------------------------------------------------------*/
/* La función readKey debe leer una variable interna del módulo y devolver true o false si la tecla  */
/* fue presionada.                                                                                   */
/* Si devuelve true, debe resetear (poner en false) el estado de la variable.                        */
/*---------------------------------------------------------------------------------------------------*/
bool_t readKey(void);

/**
  * @brief  Función que detecta flanco ascendente al presionar la tecla azul
  *
  * @param void
  * @retval true: si se produce un flanco ascendente false: si no hay flanco ascendente
  */
bool_t readKeyUp(void);


