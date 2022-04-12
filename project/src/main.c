#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void GPIO_Init (void);

void vTask_led_blink_pc13 (void *argument);
void vTask_led_blink_pc9 (void *argument);

int main(void){		
	
	GPIO_Init();
	
	xTaskCreate(vTask_led_blink_pc13, "LED1", 32, NULL, 1, NULL);
	xTaskCreate(vTask_led_blink_pc9, "LED2", 32, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*******************************************************************************************************/

void GPIO_Init (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH &= ~GPIO_CRH_CNF13;
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
}

void vTask_led_blink_pc13 (void *argument){
	
	while(1)
	{
		
		GPIOC->BSRR |= GPIO_BSRR_BS13;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BR13;
		vTaskDelay(1000);
		
	}
	
}

void vTask_led_blink_pc9 (void *argument){
	
	while(1)
	{
	
		GPIOC->BSRR |= GPIO_BSRR_BR9;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BS9;
		vTaskDelay(1000);
		
	}
	
}