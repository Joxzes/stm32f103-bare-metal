#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t *)0x40021018u)
#define GPIOC_CRH (*(volatile uint32_t *)0x40011004u)
#define GPIOC_IDR (*(volatile uint32_t *)0x40011008u)
#define GPIOC_ODR (*(volatile uint32_t *)0x4001100Cu)
#define GPIOC_BSRR (*(volatile uint32_t *)0x40011010u)

int main(void) {
    RCC_APB2ENR |= (1u << 4);

    GPIOC_CRH &= ~(0xFu << 20);
    GPIOC_CRH |= (0x2u << 20);

    GPIOC_CRH &= ~(0xFu << 28);
    GPIOC_CRH |= (0x8u << 28);

    GPIOC_BSRR = (1u << 31);

    for (;;) {
        if ((GPIOC_IDR & (1u << 15)) == 0u) {
            GPIOC_BSRR = (1u << 13);
        } else {
            GPIOC_BSRR = (1u << 29);
        }
    }
}