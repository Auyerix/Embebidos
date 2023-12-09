#include "stm32f4xx_hal.h"

/**
  * @brief  Función de inicio de LCD
  * Envía los comandos necesarios para inicializar un LCD de 4x16
  *
  * @param 	void
  * @retval void
  */
void lcd_init (void);   // initialize lcd

/**
  * @brief  Función de envío de comandos
  *
  * @param 	cmd = comando a enviar
  * @retval void
  */
void lcd_send_cmd (char cmd);  // send command to the lcd


/**
  * @brief  Función de envío de caracter
  *
  * @param 	data = caracter a enviar
  * @retval void
  */
void lcd_send_data (char data);  // send data to the lcd

/**
  * @brief  Función de cadenas utilizando la función lcd_send_data hasta encontrar un retorno
  * de línea (es decir hasta el final de la cadena
  * @param 	data = puntero al inicio de la cadena
  * @retval void
  */
void lcd_send_string (char *str);  // send string to the lcd

/**
  * @brief  Función de cadenas utilizando la función lcd_send_data hasta encontrar un retorno
  * de línea (es decir hasta el final de la cadena
  * @param 	data = puntero al inicio de la cadena
  * @retval void
  */
void lcd_send_string (char *str);  // send string to the lcd

/**
  * @brief  Función que llena la memoria del LCD de espcios en blanco limpiando la pantalla permitiendo
  * sobreescribir sobre una pantalla en blanco evitando mensajes antiguos.
  * @param 	void
  * @retval void
  */
void lcd_clear (void);  

/**
  * @brief  Mensaje de información y bienvenida con un delay bloqueante de inicio del Sistema
  * @param 	void
  * @retval void
  */
void welcome_message(void);
