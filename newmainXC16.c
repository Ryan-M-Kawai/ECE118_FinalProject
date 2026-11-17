
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

#define FR_BUMPER_PIN AD_PORTW6
#define FL_BUMPER_PIN AD_PORTW5
#define BR_BUMPER_PIN AD_PORTW8
#define BL_BUMPER_PIN AD_PORTW7

static int fr_pressed = 0;
static int fl_pressed = 0;
static int br_pressed = 0;
static int bl_pressed = 0;
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
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {

        forward(600);
    }
    stopMotors();
    TIMERS_InitTimer(1, 3000);
    TIMERS_StartTimer(1);
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {

        backward(600);
    }

    stopMotors();
    TIMERS_InitTimer(1, 3000);
    TIMERS_StartTimer(1);
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {

        turnLeft(600);
    }
    stopMotors();
    TIMERS_InitTimer(1, 3000);
    TIMERS_StartTimer(1);
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
        turnRight(600);

    }
    stopMotors();
    TIMERS_InitTimer(1, 3000);
    TIMERS_StartTimer(1);
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
        strafeRight(600);

    }
    stopMotors();
    TIMERS_InitTimer(1, 3000);
    TIMERS_StartTimer(1);
    while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED) {
        strafeLeft(600);

    }
    stopMotors();
    while (1) {

        if (AD_IsNewDataReady() == TRUE) {
            fr_pressed = check_bumper(FR_BUMPER_PIN, fr_pressed, "FR");
            fl_pressed = check_bumper(FL_BUMPER_PIN, fl_pressed, "FL");
            br_pressed = check_bumper(BR_BUMPER_PIN, br_pressed, "BR");
            bl_pressed = check_bumper(BL_BUMPER_PIN, bl_pressed, "BL");
        }

    }
    return 0;
}