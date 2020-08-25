/*
 * retarget.h
 *
 *  Created on: Aug 25, 2020
 */

#ifndef _RETARGET_H
#define _RETARGET_H

#define DBG_UART  &huart1

int __io_putchar(int ch);
int _write(int file, char *ptr, int len);

#endif /* _RETARGET_H */
