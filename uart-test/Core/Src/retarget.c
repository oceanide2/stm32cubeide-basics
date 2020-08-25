/*
 * retarget.c
 *
 *  Created on: Aug 25, 2020
 */

#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "retarget.h"
#include "usart.h"

int __io_putchar(int ch)
{
  uint8_t c[1];
  c[0] = ch & 0x00FF;

  HAL_UART_Transmit(DBG_UART, &*c, 1, 10);
  return ch;
}

int _write(int file, char *ptr, int len)
{
  int i;

  for (i = 0; i < len; i++)
  {
    __io_putchar(*ptr++);
  }

  return len;
}
