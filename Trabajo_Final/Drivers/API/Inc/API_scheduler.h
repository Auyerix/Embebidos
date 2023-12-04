/*
 * API_scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Gustavo Auyero
 *      @brief: funciones para el manejo de las distintas tareas a realizar
 */

#ifndef API_INC_API_SCHEDULER_H_
#define API_INC_API_SCHEDULER_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef bool bool_t;
typedef float float_t;


/**
 * @brief  Esta función es el callback de la interrupción por tiempo de un handler
 * permitirá por medio de un flag avisar al módulo que la interrupción se ha cumplido
 * y disparar determinadas acciones ya fuera de la interrupción
 * para aumentar el tiempo en que estas acciones se llevan a cabo un contador permite
 * aumentar la cantidad de veces que esta interrupción debe darse para que el flag se
 * ponga en uno
 * @param  TIM_HandleTypeDef
 * @retval : None
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/**
 * @brief  Esta función realiza la lectura de los valores actules de presión y temperatura
 * como también el armado de los vectores de valores para almacenar los históricos ingresando
 * en la posición del vector 0 el valor reciente y moviendo sucesivamente los valores históricos
 * @param  : void
 * @retval : true o false según la conversión se haya realizado según el flag de la interrupción
 * por tiempo
*/
bool_t readSensor(void);

/**
 * @brief  Función que copia los datos de los vectores con valores de temperatura en otra matriz
 * enviada desde un módulo externo, según el puntero enviado desde este otro módulo
 * @param  : puntero a donde copiar la matriz de temperatura
 * @retval : void
*/
void readDataTemperature(float_t* diplayTemperature);

/**
 * @brief  Función que copia los datos de los vectores con valores de presión en otra matriz
 * enviada desde un módulo externo, según el puntero enviado desde este otro módulo
 * @param  : puntero a donde copiar la matriz de presión
 * @retval : void
*/
void readDataPressure(float_t* diplayPressure);


/**
 * @brief  Función bloqueante de lectura inicial de alarma de temperatuar
 * a ser implementada por interrupciones (no bloqueante)
 * @param  : void
 * @retval : void
*/
void readDataSerial(void);


#endif /* API_INC_API_SCHEDULER_H_ */
