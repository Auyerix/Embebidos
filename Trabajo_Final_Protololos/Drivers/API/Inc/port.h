/*
 * port.h
 *
 *  Created on: Dec 8, 2023
 *      Author: Gustavo Auyero
 *      @attention
 *      Este driver permiter recibir los valores a transmitir por I2C y comunicacrse con un LCD
 *      Se ha utilizado una llamada a la HAL de STM32 para este fin
 *      Este driver será reemplazado junto con su llamada a la función en caso que el LCD requiera
 *      otro método de comunicación
 *
 */

//#ifndef API_INC_PORT_H_
//#define API_INC_PORT_H_

#include "main.h"


/**
  * @brief  Función de comunicación del LCD por medio de I2C
  * Envía los comandos necesarios para inicializar un LCD de 4x16
  *
  * @param 	uint8_t * dataTransmit_t puntero al inicio del vector a transmitir
  * @param  uint8_t size tamño del vector a transmitir
  * @retval void
  */
void i2c_lcd_transmit (uint8_t * dataTransmit_t, uint8_t size);   // initialize i2c with lcd
