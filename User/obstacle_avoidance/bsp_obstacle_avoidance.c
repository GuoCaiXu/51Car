# include "./obstacle_avoidance/bsp_obstacle_avoidance.h"
# include "intrins.h"
# include "./car/bsp_car.h"

void  trigger(void) 		         //����ģ��
  {
    TRIG = 0;
    TRIG = 1;			                     //����һ��ģ��
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    TRIG = 0;
  }

uint16_t calc(void){

    uint16_t duration, distance;
    duration = TH0 * 256 + TL0;
    duration *= 12/11.0592;

    distance = duration * 0.017;
    TH0 = 0;
    TL0 = 0;

    return distance;
}

uint16_t loop(void){

    uint16_t distance = 0, i = 0;

    trigger();
    while(!ECHO){
        i ++;
        if (i == 1000){
            break;
        }
    }
    i = 0;
    TR0 = 1;
    while(ECHO){
        i ++;
        if (i == 1000){
            break;
        }
    }
    TR0 = 0;
    distance = calc();
    delay_1ms(10);

    return distance;
}

void Obsacle_Avoidance(void){

    uint16_t left, right;
    car_forward();
    if (loop() <= 30){
        car_retreat();
        delay(4000);
        car_left();
        delay(4000);
        car_stop();
        left = loop();
        car_right();
        delay(8000);
        car_stop();
        right = loop();

        if (left >= right){
            car_left();
            delay(8000);
            car_stop();
            car_forward();
        }
    }
}
