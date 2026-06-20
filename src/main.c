#include "gpio.h"

#include <stdio.h>
#include <wiringPi.h>

int main(void) {
    if (gpio_init(LED_PIN) != 0) {
        fprintf(stderr, "wiringPi initialization failed\n");
        return 1;
    }

    for (int i = 0; i < BLINK_COUNT; ++i) {
        gpio_write(LED_PIN, LED_ON);
        delay(BLINK_INTERVAL_MS);
        gpio_write(LED_PIN, LED_OFF);
        delay(BLINK_INTERVAL_MS);
    }

    gpio_cleanup(LED_PIN);
    return 0;
}
