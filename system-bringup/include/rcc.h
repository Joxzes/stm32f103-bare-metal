#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "stm32f103.h"

void clock_tree_init(void);
void gpio_clock_enable(GPIO_TypeDef *port);
void afio_clock_enable(void);

#endif