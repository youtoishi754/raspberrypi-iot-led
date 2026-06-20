#include "gpio.h"

#include <wiringPi.h>

int gpio_init(int pin) {
    if (wiringPiSetupGpio() == -1) {
        return -1;
    }

    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    return 0;
}

int gpio_write(int pin, int value) {
    digitalWrite(pin, value ? HIGH : LOW);
    return 0;
}

void gpio_cleanup(int pin) {
    (void)pin;
    digitalWrite(pin, LOW);
}
