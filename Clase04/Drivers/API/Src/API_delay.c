#include "API_delay.h"
#include "stm32f4xx_hal.h"


void delayInit( delay_t * delay, tick_t duration ){

		delay->duration = duration;
		delay->running = false;
		delay->startTime = 0;

}

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

void delayWrite( delay_t * delay, tick_t duration ){

		delay->duration = duration;


}

