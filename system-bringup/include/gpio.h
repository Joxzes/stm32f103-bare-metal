#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

typedef enum{
    GPIO_INPUT_ADC,
    GPIO_INPUT_PULLUP,
    GPIO_INPUT_PULLDOWN,
    GPIO_OUTPUT
} gpio_mode_t;

#define GPIOA ((GPIO_TypeDef *)0x40010800u)
#define GPIOB ((GPIO_TypeDef *)0x40010C00u)
#define GPIOC ((GPIO_TypeDef *)0x40011000u)
#define GPIOD ((GPIO_TypeDef *)0x40011400u)
#define GPIOE ((GPIO_TypeDef *)0x40011800u)
#define GPIOF ((GPIO_TypeDef *)0x40011C00u)
#define GPIOG ((GPIO_TypeDef *)0X40012000u)

void gpio_clock_enable(GPIO_TypeDef *port);
void gpio_config(GPIO_TypeDef *port, uint8_t pin, gpio_mode_t mode);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, uint8_t state);
uint8_t gpio_read(GPIO_TypeDef *port, uint8_t pin);

#endif