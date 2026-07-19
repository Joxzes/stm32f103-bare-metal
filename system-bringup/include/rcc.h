#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "gpio.h"

void clock_tree_init(void);
void gpio_clock_enable(GPIO_TypeDef *port);

#endif