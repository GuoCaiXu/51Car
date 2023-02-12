# include "stc89c52rc.h"
# include "./car/bsp_car.h"
# include "./uart/bsp_uart.h"
# include "stdio.h"

char dat;

void main(void){

    uart_Config();

    while(1){

       if (dat == 'W'){         /*ǰ��*/
        car_stop();
        car_go();
       }
       else if (dat == 'S'){    /*����*/
        car_stop();
        car_back_go();
       }
       else if (dat == 'A'){    /*��ת*/
        car_stop();
        car_left_go();
       }
       else if (dat == 'D'){    /*��ת*/
        car_stop();
        car_right_go();
       }
       else if (dat == 'T'){    /*ֹͣ*/
        car_stop();
       }
    }
}
