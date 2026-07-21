#include <stdint.h>
#include "afio.h"

void afio_exti_select(uint8_t line, afio_port_t port) {
    if ((line > 15u) || (port > AFIO_PORT_G)) {
        return;
    }

    uint8_t index = line / 4u;
    uint8_t position = (line % 4u) * 4u;

    AFIO->EXTICR[index] &= ~(0xFu << position);
    AFIO->EXTICR[index] |= ((uint32_t)port << position);
}