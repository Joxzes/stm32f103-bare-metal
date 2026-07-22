#include <stdint.h>
#include "nvic.h"

void nvic_enable_irq(uint8_t irq) {
    if (irq > 42u) {
        return;
    }

    uint8_t index = irq / 32u;
    uint8_t position = irq % 32u;

    NVIC->ISER[index] = (1u << position);
}

void nvic_set_priority(uint8_t irq, uint8_t priority) {
    if ((irq > 42u) || (priority > 15u)) {
        return;
    }

    NVIC->IPR[irq] = (uint8_t)(priority << 4);
}