#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include "stm32f103.h"

void button_config(GPIO_TypeDef *port, uint8_t line);
uint8_t button_pressed(void);

#endif