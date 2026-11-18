#include <BOARD.h>
#include <IO_Ports.h>
#include <timers.h>

#define SOLENOID_PORT PORTX
#define SOLENOID_PIN  PIN3

int main(void)
{
    BOARD_Init();
    TIMERS_Init();

    // Configure solenoid control pin as an output.
    IO_PortsSetPortOutputs(SOLENOID_PORT, SOLENOID_PIN);

    // Start with the solenoid OFF.
    IO_PortsClearPortBits(SOLENOID_PORT, SOLENOID_PIN);

    while (1)
    {
        // Turn solenoid ON.
        IO_PortsSetPortBits(SOLENOID_PORT, SOLENOID_PIN);

        // Keep it ON for 50 ms.
        TIMERS_SetTimer(1, 50);
        TIMERS_StartTimer(1);

        while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED)
        {
        }

        // Turn solenoid OFF.
        IO_PortsClearPortBits(SOLENOID_PORT, SOLENOID_PIN);

        // Wait 3 seconds before firing again.
        TIMERS_SetTimer(1, 3000);
        TIMERS_StartTimer(1);

        while (TIMERS_IsTimerExpired(1) != TIMER_EXPIRED)
        {
        }
    }
}