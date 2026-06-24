#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <wiringPi.h>

enum {
	kLedBcmPin = 17,
	kLedActive = 1,
	kLedIdle = 0,
	kBlinkRounds = 5,
	kDelayFloorMs = 500,
	kDelaySpanMs = 501
};

static int led_prepare(int pin) {
	if (wiringPiSetupGpio() == -1) {
		return -1;
	}

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	return 0;
}

static int led_set_state(int pin, int value) {
	digitalWrite(pin, value ? HIGH : LOW);
	return 0;
}

static void led_release(int pin) {
	digitalWrite(pin, LOW);
}

int main(void) {
	if (led_prepare(kLedBcmPin) != 0) {
		fprintf(stderr, "GPIO setup could not be completed\n");
		return 1;
	}

	srand((unsigned int)time(NULL));

	for (int round = 0; round < kBlinkRounds; ++round) {
		int wait_ms = kDelayFloorMs + (rand() % kDelaySpanMs);

		printf("cycle %d waiting %d ms\n", round + 1, wait_ms);
		led_set_state(kLedBcmPin, kLedActive);
		delay(wait_ms);
		led_set_state(kLedBcmPin, kLedIdle);
		delay(wait_ms);
	}

	led_release(kLedBcmPin);
	return 0;
}
