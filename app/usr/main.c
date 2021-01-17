#include "global_define.h"


uint8_t g_aa;

void delay(void)
{
	int i, j;
	for (i = 0; i < 1000; i++)
		for(j =0; j< 1000; j++)
			;
}

void PMTask1(void *pvParameters)
{
    while (9)
    {
	    g_aa++;
 	    //PA_TaskDelay(4000);
	}
}


void PMTask2(void *pvParameters)
{
    while(9)
    {
        g_aa--;
        PA_TaskDelay(400000);
		delay();
        IWDT_Clear();   //喂狗则不复位，不喂狗则复位
    }
}


int32_t main()
{
    SystemClockSelect(SCU_SysClk_HRC, CLK_SEL_HRC);  //配置时钟
    DeviceClockAllEnable();   //打开所有外设时钟
    SystemCoreClock = 20000000;

    xTaskCreate(PMTask1, "PMTask1", 128, NULL, 1, NULL);
   
    xTaskCreate(PMTask2, "PMTask2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
	while(1);
}

