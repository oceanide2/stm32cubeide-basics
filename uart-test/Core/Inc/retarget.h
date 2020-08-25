/*
 * retarget.h
 *
 *  Created on: Aug 25, 2020
 */

#ifndef _RETARGET_H
#define _RETARGET_H

#define DBG_UART  &huart1

// Add syscalls.c with GCC

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker -> Libraries -> Small printf
 * set to 'Yes') calls __io_putchar()
 */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#endif /* _RETARGET_H */
