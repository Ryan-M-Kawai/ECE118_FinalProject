
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
#include <solenoidTest.h>


int main(void) {
    // Initialize hardware

    BOARD_Init();
    SERIAL_Init();
    TIMERS_Init();
    Motors_Init();
    bumpers_Init();
    IRSensor_Init();

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


    //    static int fr_prev = 0, fl_prev = 0, br_prev = 0, bl_prev = 0;
    //    static int fr_cnt = 0, fl_cnt = 0, br_cnt = 0, bl_cnt = 0;
    while (1) {

        check_FR();
        check_FL();
        check_BR();
        check_BL();
        IR_Changed_All();
    }
    return 0;
}