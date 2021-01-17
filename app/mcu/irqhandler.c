#include "global_define.h"


void NMI_IRQHandler(void)
{

}

void HardFault_IRQHandler(void)
{
    while (1)
    {
    }
}

// void SVC_IRQHandler(void)
// {

// }

// void PendSV_IRQHandler(void)
// {

// }

/*
*********************************************************************************
* @函数名	：SysTick_IRQHandler
* @描述  	：SysTick中断
* @参数  	：无
* @返回值 	：无
*********************************************************************************
*/
// void SysTick_IRQHandler(void)
// {
//     //TimingDelay_Decrement();
// }


void IWDT_IRQHandler(void)
{
    //IWDT_Clear();
}


void CCM_IRQHandler(void)
{
    //CCMConfig(DISABLE, DISABLE, CCM_Trig_Rise);
    //SystemClockConfig();//使用内部20MHZ晶振
}


void PINT0_IRQHandler(void)
{
    if(PINT_GetITStatus(PINT_IT_PINT0) != RESET)
    {
        PINT_ClearITPendingBit(PINT_IT_PINT0);
        IWDT_Clear();
    }
}


void PINT2_IRQHandler(void)
{
    if(PINT_GetITStatus(PINT_IT_PINT2) != RESET)
    {
        PINT_ClearITPendingBit(PINT_IT_PINT2);
        IWDT_Clear();
    }
}


/*********************************************************
函数名: void T16N3_IRQHandler(void)
描  述: T16N3定时中断函数
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void T16N3_IRQHandler(void)
{


    return;
}

/*********************************************************
函数名: void Interrupt_KINT_Handler(void)
描  述: 按键中断处理函数
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void KINT_IRQHandler(void)
{

}


