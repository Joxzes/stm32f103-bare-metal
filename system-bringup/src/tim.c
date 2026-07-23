#include <stdint.h>
#include "tim.h"
#include "rcc.h"

void tim_init(uint8_t tim) {
    TIM_TypeDef *tim_t;

    if ((tim > 4u) || (tim < 2)) {
        return;
    }

    tim_clock_en(tim);

    switch (tim) {
        case 2:
            tim_t = TIM2;
            break;
        
        case 3:
            tim_t = TIM3;
            break;

        case 4:
            tim_t = TIM4;
            break;

        default:
            return;
    }

    tim_t->CR1 &= ~1u;
    tim_t->PSC = 71u;
    tim_t->ARR = 999u;
    tim_t->CNT = 0u;

    tim_t->EGR = 1u;
    tim_t->SR = 0u;
    tim_t->CR1 |= 1u;
}