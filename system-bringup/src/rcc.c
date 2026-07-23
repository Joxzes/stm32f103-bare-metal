#include <stdint.h>
#include "rcc.h"

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

void tim_clock_en(uint8_t tim) {
    if ((tim > 4u) || (tim < 2)) {
        return;
    }

    RCC->APB1ENR |= (1u << (tim - 2u));
}

void afio_clock_enable(void) {
    RCC->APB2ENR |= 1u;
}