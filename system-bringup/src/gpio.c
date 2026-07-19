#include <stdint.h>
#include "gpio.h"

void gpio_config(GPIO_TypeDef *port, uint32_t pin, gpio_mode_t mode) {
    volatile uint32_t *config_register;
    uint32_t position;
    uint32_t configuration;

    if ((port == 0) || (pin > 15u)) {
        return;
    }

    if (pin <= 7u) {
        config_register = &port->CRL;
        position = pin * 4u;
    } else {
        config_register = &port->CRH;
        position = (pin - 8u) * 4u;
    }

    switch (mode) {
        case GPIO_INPUT_ADC:
            configuration = 0x0u;
            break;

        case GPIO_INPUT_PULLDOWN:
            configuration = 0x8u;
            port->BRR = (1u << pin);
            break;

        case GPIO_INPUT_PULLUP:
            configuration = 0x8u;
            port->BSRR = (1u << pin);
            break;

        case GPIO_OUTPUT:
            configuration = 0x2u;
            break;

        default:
            return;
    }

    *config_register &= ~(0xFu << position);
    *config_register |=  (configuration << position);
}