#include "API_delay.h"
#include "stm32f4xx_hal.h"

//Función donde se alojarán los datos del retardo
void delayInit( delay_t * delay, tick_t duration ){

		delay->duration = duration;
		delay->running = false;
		delay->startTime = 0;

}
//Función de disparo del retardo: Retorna: 1= tiempo cumplido 0: no alcanzo el tiempo asignado
bool_t delayRead( delay_t * delay ){

		if(delay->running == false){

			delay->startTime = HAL_GetTick();
			delay->running = true;
			return 0;
		}
		else{
			if(HAL_GetTick()- delay->startTime >= delay->duration){
				delay->running = false;
				return 1;
			}
			else{
				return 0;
		}

}


	}
//Función de cambio de duracion de tiempo de delay existente
void delayWrite( delay_t * delay, tick_t duration ){

		delay->duration = duration;

}

