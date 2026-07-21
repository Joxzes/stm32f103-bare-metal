#ifndef AFIO_H
#define AFIO_H

#include <stdint.h>
#include "stm32f103.h"

void afio_exti_select(uint8_t line, afio_port_t port);

#endif