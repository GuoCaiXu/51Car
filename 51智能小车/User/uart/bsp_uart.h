# ifndef _BSP_UART_H
# define _BSP_UART_H

# include "stc89c52rc.h"

extern char dat;

/*��дc �����еĿ⺯��*/
int putchar(int c);

/*���ڳ�ʼ��*/
void uart_Config(void);

# endif
