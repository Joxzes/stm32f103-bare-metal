#include <stdint.h>
#include "rcc.h"

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t ACR;
} FLASH_registers;

#define RCC ((RCC_TypeDef *)0x40021000u)
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

void gpio_clock_enable(GPIO_TypeDef *port) {
    if (port == GPIOA) {
        RCC->APB2ENR |= (1u << 2);
    } else if (port == GPIOB) {
        RCC->APB2ENR |= (1u << 3);
    } else if (port == GPIOC) {
        RCC->APB2ENR |= (1u << 4);
    } else if (port == GPIOD) {
        RCC->APB2ENR |= (1u << 5);
    } else if (port == GPIOE) {
        RCC->APB2ENR |= (1u << 6);
    } else if (port == GPIOF) {
        RCC->APB2ENR |= (1u << 7);
    } else if (port == GPIOG) {
        RCC->APB2ENR |= (1u << 8);
    }
}