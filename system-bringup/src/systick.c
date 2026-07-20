#include <stdint.h>
#include "systick.h"

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} STK_registers;

#define STK ((STK_registers *)0xE000E010u)

static volatile uint32_t ticks = 0u;

void systick_init(void) {
    STK->CTRL = 0u;

    STK->LOAD = 0x1193Fu;

    STK->VAL = 0u;

    STK->CTRL |= (1u << 2);
    STK->CTRL |= (1u << 1);
    STK->CTRL |= 1u;
}

void SysTick_Handler(void)
{
    ticks++;
}

void delay(uint32_t ms) {
    uint32_t start = ticks;

    while ((ticks - start) < ms) {
    }
}