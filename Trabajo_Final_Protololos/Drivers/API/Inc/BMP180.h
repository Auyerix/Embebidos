/**
  ******************************************************************************

  BMP180 LIBRARY for STM32 using I2C
  Author:   	ControllersTech
  Updated:  	26/07/2020

  Updated:  	20/11/2023 by Gustavo Auyero
  	  	  		Se incluye typedef float float_t; para hacer portable el código
  	  	  		Se incluye una función uint16_t Get_ID (void) para encontrar el dispositivo en debug
  	  	  		Se comentan las funciones dando una explicación de su uso


  ******************************************************************************
  Copyright (C) 2017 ControllersTech.com

  This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
  of the GNU General Public License version 3 as published by the Free Software Foundation.
  This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
  or indirectly by this software, read more about this on the GNU General Public License.

  ******************************************************************************
*/

#ifndef _BMP180_H_
#define _BMP180_H_


#include "stm32f4xx_hal.h"

//Portabilidad de código
typedef float float_t;

/**
 * @brief  Función que permite agregar código de iniciación pero particularmente llama a una función de calibración
 * con valores genericos de los sensores y otro valores propios y particulares de cada sensor, valores que seráon
 * utilizados para los cálculos de temperatura y presión
 * @param  : None
 * @retval : None
*/
void BMP180_Start (void);

/**
 * @brief  Función lee la temperatura previa lectura de un temperatura no compesanda que será corregida por una función
 * con los algoritmos sugeridos por el fabricante del sensor y en función de las constantes leídas durante la calibración
 * La temperatura compensada será también utilizada para hacer el ajuste de la lectura de presión.
 * @param  : None
 * @retval : Temperatura atmosférica en ºC
*/
float_t BMP180_GetTemp (void);

/**
 * @brief  Función que lee la temperatura compensada y por medio de una función lee la presión no compensada, que luego
 * por un algoritmos sugerido por el fabricante y en función de las contantes de calibración realiza el cálculo de presión
 * final
 * El over sampling setting (oss) refiere a la cantidad de muestreos y promedio en función de la precisión y consumo
 * deseado o admitido. Consultar el manual del BMP180. Para este caso se utiliza el valor de 0 que es una muestra simple
 * Suponiendo cambios lentos en el valor de la presión.
 * @param  : oss (valor de over sampling)
 * @retval : Presión atmosférica en Pa
*/
float_t BMP180_GetPress (int oss);

/**
 * @brief  Función que lee la temperatura compensada y por medio de una función lee la presión no compensada, que luego
 * por un algoritmos sugerido por el fabricante y en función de las contantes de calibración realiza el cálculo de presión
 * final
 * El over sampling setting (oss) refiere a la cantidad de muestreos y promedio en función de la precisión y consumo
 * deseado o admitido. Consultar el manual del BMP180. Para este caso se utiliza el valor de 0 que es una muestra simple
 * Suponiendo cambios lentos en el valor de la presión.
 * @atention: Función no utilizada en este ejemplo
 * @param  : oss (valor de over sampling)
 * @retval : Presión atmosférica en metros de columna de agua
*/
float_t BMP180_GetAlt (int oss);

/**
 * @brief  Función para encontrar el esclavo I2C solo utilizada en etapa de debug
 * @param  : void
 * @retval : valor decimal del esclavo I2C
*/
uint16_t Get_ID (void);

#endif /* INC_BMP180_H_ */
