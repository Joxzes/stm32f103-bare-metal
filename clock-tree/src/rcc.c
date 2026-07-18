#include <stdint.h>

typedef struct {
    volatile uint32_t CR;
} RCC_registers;

#define RCC ((RCC_registers *)0x40021000u)

void rcc_hse_start(void) {
    RCC->CR |= (1u << 16);
}




