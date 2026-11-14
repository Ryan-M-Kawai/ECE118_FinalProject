
#include <BOARD.h>
#include <AD.h>
#include <serial.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pwm.h>
#define IR_CHANGE_THRESHOLD 100
#define IR_THRESHOLD  100
#define IR_SENSOR_PIN0 AD_PORTV4

#define MOTOR_PWM1 PWM_PORTY10
#define MOTOR_PWM2 PWM_PORTY12

void IRSensor_Init(unsigned int pin) {
    AD_Init();
    AD_AddPins(pin);
    while (!(AD_ActivePins() & pin));
}

uint16_t IRSensor_Read(unsigned int pin) {
    return AD_ReadADPin(pin);
}

float IRSensor_ReadVoltage(unsigned int pin) {
    uint16_t adcValue = IRSensor_Read(pin);
    return ((float) adcValue * 3.3f) / 1023.0f;
}

static void IR_Changed(unsigned int pin) {
    static unsigned char initialized = 0;
    static unsigned char aboveThresholdPrev = 0;

    unsigned int irValue = IRSensor_Read(pin);

    if (!initialized) {
        aboveThresholdPrev = (irValue >= IR_THRESHOLD);
        initialized = 1;
        return;
    }

    unsigned char aboveThresholdCurr = (irValue >= 100);

    // Only print when crossing the 100 threshold
    if (aboveThresholdCurr != aboveThresholdPrev) {
        aboveThresholdCurr = aboveThresholdPrev;

        float voltage = ((float) irValue * 3.3f) / 1023.0f;

        printf("IR crossed 100: %u | Voltage: %.2f V\r\n",
                irValue, (double) voltage);
    }
}

int main(void) {
    // Initialize hardware
    BOARD_Init();
    SERIAL_Init();
    IRSensor_Init(IR_SENSOR_PIN0);

    printf("\r\nHello World!\r\n");
    while (!IsTransmitEmpty());

    while (1) {
        IR_Changed(IR_SENSOR_PIN0);
    }
}