#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 


void Uart_Init(u32 bound);
void Uart1_SendByte(u8 data);
#endif


