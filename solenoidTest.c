#include <BOARD.h>
#include <IO_Ports.h>
#include <timers.h>

#define FLYWHEEL_PORT PORTX
#define FLYWHEEL_PIN  PIN3

#define ON_TIME  10000  // 10 seconds
#define OFF_TIME 10000  // 10 seconds

int main(void)
{
    BOARD_Init();
    TIMERS_Init();

    // Set X3 as a digital output
    IO_PortsSetPortOutputs(FLYWHEEL_PORT, FLYWHEEL_PIN);

    // Start with flywheel OFF
    IO_PortsClearPortBits(FLYWHEEL_PORT, FLYWHEEL_PIN);

    while (1)
    {
        // Turn flywheel ON
        IO_PortsSetPortBits(FLYWHEEL_PORT, FLYWHEEL_PIN);

        TIMERS_SetTimer(1, ON_TIME);
        TIMERS_StartTimer(1);

        while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED)
        {
        }

        // Turn flywheel OFF
        IO_PortsClearPortBits(FLYWHEEL_PORT, FLYWHEEL_PIN);

        TIMERS_SetTimer(1, OFF_TIME);
        TIMERS_StartTimer(1);

        while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED)
        {
        }
    }

    return 0;
}