#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t *)0x40021018u)
#define GPIOC_CRH (*(volatile uint32_t *)0x40011004u)
#define GPIOC_ODR (*(volatile uint32_t *)0x4001100Cu)
#define GPIOC_BSRR (*(volatile uint32_t *)0x40011010u)

int main(void) {
    RCC_APB2ENR |= (1u << 4);

    GPIOC_CRH &= ~(0xFu << 20);
    GPIOC_CRH |= (0x2u << 20);

    for (;;) {
        GPIOC_BSRR = (1u << 29);

        for (volatile uint32_t i = 0; i < 500000u; i++) {
        }

        GPIOC_BSRR = (1u << 13);

        for (volatile uint32_t i = 0; i < 500000u; i++) {
        }
    }
}