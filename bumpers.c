#include <BOARD.h>
#include <serial.h>
#include <ad.h>
#include <stdio.h>
#include <timers.h>
#define FR_PIN AD_PORTW6
#define FL_PIN AD_PORTW5
#define BR_PIN AD_PORTW7
#define BL_PIN AD_PORTW8

#define HIGH_THRESHOLD 700
#define LOW_THRESHOLD 300
#define DEBOUNCE_MS 10

static int fr_pressed = 0;
static int fl_pressed = 0;
static int br_pressed = 0;
static int bl_pressed = 0;
void bumpers_Init() {
    
    AD_AddPins(FR_PIN);
    AD_AddPins(FL_PIN);
    AD_AddPins(BR_PIN);
    AD_AddPins(BL_PIN);
    if (AD_AddPins(FR_PIN | FL_PIN | BR_PIN | BL_PIN) == ERROR) {
        printf("AD_AddPins failed\r\n");
    }
}
static int stays_past(unsigned int pin, int wantPressed)
{
    unsigned int start = TIMERS_GetTime();

    while ((TIMERS_GetTime() - start) < DEBOUNCE_MS) {
        int v = (int)AD_ReadADPin(pin);
        if (wantPressed && v <= HIGH_THRESHOLD) {
            return 0;
        }
        if (!wantPressed && (v < 0 || v >= LOW_THRESHOLD)) {
            return 0;
        }
    }
    return 1;
}
//
//int check_bumper(unsigned int pin, int wasPressed, char *name)
//{
//    int value = (int)AD_ReadADPin(pin);
//    int printed = 0;
//    if (value < 0) {                       // ERROR: pin not active
//        return wasPressed;
//    }
//
//    if (wasPressed == 0 && value > HIGH_THRESHOLD && stays_past(pin, 1)) {
//        printf("%s PRESSED\r\n", name);
//        printed = 1;
//        return 1;
//    }
//    if (wasPressed == 1 && value < LOW_THRESHOLD && stays_past(pin, 0)) {
//        printf("%s RELEASED\r\n", name);
//        return 0;
//    }
//    return wasPressed;                     // no change
//}
//int check_bumper(unsigned int pin, int wasPressed, char *name)
//{
//    int value = (int)AD_ReadADPin(pin);
//    int isPressed;
//
//    if (value < 0) {                 // ERROR: pin not active
//        return wasPressed;
//    }
//
//    isPressed = (value > HIGH_THRESHOLD);
//
//    if (isPressed != wasPressed) {   // crossed the boundary
//        if (isPressed) {
//            printf("%s PRESSED\r\n", name);
//        } else {
//            printf("%s RELEASED\r\n", name);
//        }
//    }
//    return isPressed;                // becomes wasPressed next call
//}

static int read_bumper(unsigned int pin)
{
    int value = (int)AD_ReadADPin(pin);
    if (value < 0) {
        return -1;
    }
    return (value > HIGH_THRESHOLD);
}

void check_FR(void)
{
    static int prev = 0;
    static int count = 0;
    int curr = read_bumper(FR_PIN);

    if (curr < 0) return;

    if (curr == prev) {
        count = 0;
    } else {
        count++;
        if (count >= DEBOUNCE_MS) {
            prev = curr;
            count = 0;
            if (curr) printf("FR PRESSED\r\n");
            else      printf("FR RELEASED\r\n");
        }
    }
}

void check_FL(void)
{
    static int prev = 0;
    static int count = 0;
    int curr = read_bumper(FL_PIN);

    if (curr < 0) return;

    if (curr == prev) {
        count = 0;
    } else {
        count++;
        if (count >= DEBOUNCE_MS) {
            prev = curr;
            count = 0;
            if (curr) printf("FL PRESSED\r\n");
            else      printf("FL RELEASED\r\n");
        }
    }
}

void check_BR(void)
{
    static int prev = 0;
    static int count = 0;
    int curr = read_bumper(BR_PIN);

    if (curr < 0) return;

    if (curr == prev) {
        count = 0;
    } else {
        count++;
        if (count >= DEBOUNCE_MS) {
            prev = curr;
            count = 0;
            if (curr) printf("BR PRESSED\r\n");
            else      printf("BR RELEASED\r\n");
        }
    }
}

void check_BL(void)
{
    static int prev = 0;
    static int count = 0;
    int curr = read_bumper(BL_PIN);

    if (curr < 0) return;

    if (curr == prev) {
        count = 0;
    } else {
        count++;
        if (count >= DEBOUNCE_MS) {
            prev = curr;
            count = 0;
            if (curr) printf("BL PRESSED\r\n");
            else      printf("BL RELEASED\r\n");
        }
    }
}