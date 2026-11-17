#include <BOARD.h>
#include <IO_Ports.h>
#include <pwm.h>
#include <AD.h>
#define MOTOR_SPEED 600

//PWM_PORTY12 doesnt work.
#define MOTOR_PWM_FL PWM_PORTZ06 // front left 1 in runmotor
#define MOTOR_PWM_FR PWM_PORTY10 // front right 2 in runmotor
#define MOTOR_PWM_BL PWM_PORTX11 // back left 3 in runmotor
#define MOTOR_PWM_BR PWM_PORTY04 // back right 4 in runmotor

#define FRONT_MOTORS_IO_PIN PORTZ
#define BACK_MOTORS_IO_PIN PORTY

//LEFT
#define IO1_Input1 PIN3
#define IO1_Input2 PIN5

//RIGHT
#define IO2_Input1 PIN7
#define IO2_Input2 PIN9



//
//
//int main(void)
//{
//    BOARD_Init();
//    PWM_Init();
//
//    //direction pins
//    IO_PortsSetPortOutputs(PORTZ, PIN3 | PIN5 | PIN7 | PIN9);
//    IO_PortsSetPortOutputs(PORTY, PIN3 | PIN5 | PIN7 | PIN9);
//
//    PWM_AddPins(PWM_PORTZ06 | PWM_PORTY12 | PWM_PORTY10 | PWM_PORTY04);
//    //front left
//    IO_PortsSetPortBits(PORTZ, PIN3);
//    IO_PortsClearPortBits(PORTZ, PIN5);
//    //back left
//    IO_PortsSetPortBits(PORTZ, PIN7);
//    IO_PortsClearPortBits(PORTZ, PIN9);
//
//    //front right
//    IO_PortsClearPortBits(PORTY, PIN3);
//    IO_PortsSetPortBits(PORTY, PIN5);
//    //back right
//    IO_PortsClearPortBits(PORTY, PIN7);
//    IO_PortsSetPortBits(PORTY, PIN9);
//
//    PWM_SetDutyCycle(PWM_PORTZ06, MOTOR_SPEED);
//    PWM_SetDutyCycle(PWM_PORTY12, MOTOR_SPEED);
//    PWM_SetDutyCycle(PWM_PORTY10, MOTOR_SPEED);
//    PWM_SetDutyCycle(PWM_PORTY04, MOTOR_SPEED);
//
//    while (1)
//    {
//    }
//
//    return 0;
//}

void Motors_Init() {
    BOARD_Init();
    PWM_Init();

    //direction pins
    IO_PortsSetPortOutputs(FRONT_MOTORS_IO_PIN, PIN3 | PIN5 | PIN7 | PIN9);
    IO_PortsSetPortOutputs(BACK_MOTORS_IO_PIN, PIN3 | PIN5 | PIN7 | PIN9);

    PWM_AddPins(MOTOR_PWM_FL | MOTOR_PWM_FR | MOTOR_PWM_BR | MOTOR_PWM_BL);
    PWM_SetFrequency(PWM_1KHZ);
}
//void runMotor(int motor, int speed, int direction)
//// 1 0 forward
//// 0 1 backward
//{
//    switch (motor)
//    {
//        case 1: // front left
//            if (direction == 1)
//            {
//                IO_PortsSetPortBits(FRONT_MOTORS_IO_PIN, IO1_Input2);
//                IO_PortsClearPortBits(FRONT_MOTORS_IO_PIN, IO1_Input1);
//            }
//            else
//            {
//                IO_PortsClearPortBits(FRONT_MOTORS_IO_PIN, IO1_Input1);
//                IO_PortsSetPortBits(FRONT_MOTORS_IO_PIN, IO1_Input2);
//            }
//            PWM_SetDutyCycle(MOTOR_PWM_FL, speed);
//            break;
//
//        case 2: // back left
//            if (direction == 1)
//            {
//                IO_PortsSetPortBits(BACK_MOTORS_IO_PIN, IO1_Input2);
//                IO_PortsClearPortBits(BACK_MOTORS_IO_PIN, IO1_Input1);
//            }
//            else
//            {
//                IO_PortsClearPortBits(BACK_MOTORS_IO_PIN, IO2_Input2);
//                IO_PortsSetPortBits(BACK_MOTORS_IO_PIN, IO2_Input1);
//            }
//            PWM_SetDutyCycle(MOTOR_PWM_BL, speed);
//            break;
//        case 3: // front right
//            if (direction == 1)
//            {
//                IO_PortsClearPortBits(FRONT_MOTORS_IO_PIN, IO2_Input1);
//                IO_PortsSetPortBits(FRONT_MOTORS_IO_PIN, IO2_Input2);
//            }
//            else
//            {
//                IO_PortsSetPortBits(FRONT_MOTORS_IO_PIN, IO2_Input2);
//                IO_PortsClearPortBits(FRONT_MOTORS_IO_PIN, IO2_Input1);
//            }
//            PWM_SetDutyCycle(MOTOR_PWM_FR, speed);
//            break;
//        case 4: // back right
//            if (direction == 1)
//            {
//                IO_PortsClearPortBits(BACK_MOTORS_IO_PIN, IO2_Input1);
//                IO_PortsSetPortBits(BACK_MOTORS_IO_PIN, IO2_Input2 );
//            }
//            else
//            {
//                IO_PortsSetPortBits(BACK_MOTORS_IO_PIN, IO2_Input2);
//                IO_PortsClearPortBits(BACK_MOTORS_IO_PIN, IO2_Input1);
//            }
//            PWM_SetDutyCycle(MOTOR_PWM_BR, speed);
//            break;
//        default:
//            break;
//    }
//}

