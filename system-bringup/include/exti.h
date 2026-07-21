#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>
#include "stm32f103.h"

void exti_configure_line(uint8_t line, exti_trigger_t trigger);

#endif