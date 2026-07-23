#ifndef TIM_H
#define TIM_H

#include <stdint.h>
#include "stm32f103.h"

void tim_init(uint8_t tim);
uint32_t tim2_millis(void);

#endif