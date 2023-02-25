# include "./uart/bsp_uart.h"

char dat;

/**
 *  @brief  ���ڳ�ʼ��
 *  @param  ��
 *  @retval ��
 */
void uart_Config(void){

  TMOD = 0x20;
  SCON = 0x50;

  TH1 = 0xFD;
  TL1 = 0xFD;
  SCON |= 0x02;
  ES=1;		
  EA=1;		
  TR1=1;
  EA = 1;
}

void uart() interrupt 4 {

  RI = 0;			
  dat = SBUF;
}
