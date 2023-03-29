/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
 #include "uart.h"
 
 /*
  * casting to tell the compiler that the extras are not an integer representing the address of the pointer
  */
 #define UART0DR  *((volatile unsigned int*)((unsigned int*)0x101f1000))
 
 void Uart_Send_String(unsigned char *P_tx_string)
 {
	 while(*P_tx_string != '\0')
	 {
		 /*
		  * casting to align with the addess
		  */
		 UART0DR = (unsigned int)(*P_tx_string);
		 P_tx_string++;
	 }
 }