/*
 * main.c
 *
 *  Created on: 9 Aug 2023
 *      Author: Elsayed Ayman Habib
 */

#include "LIFO.h"
unsigned int UART_Buffer [5];

int main()
{
	LIFO_Buf_t UART_lifo , I2C_lifo;

	int data = 0 ;
	/*
	 * Static Allocation
	 */
	LIFO_init(&UART_lifo, UART_Buffer , 5);
	/*
	 * Dynamic Allocation
	 */
	unsigned int* I2C_Buffer = (unsigned int*)malloc(5 *sizeof(unsigned int));
	LIFO_init(&I2C_lifo, I2C_Buffer , 5);

	for(int i = 0 ; i < 5 ; i ++)
	{
		switch (LIFO_Push_item(&UART_lifo, i))
		{
		case (LIFO_full):
			{
			printf("UART_Buffer is full \n");
			printf("please pop some items from buffer \n");
			}
		break;
		case (LIFO_Null):
			{
			printf("UART_Buffer is't found \n");
			printf("please create buffer before push any item \n");
			}
		break;
		case (LIFO_no_error):
			{
			printf("UART_Buffer is successfully found \n");
			printf("UART_Buffer add : %d \n" , i);
			}
		break;
		}
	}

	for(int i = 0 ; i < 5 ; i ++)
	{
		switch (LIFO_Pop_item(&UART_lifo, &data))
		{
		case (LIFO_empty):
			{
			printf("UART_Buffer is empty \n");
			printf("please bush some items to buffer \n");
			}
		break;
		case (LIFO_Null):
			{
			printf("UART_Buffer is't found \n");
			printf("please create buffer before push any item \n");
			}
		break;
		case (LIFO_no_error):
			{
			printf("UART_Buffer is successfully found \n");
			printf("UART_Buffer get : %d \n" , data);
			}
		break;
		}
	}
	return 0 ;
}
