/*
 * retarget.c
 *
 *  Created on: Aug 25, 2020
 */

#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "retarget.h"
#include "usart.h"

/*
 * @brief   Retargets the C library printf function to the USART
 * @param   None
 * @retval  None
 */

PUTCHAR_PROTOTYPE
{
  if (ch == '\n')
    HAL_UART_Transmit(DBG_UART, (uint8_t *)"\r", 1, HAL_MAX_DELAY);

  HAL_UART_Transmit(DBG_UART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

  return ch;
}
