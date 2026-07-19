#include <stdint.h>
#include "systick.h"

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} STK_registers;

#define STK ((STK_registers *)0xE000E010u)

void systick_init(void) {
    STK->CTRL &= ~1u;
    STK->LOAD = 0x1193Fu;
    STK->VAL = 1u;
    STK->CTRL |= (1u << 2);
    STK->CTRL &= ~(1u << 1);
    STK->CTRL |= 1u;
}

void delay(uint32_t ms) {
    while (ms > 0u) {
        if ((STK->CTRL & (1u << 16)) != 0u) {
            ms--;
        }
    }
}