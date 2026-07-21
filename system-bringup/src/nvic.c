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