static void setDirection(int8_t port, uint16_t in1, uint16_t in2, int dir) {
    if (dir == 1) { // forward
        IO_PortsClearPortBits(port, in1);
        IO_PortsSetPortBits(port, in2);
    } else { // reverse
        IO_PortsClearPortBits(port, in2);
        IO_PortsSetPortBits(port, in1);
    }
}

// 1 2
// 3 4   (FL FR / BL BR)

void runMotor(int motor, int speed, int direction) {
    switch (motor) {
        case 1: // front left
            setDirection(FRONT_MOTORS_IO_PIN, IO1_Input1, IO1_Input2, direction);
            PWM_SetDutyCycle(MOTOR_PWM_FL, speed);
            break;
        case 2: // front right
            setDirection(FRONT_MOTORS_IO_PIN, IO2_Input1, IO2_Input2, direction);
            PWM_SetDutyCycle(MOTOR_PWM_FR, speed);
            break;
        case 3: // back left
            setDirection(BACK_MOTORS_IO_PIN, IO1_Input1, IO1_Input2, direction);
            PWM_SetDutyCycle(MOTOR_PWM_BL, speed);
            break;
        case 4: // back right
            setDirection(BACK_MOTORS_IO_PIN, IO2_Input1, IO2_Input2, direction);
            PWM_SetDutyCycle(MOTOR_PWM_BR, speed);
            break;
        default:
            break;
    }
}
// 1 2
// 3 4

void forward(int speed) {
    runMotor(1, speed, 1);
    runMotor(2, speed, 1);
    runMotor(3, speed, 1);
    runMotor(4, speed, 1);
}

void backward(int speed) {
    runMotor(1, speed, 0);
    runMotor(2, speed, 0);
    runMotor(3, speed, 0);
    runMotor(4, speed, 0);
}

void turnLeft(int speed) {
    runMotor(1, speed, 0);
    runMotor(2, speed, 1);
    runMotor(3, speed, 0);
    runMotor(4, speed, 1);
}

void turnRight(int speed) {
    runMotor(1, speed, 1);
    runMotor(2, speed, 0);
    runMotor(3, speed, 1);
    runMotor(4, speed, 0);
}

void strafeLeft(int speed) {
    runMotor(1, speed, 0);
    runMotor(2, speed, 1);
    runMotor(3, speed, 1);
    runMotor(4, speed, 0);
}

void strafeRight(int speed) {
    runMotor(1, speed, 1);
    runMotor(2, speed, 0);
    runMotor(3, speed, 0);
    runMotor(4, speed, 1);
}

void strafeForwardLeft(int speed) {
    runMotor(2, speed, 1);
    runMotor(3, speed, 1);
}

void strafeForwardRight(int speed) {
    runMotor(1, speed, 1);
    runMotor(4, speed, 1);
}

void strafeBackwardLeft(int speed) {
    runMotor(1, speed, 0);

    runMotor(4, speed, 0);
}

void strafeBackwardRight(int speed) {
    runMotor(2, speed, 0);
    runMotor(3, speed, 0);
}

void stopMotors() {
    PWM_SetDutyCycle(MOTOR_PWM_FL, 0);
    PWM_SetDutyCycle(MOTOR_PWM_FR, 0);
    PWM_SetDutyCycle(MOTOR_PWM_BL, 0);
    PWM_SetDutyCycle(MOTOR_PWM_BR, 0);
}