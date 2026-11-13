#include <BOARD.h>
#include <IO_Ports.h>
#include <pwm.h>

#define MOTOR_SPEED 600

int main(void)
{
    BOARD_Init();
    PWM_Init();

    //direction pins
    IO_PortsSetPortOutputs(PORTZ, PIN3 | PIN5 | PIN7 | PIN9);
    IO_PortsSetPortOutputs(PORTY, PIN3 | PIN5 | PIN7 | PIN9);

    PWM_AddPins(PWM_PORTZ06 | PWM_PORTY12 | PWM_PORTY10 | PWM_PORTY04);
    //front left
    IO_PortsSetPortBits(PORTZ, PIN3);
    IO_PortsClearPortBits(PORTZ, PIN5);
    //back left
    IO_PortsSetPortBits(PORTZ, PIN7);
    IO_PortsClearPortBits(PORTZ, PIN9);

    //front right
    IO_PortsClearPortBits(PORTY, PIN3);
    IO_PortsSetPortBits(PORTY, PIN5);
    //back right
    IO_PortsClearPortBits(PORTY, PIN7);
    IO_PortsSetPortBits(PORTY, PIN9);

    PWM_SetDutyCycle(PWM_PORTZ06, MOTOR_SPEED);
    PWM_SetDutyCycle(PWM_PORTY12, MOTOR_SPEED);
    PWM_SetDutyCycle(PWM_PORTY10, MOTOR_SPEED);
    PWM_SetDutyCycle(PWM_PORTY04, MOTOR_SPEED);

    while (1)
    {
    }

    return 0;
}
