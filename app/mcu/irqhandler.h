#ifndef __IRQHANDLER_H__
#define __IRQHANDLER_H__

#include "ES8P508x.h"


/************ÖÐ¶Ïº¯ÊýÉùÃ÷***********/
void  NMI_IRQHandler(void);
void  HardFault_IRQHandler(void);
void  SVC_IRQHandler(void);
void  PendSV_IRQHandler(void);
void  SysTick_IRQHandler(void);
void PINT0_IRQHandler(void);
void PINT2_IRQHandler(void);
void IWDT_IRQHandler(void);


#endif
