#ifndef GPIO_H
#define GPIO_H

#define LED_PIN 17
#define LED_ON 1
#define LED_OFF 0
#define BLINK_COUNT 5
#define BLINK_INTERVAL_MS 1000

int gpio_init(int pin);
int gpio_write(int pin, int value);
void gpio_cleanup(int pin);

#endif
