
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"

typedef bool bool_t;

/**
  * @brief  Función de inicialización de la uart2
  *
  * @param
  * @retval true: si la inicialización es correcta false si ha fallado
  */
bool_t uartInit(void);

/**
  * @brief  Función de envío de una cadena por el puerto serie
  *
  * @param Puntero a la cadena que se quiere transmitir por el puerto serie
  * 	transmite haste encontrar un '\0'
  * @retval void
  */
void uartSendString(uint8_t * pstring);

/**
  * @brief  Función de envío de una cadena por el puerto serie
  * @param  Puntero a la cadena que se quiere transmitir por el puerto serie
  * @param  Cantidad de caracteres de esa cadena a transmitir
  * @retval void
  */
void uartSendStringSize(uint8_t * pstring, uint16_t size);

/**
  * @brief  Función de recepción de una cadena por el puerto serie
  * @param  Puntero a la cadena donde se reciben los caracteres por puerto serie
  * @param  Cantidad de caracteres de esa cadena a recibir
  * @retval HAL void
  */
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
