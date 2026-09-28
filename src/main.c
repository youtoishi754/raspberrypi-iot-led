#include <stdio.h>

#include <wiringPi.h>

enum {
	kLedBcmPin = 17,
	kBlinkDelayMs = 500
};

// GPIO を初期化して、LED を消灯状態にそろえる。
static int led_prepare(int pin) {
	if (wiringPiSetupGpio() == -1) {
		return -1;
	}

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	return 0;
}

int main(void) {
	if (led_prepare(kLedBcmPin) != 0) {
		fprintf(stderr, "GPIO の初期化に失敗しました\n");
		return 1;
	}

	// LED を一定間隔で点滅させる。
	for (;;) {
		digitalWrite(kLedBcmPin, HIGH);
		delay(kBlinkDelayMs);
		digitalWrite(kLedBcmPin, LOW);
		delay(kBlinkDelayMs);
	}

	return 0;
}
