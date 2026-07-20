#include <stdint.h>
#include "rcc.h"
#include "systick.h"

static void button_toggle_led(void) {
    static uint8_t previous_state = 0u;
    uint8_t current_state = gpio_read(GPIOC, 15);

    if ((previous_state == 1) && (current_state == 0)) {
        delay(10);

        current_state = gpio_read(GPIOC, 15);
        
        if (current_state == 0) {
            if (gpio_read(GPIOC, 13) != 0) {
                gpio_write(GPIOC, 13, 0);
            } else {
                gpio_write(GPIOC, 13, 1);
            }
        }
    }

    previous_state = current_state;
}

static void press_button_led(void) {
    if (gpio_read(GPIOC, 15) != 0) {
        gpio_write(GPIOC, 13, 0);
    } else {
        gpio_write(GPIOC, 13, 1);
    }
}

static void blink(void) {
    gpio_write(GPIOC, 13, 1);
    delay(500);

    gpio_write(GPIOC, 13, 0);
    delay(500);
}

int main(void) {
    clock_tree_init();
    systick_init();

    gpio_clock_enable(GPIOC);

    gpio_config(GPIOC, 13, GPIO_OUTPUT);
    gpio_config(GPIOC, 15, GPIO_INPUT_PULLDOWN);

    for (;;) {
        button_toggle_led();
        // press_button_led();
        // blink();
    }
}