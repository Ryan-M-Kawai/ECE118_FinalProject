
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
#include <bumpers.h>
#define IR_SENSOR_PIN0 AD_PORTV3
#define IR_SENSOR_PIN1 AD_PORTV4
#define IR_SENSOR_PIN2 AD_PORTV5
#define IR_SENSOR_PIN3 AD_PORTV6
#define IR_SENSOR_PIN4 AD_PORTV7
#define IR_SENSOR_PIN5 AD_PORTV8
#define IR_SENSOR_PIN6 AD_PORTW3

#define FR_BUMPER_PIN AD_PORTW8
#define FL_BUMPER_PIN AD_PORTW7
#define BR_BUMPER_PIN AD_PORTW6
#define BL_BUMPER_PIN AD_PORTW5

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
    bumpers_Init();

    //    printf("\r\nHello World!\r\n");
    //    TIMERS_SetTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //
    //        forward(600);
    //    }
    //    stopMotors();
    //    TIMERS_InitTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //
    //        backward(600);
    //    }
    //
    //    stopMotors();
    //    TIMERS_InitTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //
    //        turnLeft(600);
    //    }
    //    stopMotors();
    //    TIMERS_InitTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //        turnRight(600);
    //
    //    }
    //    stopMotors();
    //    TIMERS_InitTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //        strafeRight(600);
    //
    //    }
    //    stopMotors();
    //    TIMERS_InitTimer(1, 3000);
    //    TIMERS_StartTimer(1);
    //    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
    //        strafeLeft(600);
    //
    //    }
    //stopMotors();
    //    
    //static int fr_pressed = 0;
    //static int fl_pressed = 0;
    //static int br_pressed = 0;
    //static int bl_pressed = 0;

    static int fr_prev = 0, fl_prev = 0, br_prev = 0, bl_prev = 0;
    static int fr_cnt = 0, fl_cnt = 0, br_cnt = 0, bl_cnt = 0;
    while (1) {

        check_FR();
        check_FL();
        check_BR();
        check_BL();

    }
    return 0;
}