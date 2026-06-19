#ifndef GPIO_H
#define GPIO_H

int gpio_init(int pin);
int gpio_write(int pin, int value);
void gpio_cleanup(int pin);

#endif
