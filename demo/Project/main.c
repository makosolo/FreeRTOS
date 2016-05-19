#include "sys.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "croutine.h"

#include "bsp_usart.h"
#include "bsp_led.h"
#include "bsp_init.h"

void vTaskTaskLED0(void *pvParameters);
void vTaskTaskLED1(void *pvParameters);

int main(void)
{
    bsp_Init();//Ӳ����ʼ��
    
    xTaskCreate(    vTaskTaskLED0,   /* ������  */
                    "vTaskTaskLED0",     /* ������    */
                    512,               /* stack��С����λword��Ҳ����4�ֽ� */
                    NULL,              /* �������  */
                    1,                 /* �������ȼ�*/
                    NULL );            /* ������  */

    xTaskCreate(    vTaskTaskLED1,   /* ������  */
                    "vTaskTaskLED1",     /* ������    */
                    512,               /* stack��С����λword��Ҳ����4�ֽ� */
                    NULL,              /* �������  */
                    1,                 /* �������ȼ�*/
                    NULL );            /* ������  */
    
    vTaskStartScheduler();
    
    while(1);
}

void vTaskTaskLED0(void *pvParameters)
{
    while(1)
    {
        LED0 = !LED0;
        vTaskDelay(500);
    }
}

void vTaskTaskLED1(void *pvParameters)
{
    while(1)
    {
        LED1 = !LED1;
        vTaskDelay(250);
    }
}
