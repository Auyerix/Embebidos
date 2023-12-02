/*
 * API_screen_managment.c
 *
 *  Created on: Nov 27, 2023
 *      Author: osboxes
 */

#include "API_screen_managment.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include "API_debounce.h"
#include "API_scheduler.h"

#include "i2c-lcd.h"

#include <stdio.h>
#include "string.h"


//definición de una instancia de screenState_t con los distintos estados de la máquina
static screenState_t screenState;

//Matrices para recibir los valores a publicar de temperatura y presión
float diplayTemperature[4] = {0};
float diplayPressure[4] = {0};

//Buffer de escritura en LCD
char buffer[40];


void screenFSM_init(void){

	//inicio de la máquina de estados
	screenState = SCREEN_MAIN;

}

void screenFSM_update(void){


		switch(screenState){

		case SCREEN_MAIN:
			if(readKey()){
				screenState = SCREEN_ALARMS;
			}

		break;

		case SCREEN_ALARMS:
			if(readKey()){
				screenState = SCREEN_HISTORICAL;
			}


		break;

		case SCREEN_HISTORICAL:
			if(readKey()){
				screenState = SCREEN_MAIN;
			}


		break;



		default:
		screenState = SCREEN_MAIN;

		}


}

void screen_data_update(void){

	if(screenState == SCREEN_MAIN){

		readDataTemperature(diplayTemperature);
		readDataPressure(diplayPressure);


			lcd_send_cmd (0x80|0x00);
			lcd_send_string("VALORES ACTUALES");

			sprintf (buffer,"Valor=%4.2f C", diplayTemperature[0]);
			lcd_send_cmd (0x80|0x40);
			lcd_send_string(buffer);

			sprintf (buffer,"Valor=%6.0f Pa", diplayPressure[0]);
			lcd_send_cmd (0x80|0x10);
			lcd_send_string(buffer);

			lcd_send_cmd (0x80|0x50);
			lcd_send_string("ALARMAS NO");
	}

}

/*
sprintf (buf,"Valor= %u", num);
  //sprintf(buf,"hola    ");
  lcd_send_cmd (0x80|0x00);
  lcd_send_string (buf);*/





