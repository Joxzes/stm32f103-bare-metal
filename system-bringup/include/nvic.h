#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>
#include "stm32f103.h"

void nvic_enable_irq(uint8_t irq);
// void nvic_disable_irq(uint8_t irq);
// void nvic_set_pending_irq(uint8_t irq);
// void nvic_clear_pending_irq(uint8_t irq);
// void nvic_set_priority(uint8_t irq, uint8_t priority);

#endif