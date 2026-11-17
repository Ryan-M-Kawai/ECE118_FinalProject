
#include <BOARD.h>
#include <AD.h>
#include <serial.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pwm.h>
#include <Motor.h>
#include <tape_detector.h>
#include <timers.h>

#define IR_SENSOR_PIN0 AD_PORTV3
#define IR_SENSOR_PIN1 AD_PORTV4
#define IR_SENSOR_PIN2 AD_PORTV5
#define IR_SENSOR_PIN3 AD_PORTV6
#define IR_SENSOR_PIN4 AD_PORTV7
#define IR_SENSOR_PIN5 AD_PORTV8
#define IR_SENSOR_PIN6 AD_PORTW3

int main(void) {
    // Initialize hardware
    BOARD_Init();
    SERIAL_Init();
    TIMERS_Init();

    //    IRSensor_Init(IR_SENSOR_PIN0);
    //    IRSensor_Init(IR_SENSOR_PIN0);
    //    IRSensor_Init(IR_SENSOR_PIN0);
    //    IRSensor_Init(IR_SENSOR_PIN0);
    //    IRSensor_Init(IR_SENSOR_PIN0);
    //    IRSensor_Init(IR_SENSOR_PIN0);

    Motors_Init();

    printf("\r\nHello World!\r\n");
    TIMERS_SetTimer(1, 3000);
    TIMERS_StartTimer(1);
    forward(600);
    if (TIMERS_IsTimerExpired(1) == TIMER_EXPIRED) {

        stopMotors();
        
    }
    TIMERS_InitTimer(1,3000);
    TIMERS_StartTimer(1);
    backward(600);

    if (TIMERS_IsTimerExpired(1) == TIMER_EXPIRED) {

        stopMotors();
        
    }
    TIMERS_InitTimer(1,3000);
    TIMERS_StartTimer(1);
    turnLeft( 600);

    if (TIMERS_IsTimerExpired(1) == TIMER_EXPIRED) {

        stopMotors();
        
    }

    TIMERS_InitTimer(1,3000);
    TIMERS_StartTimer(1);
    turnRight( 600);
    if (TIMERS_IsTimerExpired(1) == TIMER_EXPIRED) {

        stopMotors();
        
    }
   
    while (1) {

        ;

    }
    return 0;
}