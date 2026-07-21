#include <stdint.h>
#include "stm32f103.h"

void exti_configure_line(uint8_t line, exti_trigger_t trigger) {
    if (line > 15u) {
        return;
    }

    EXTI->IMR &= ~(1u << line);

    switch (trigger) {
        case RISING:
            EXTI->FTSR &= ~(1u << line);
            EXTI->RTSR |= (1u << line);
            break;

        case FALLING:
            EXTI->RTSR &= ~(1u << line);
            EXTI->FTSR |= (1u << line);
            break;

        default: 
            return;
    }

    EXTI->PR = (1u << line);
    EXTI->IMR |= (1u << line);
}