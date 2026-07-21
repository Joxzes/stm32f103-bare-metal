#include <stdint.h>
#include "rcc.h"
#include "systick.h"
#include "gpio.h"
#include "afio.h"
#include "exti.h"
#include "nvic.h"
#include "button.h"

static void blink(void) {
    static uint32_t previous = 0u;
    uint32_t now = millis();

    if ((now - previous) >= 250u) {
        previous = now;

        if (gpio_read(GPIOC, 13u)) {
            gpio_write(GPIOC, 13u, 0);
        } else {
            gpio_write(GPIOC, 13u, 1);
        }
    }
}

static void button_blink(void)
{
    static uint8_t blink_en = 0u;
    static uint8_t locked = 0u;

    uint8_t event = button_pressed();

    if (event && !locked)
    {
        delay(20u);

        if (!gpio_read(GPIOC, 15u))
        {
            blink_en = !blink_en;
            locked = 1u;

            if (!blink_en)
            {
                gpio_write(GPIOC, 13u, 1u);
            }
        }
    }

    if (locked && gpio_read(GPIOC, 15u))
    {
        delay(20u);

        if (gpio_read(GPIOC, 15u))
        {
            locked = 0u;
        }
    }

    if (blink_en)
    {
        blink();
    }
}

int main(void) {
    clock_tree_init();
    systick_init();

    gpio_clock_enable(GPIOC);
    afio_clock_enable();

    gpio_config(GPIOC, 13, GPIO_OUTPUT);
    gpio_write(GPIOC, 13, 1);

    button_config(GPIOC, 15);

    for (;;) {
        button_blink();
    }
}