/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
 #include <stdint.h>
 extern uint32_t SystemCoreClock;
#endif

/* 配置1：使能抢占式调度器；配置0：使能合作式调度器*/
#define configUSE_PREEMPTION			1

/* 此参数用于定义 CPU 的主频，单位 Hz*/
#define configCPU_CLOCK_HZ				(SystemCoreClock)

/* 此参数用于定义系统时钟节拍数，单位 Hz*/
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )

/* 此参数用于定义可供用户使用的最大优先级数，如果这个定义的是 5，那么用户可以使用的优先级号是 0,1,2,3,4，不包含 5*/
#define configMAX_PRIORITIES			( 3 )

/* 此参数用于定义空闲任务的栈空间大小，单位字，即 4 字节。*/
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 64 )

/* 定义堆大小,FreeRTOS 内核,用户动态内存申请,任务栈,任务创建,信号量创建,消息队列创建等都需要用这个空间,单位字节,即1个字节*/
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 15360) )//15K

/* 定义任务名最大的字符数，末尾的结束符 '\0'也要计算在内*/
#define configMAX_TASK_NAME_LEN			( 16 )

/* 使能此配置将添加额外的结构体成员和函数，以此来协助可视化和跟踪，在使用 IAR 中的 FreeRTOS插件时要使能这个配置，
** 否则无法显示任务栈的使用情况。*/
#define configUSE_TRACE_FACILITY		0

/* 系统时钟节拍计数使用 TickType_t 数据类型定义的。如果用户使能了宏定义 configUSE_16_BIT_TICKS，
** 那么 TickType_t 定义的就是 16 位无符号数，如果没有使能，那么 TickType_t 定义的就是 32 位无符号数。
** 对于 32 位架构的处理器，一定要禁止此宏定义，即设置此宏定义数值为 0 即可。 而 16 位无符号数类型主
** 要用于 8 位和 16 位架构的处理器。*/
#define configUSE_16_BIT_TICKS			0

/* 此参数用于使能与空闲任务同优先级的任务，只有满足以下两个条件时，此参数才有效果：
** 1. 使能抢占式调度器。
** 2. 有创建与空闲任务同优先级的任务。
** 配置为 1，就可以使能此特性了，实际应用中不建议用户使用此功能，将其配置为 0 即可 */
#define configIDLE_SHOULD_YIELD			0

/*配置为1:使能互斥信号量;    配置为0:禁能互斥信号量*/
#define configUSE_MUTEXES				1

/* 配置为1：使能消息队列；配置为0：禁能消息队列 */
#define configUSE_QUEUE_SETS			0

/* 通过此定义来设置可以注册的信号量和消息队列个数。队列注册有两个目的，这两个目的都与内核调试有关：
** 注册队列的时候，可以给队列起一个名字，当使用调试组件的时候，通过名字可以很容易的区分不同队列。
** 通过队列的相关信息，调试器可以很容易定位队列和信号量，能够定位信号量是因为 FreeRTOS 信号量也是
** 基于队列实现的。当然，如果用户没有使用内核方面的调试器，这个宏定义是没有意义的 */
#define configQUEUE_REGISTRY_SIZE		8

/* FreeRTOS 的栈溢出检测支持两种方法，配置为2:栈溢出检测使用方法二 配置为1:栈溢出检测使用方法一。
** 配置为0:禁止栈溢出检测。 */
#define configCHECK_FOR_STACK_OVERFLOW	0

/* 配置为1:使能递归互斥信号量 配置为0:禁能递归互斥信号量 */
#define configUSE_RECURSIVE_MUTEXES		1

/* 当创建任务，信号量或者消息队列时，FreeRTOS 通过函数 pvPortMalloc()申请动态内存。
** 配置为1:使能动态内存申请失败时的钩子函数
** 配置为0:禁能动态内存申请失败时的钩子函数 */
#define configUSE_MALLOC_FAILED_HOOK	0

