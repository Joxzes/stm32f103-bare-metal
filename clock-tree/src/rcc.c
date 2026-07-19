#include "rcc.h"
#include <stdint.h>

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
} RCC_registers;

typedef struct {
    volatile uint32_t ACR;
} FLASH_registers;

#define RCC ((RCC_registers *)0x40021000u)
#define FLASH ((FLASH_registers *)0X40022000u)

void clock_tree_init(void) {

    /* HSE */
    RCC->CR |= (1u << 16);

    while ((RCC->CR & (1u << 17)) == 0u) {
    }

    /* LATENCY */
    FLASH->ACR &= ~0x7u;
    FLASH->ACR |= 0x2u;

    /* HPRE - AHB */
    RCC->CFGR &= ~(0xFu << 4);

    /* PPRE1 - APB1 */
    RCC->CFGR &= ~(0x7u << 8);
    RCC->CFGR |= (0x4u << 8);

    /* PPRE2 - APB2 */
    RCC->CFGR &= ~(0x7u << 11);

    /* ADCPRE - ADC */
    RCC->CFGR &= ~(0x3u << 14);
    RCC->CFGR |= (0x2u << 14);

    /* PLLXTPRE */
    RCC->CFGR &= ~(1u << 17);

    /* PLLSRC */
    RCC->CFGR |= (1u << 16);

    /* PLLMUL */
    RCC->CFGR &= ~(0xFu << 18);
    RCC->CFGR |= (0x7u << 18);

    /* PLL */
    RCC->CR |= (1u << 24);

    while ((RCC->CR & (1u << 25)) == 0u) {
    }

    /* SW */
    RCC->CFGR &= ~0x3u;
    RCC->CFGR |= 0x2u;

    while (((RCC->CFGR >> 2) & 0x3u) != 0x2u) {
    }

    /* Optional - HSION/OFF */
    RCC->CR &= ~1u;
}