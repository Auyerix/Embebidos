/*
 * port.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Gustavo Auyero
 */

#include "port.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"


extern I2C_HandleTypeDef hi2c1;  // Manejador asignado a la comunicación I2C

#define SLAVE_ADDRESS_LCD 0x4E // Dirección del LCD
#define TIMEOUT 100				// tiempo de timeout de la comunicación I2C


void i2c_lcd_transmit (uint8_t * dataTransmit_t, uint8_t size){

	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD, dataTransmit_t, size, TIMEOUT);


}
