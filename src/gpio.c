#include "gpio.h"

#include <stdio.h>

int gpio_init(int pin) {
    (void)pin;
    return 0;
}

int gpio_write(int pin, int value) {
    (void)pin;
    (void)value;
    return 0;
}

void gpio_cleanup(int pin) {
    (void)pin;
}
