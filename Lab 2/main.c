#include "system.h"

#define START_TASK_PRIO 4
#define START_STK_SIZE 256
TaskHandle_t StartTask_Handler;
TimerHandle_t TIMERTASK;
void start_task(void *pvParameters);

int main(void){
	systemInit();
	
	xTaskCreate((TaskFunction_t) start_task, (const char*) "start task", (uint16_t) START_STK_SIZE, (void *) NULL, (UBaseType_t) START_TASK_PRIO, (TaskHandle_t*) &StartTask_Handler);
	TIMERTASK = xTimerCreate("led_task", F2T(RATE_1_HZ), pdTRUE, 0, led_task);
	if(xTimerStart(TIMERTASK,0) == pdPASS)
	vTaskStartScheduler();
		
}

void start_task(void *pvParameters){
	taskENTER_CRITICAL();
	//xTaskCreate(led_task, "led_task", LED_STK_SIZE, NULL, LED_TASK_PRIO, NULL);
	// xTaskCreate(buzz_task, "buzz_task", BUZZ_STK_SIZE, NULL, BUZZ_TASK_PRIO, NULL);
	//xTaskCreate(show_task, "oled_task", BUZZ_STK_SIZE, NULL, BUZZ_TASK_PRIO, NULL); 
	//xTaskCreate(button_task,"button_task", BUZZ_STK_SIZE, NULL, BUZZ_TASK_PRIO, NULL);
	xTaskCreate (USART_task, "USART_task",BUZZ_STK_SIZE, NULL, BUZZ_TASK_PRIO, NULL);
	vTaskDelete(StartTask_Handler);
	taskEXIT_CRITICAL();
}
