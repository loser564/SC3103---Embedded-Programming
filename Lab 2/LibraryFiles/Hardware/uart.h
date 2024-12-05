#ifndef __UART_H
#define __UART_H
#include "sys.h"
#include "system.h"
#include "oled.h"

#define UART_TASK_PRIO		3     //Task priority 
#define UART_STK_SIZE 		128   //Task stack size 



void uart3_init(u32 bound);
void USART_task(void *pvParameters);
void usart3_send(u8 data);

#endif