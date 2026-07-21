#include <stdint.h>
#include "systick.h"

static volatile uint32_t ticks = 0u;

void systick_init(void) {
    STK->CTRL = 0u;

    STK->LOAD = 0x1193Fu;

    STK->VAL = 0u;

    STK->CTRL |= (1u << 2);
    STK->CTRL |= (1u << 1);
    STK->CTRL |= 1u;
}

void SysTick_Handler(void) {
    ticks++;
}

uint32_t millis(void) {
    return ticks;
}

void delay(uint32_t ms) {
    uint32_t start = ticks;

    while ((ticks - start) < ms) {
    }
}