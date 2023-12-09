Trabajo Final 

Materia: Protocolos de Comunicación

Sistema de lectura de presiòn y temperatura por medio de un BMP180 
Valores mostrados por LCD conectado por I2C

Autor: Gustavo Auyero
Noviembre 2023

Este programa tiene la misma funcionalidad que el subido en Trabajo _Final solo que se agrega un módulo port.c de manera de aislar la comunicación I2C con el LCD. De esta manera se logra darle portabilidad en caso de realizar otro tipo de comunicación con el LCD, donde se mantendría el driver del LCD y solo se cambiaría el llamado a la función que maneja la comunicación. 
Se documenta el módulo y la función asociada dentro del mismo módulo 
