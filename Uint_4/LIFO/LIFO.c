/*
 * LIFO.C
 *
 *  Created on: 8 Aug 2023
 *      Author: Elsayed Ayman Habib
 */
#include "lifo.h"

LIFO_Status LIFO_Push_item(LIFO_Buf_t* lifo_buf , unsigned int item)
{
	/*
	 * Check lifo is valid
	 */
	if ((!lifo_buf->base) || (!lifo_buf->head))
	{
		return LIFO_Null ;
	}

	/*
	 * Check lifo is not full
	 */
	if (lifo_buf->count == lifo_buf->length)
	{
		return LIFO_full ;
	}

	/*
	 * Start to add item to Buffer
	 */
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error ;

}
LIFO_Status LIFO_Pop_item(LIFO_Buf_t* lifo_buf , unsigned int* item)
{
	/*
	 * Check lifo is valid
	 */
	if ((!lifo_buf->base) || (!lifo_buf->head))
	{
		return LIFO_Null ;
	}
	/*
	 * Check lifo is not empty
	 */
	if (lifo_buf->count == 0)
	{
		return LIFO_empty ;
	}
	/*
	 * Start to get item from Buffer
	 */
	lifo_buf->head--;
    *item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error ;

}
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int length)
{
	if (buf == NULL)
	{
return LIFO_Null ;
	}

	lifo_buf->base = buf ;
	lifo_buf->head = buf ;
	lifo_buf->length = length ;
	lifo_buf->count = 0 ;
	return LIFO_no_error ;
}
