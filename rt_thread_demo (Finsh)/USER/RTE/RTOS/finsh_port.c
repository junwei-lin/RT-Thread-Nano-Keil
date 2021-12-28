/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rthw.h>
#include <rtconfig.h>
#include <stm32f10x.h>
#ifndef RT_USING_FINSH
#error Please uncomment the line <#include "finsh_config.h"> in the rtconfig.h 
#endif

#ifdef RT_USING_FINSH

char rt_hw_console_getchar(void)
{
    /* Note: the initial value of ch must < 0 */

//#error "TODO 4: Read a char from the uart and assign it to 'ch'."

    int ch = -1;
 
    if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
    {
        ch = USART_ReceiveData(USART1) & 0xFF;
    }
    else
    {
        if(USART_GetFlagStatus(USART1, USART_FLAG_ORE) != RESET)
        {
            USART_ClearITPendingBit(USART1, USART_FLAG_ORE);
        }
        rt_thread_mdelay(10);
    }
    
    return ch;
}

#endif /* RT_USING_FINSH */

