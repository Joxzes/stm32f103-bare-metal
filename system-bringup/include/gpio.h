#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "stm32f103.h"

void gpio_config(GPIO_TypeDef *port, uint8_t pin, gpio_mode_t mode);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, uint8_t state);
uint8_t gpio_read(GPIO_TypeDef *port, uint8_t pin);

#endif