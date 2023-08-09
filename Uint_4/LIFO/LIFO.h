/*
 * LIFO.h
 *
 *  Created on: 8 Aug 2023
 *      Author: Elsayed Ayman Habib
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

typedef struct {
	unsigned int length ;
	unsigned int count ;
	unsigned int* base ;
	unsigned int* head ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error ,
	LIFO_full ,
	LIFO_empty ,
	LIFO_Null
}LIFO_Status;

LIFO_Status LIFO_Push_item(LIFO_Buf_t* lifo_buf , unsigned int item);
LIFO_Status LIFO_Pop_item(LIFO_Buf_t* lifo_buf , unsigned int* item);
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int length);

#endif /* LIFO_H_ */
