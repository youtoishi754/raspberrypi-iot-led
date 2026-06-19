#include "gpio.h"

#include <stdio.h>
#include <unistd.h>

#define LED_PIN 17

int main(void) {
    if (gpio_init(LED_PIN) != 0) {
        fprintf(stderr, "GPIO initialization failed\n");
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        gpio_write(LED_PIN, 1);
        sleep(1);
        gpio_write(LED_PIN, 0);
        sleep(1);
    }

    gpio_cleanup(LED_PIN);
    return 0;
}
