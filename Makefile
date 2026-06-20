CC := gcc
CFLAGS := -Wall -Wextra -O2
LDLIBS := -lwiringPi
TARGET_DIR := bin
TARGET := $(TARGET_DIR)/raspberrypi-iot-led
SOURCES := src/main.c src/gpio.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDLIBS)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

clean:
	rm -rf $(TARGET_DIR)
