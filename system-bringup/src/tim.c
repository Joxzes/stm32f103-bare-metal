#include <stdint.h>
#include "tim.h"
#include "rcc.h"
#include "nvic.h"

void tim_init(uint8_t tim) {
    TIM_TypeDef *tim_t;
    uint8_t irq;

    if ((tim > 4u) || (tim < 2)) {
        return;
    }

    tim_clock_en(tim);

    switch (tim) {
        case 2:
            tim_t = TIM2;
            irq = 28u;
            break;
        
        case 3:
            tim_t = TIM3;
            irq = 29u;
            break;

        case 4:
            tim_t = TIM4;
            irq = 30u;
            break;

        default:
            return;
    }

    tim_t->CR1 &= ~1u;
    tim_t->DIER &= ~1u;

    tim_t->PSC = 71u;
    tim_t->ARR = 999u;
    tim_t->CNT = 0u;

    tim_t->EGR = 1u;
    tim_t->SR = 0u;

    tim_t->DIER |= 1u;
    nvic_enable_irq(irq);

    tim_t->CR1 |= 1u;
}