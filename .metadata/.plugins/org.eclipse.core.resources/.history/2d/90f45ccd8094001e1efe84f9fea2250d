/*
 * API_scheduler.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Gustavo Auyero
 */

#include "API_scheduler.h"
#include "main.h"
#include "BMP180.h"

#include <stdio.h>
#include <string.h>

#include "API_uart.h"

extern TIM_HandleTypeDef htim10;

//Variable que indica la presencia de la interrupción
static bool_t schedulerFlag = false;

//Variable que indica ENTER en el 3er dígito para leer el valor de alarma por puerto serie
static bool_t serialReadFlag = false;

//Valores para alojar lectura de presión y temperatura actual e históricos
static float_t pressure[4] = {0};
static float_t temperature[4] = {0};

static char bufferSerial[50] = {0};

static char serialBufferReception[10];

//valor de Alarma de Temperatura a ser ingresado por puerto serial (a ser implementado por interrupciones)
float_t alarmTemperature = 25.00;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	static uint16_t count = 0;
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	if(count==3){
		//HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
		schedulerFlag = true;
		count = 0;
	}
	count++;

}

bool_t readSensor(void){

	if(schedulerFlag){
		schedulerFlag = false;
		HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);

		temperature[3] = temperature[2];
		temperature[2] = temperature[1];
		temperature[1] = temperature[0];

		pressure[3] = pressure[2];
		pressure[2] = pressure[1];
		pressure[1] = pressure[0];


		temperature[0] = BMP180_GetTemp();
		pressure[0] = BMP180_GetPress (0);

		//Esto envía los valores actuales de presión y temperatura a la UART
		sprintf (bufferSerial,"%4.2fC %6.0fPa \n\r",temperature[0],pressure[0]);
		uartSendString((uint8_t *)bufferSerial);

		return true;
	}
	return false;
}

void readDataTemperature(float_t* diplayTemperature){

	*diplayTemperature = temperature[0];
	*(diplayTemperature+1) = temperature[1];
	*(diplayTemperature+2) = temperature[2];
	*(diplayTemperature+3) = temperature[3];

}

void readDataPressure(float_t* diplayPressure){

	*diplayPressure = pressure[0];
	*(diplayPressure+1) = pressure[1];
	*(diplayPressure+2) = pressure[2];
	*(diplayPressure+3) = pressure[3];

}

void readDataSerial(void){


		uartReceiveStringSize((uint8_t *) serialBufferReception,3);

		if(serialBufferReception[2]=='\r'){
			alarmTemperature = (serialBufferReception[0]-48)*10 + (serialBufferReception[1]-48);

			serialReadFlag=true;
		}


}