/* 空闲任务的钩子函数，钩子函数的主要功能是用于函数的扩展 */
#define configUSE_IDLE_HOOK				0

/* 使能滴答定时器中断里面执行的钩子函数 */
#define configUSE_TICK_HOOK				0

/* 设置为1时 以下函数会被编译
** void vTaskSetApplicationTaskTag( TaskHandle_t xTask, TaskHookFunction_t pxHookFunction )；
** TaskHookFunction_t xTaskGetApplicationTaskTag( TaskHandle_t xTask )；
** BaseType_t xTaskCallApplicationTaskHook( TaskHandle_t xTask, void *pvParameter )；*/
#define configUSE_APPLICATION_TASK_TAG	0

/* 1:使能计数型信号量 相关API函数被编译 */
#define configUSE_COUNTING_SEMAPHORES	1

/* Run time stats related definitions. */
/*void vMainConfigureTimerForRunTimeStats( void );*/
/*unsigned long ulMainGetRunTimeCounterValue( void );*/

/* 配置为1:使能任务运行状态参数统计 */
#define configGENERATE_RUN_TIME_STATS	0

/* 此宏用来初始化一个外设来作为时间统计的基准时钟 */
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() {;}/*vMainConfigureTimerForRunTimeStats()*/

/* 此宏用来返回当前基准时钟的时钟值 */
#define portGET_RUN_TIME_COUNTER_VALUE() ulMainGetRunTimeCounterValue()

/* Co-routine definitions.配置1：启用协程 启用协程以后必须添加文件croutine.c */
#define configUSE_CO_ROUTINES 			0
/* 设置协程的最大优先级，0是最低优先级，configMAX_CO_ROUTINE_PRIORITIES-1是最高优先级 */
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* 配置1：启用软件定时器 */
#define configUSE_TIMERS				1

#define INCLUDE_xTimerPendFunctionCall 1

/* 配置软件定时器任务的优先级 */
#define configTIMER_TASK_PRIORITY		( configMAX_PRIORITIES-1 )

/* 配置软件定时器命令队列的长度 */
#define configTIMER_QUEUE_LENGTH		5

/* 配置软件定时器任务的栈空间大小 */
#define configTIMER_TASK_STACK_DEPTH	( 64 )

/* 是否支持动态分配   配置为0:不支持 配置为1:支持*/
#define configSUPPORT_DYNAMIC_ALLOCATION   1

/* 是否支持静态分配   配置为0:不支持 配置为1:支持*/
#define configSUPPORT_STATIC_ALLOCATION    0

/* 函数 Include 配置主要是指用户可以根据需要使能或者禁止在工程中使用相应的函数，配置为 1，表
** 示使能，即可以在工程中使用相应函数。 配置为 0，表示禁止，即禁止在工程中使用相应函数。可以这样
** 设置的函数主要有如下几种 */
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1
#define INCLUDE_eTaskGetState			1

/* 用户配置宏定义 configUSE_TRACE_FACILITY 和 configUSE_STATS_FORMATTING_FUNCTIONS
** 都为 1 的时候，将使能函数 vTaskList() 和 vTaskGetRunTimeStats()，如果两者中任何一个为 0，那么
** 这两个函数都将被禁能。  */
#define configUSE_STATS_FORMATTING_FUNCTIONS	1

/* 断言函数，调试过程中使用，如果正式发布软件时，请关闭此功能 */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* PendSV中断服务程序 */
#define xPortPendSVHandler PendSV_IRQHandler
#define vPortSVCHandler 	SVC_IRQHandler

/* SysTick中断服务程序 */
#define xPortSysTickHandler SysTick_IRQHandler

/* The size of the global output buffer that is available for use when there
are multiple command interpreters running at once (for example, one on a UART
and one on TCP/IP).  This is done to prevent an output buffer being defined by
each implementation - which would waste RAM.  In this case, there is only one
command interpreter running. */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE 2048

#endif /* FREERTOS_CONFIG_H */

