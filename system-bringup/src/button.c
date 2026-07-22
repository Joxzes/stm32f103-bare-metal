#include <stdint.h>
#include "stm32f103.h"
#include "gpio.h"
#include "afio.h"
#include "exti.h"
#include "nvic.h"

static volatile uint8_t pressed = 0u;

void EXTI15_10_IRQHandler(void) {
    if ((EXTI->PR & (1u << 15)) != 0u) {
        EXTI->PR = (1u << 15);
        pressed = 1u;
    }
}

void button_config(GPIO_TypeDef *port, uint8_t line) {
    afio_port_t afio_port;
    uint8_t irq;

    if (line > 15u) {
        return;
    }

    if (port == GPIOA) {
        afio_port = AFIO_PORT_A;
    } else if (port == GPIOB) {
        afio_port = AFIO_PORT_B;
    } else if (port == GPIOC) {
        afio_port = AFIO_PORT_C;
    } else if (port == GPIOD) {
        afio_port = AFIO_PORT_D;
    } else if (port == GPIOE) {
        afio_port = AFIO_PORT_E;
    } else if (port == GPIOF) {
        afio_port = AFIO_PORT_F;
    } else if (port == GPIOG) {
        afio_port = AFIO_PORT_G;
    } else {
        return;
    }

    gpio_config(port, line, GPIO_INPUT_PULLUP);
    afio_exti_select(line, afio_port);

    if (line <= 4u) {
        irq = line + 6u;
    } else if (line <= 9u) {
        irq = 23u;
    } else {
        irq = 40u;
    } 

    exti_configure_line(line, FALLING);
    nvic_set_priority(irq, 2u);
    nvic_enable_irq(irq);
}

uint8_t button_pressed(void) {
    uint8_t state = pressed;
    pressed = 0;

    return state;
}