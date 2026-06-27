#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <wiringPi.h>

// LED 制御に使う定数をまとめる。
enum {
	kLedBcmPin = 17,
	kLedActive = 1,
	kLedIdle = 0,
	kBlinkRounds = 5,
	kDelayFloorMs = 500,
	kDelaySpanMs = 501
};

// GPIO を初期化し、LED を消灯状態にそろえる。
static int led_prepare(int pin) {
	if (wiringPiSetupGpio() == -1) {
		return -1;
	}

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	return 0;
}

// LED の点灯・消灯を切り替える。
static int led_set_state(int pin, int value) {
	digitalWrite(pin, value ? HIGH : LOW);
	return 0;
}

// 終了時に LED を消灯する。
static void led_release(int pin) {
	digitalWrite(pin, LOW);
}

int main(void) {
	// GPIO の準備に失敗したら、エラーを出して終了する。
	if (led_prepare(kLedBcmPin) != 0) {
		fprintf(stderr, "GPIO setup could not be completed\n");
		return 1;
	}

	// 乱数の初期値を現在時刻から設定する。
	srand((unsigned int)time(NULL));

	// 指定回数だけ LED を点滅させる。
	for (int round = 0; round < kBlinkRounds; ++round) {
		// 500〜1000 ms の範囲で待機時間を決める。
		int wait_ms = kDelayFloorMs + (rand() % kDelaySpanMs);

		// 点灯してから待機する。
		printf("cycle %d waiting %d ms\n", round + 1, wait_ms);
		led_set_state(kLedBcmPin, kLedActive);
		delay(wait_ms);
		// 消灯してからもう一度待機する。
		led_set_state(kLedBcmPin, kLedIdle);
		delay(wait_ms);
	}

	// 終了前に LED を消灯する。
	led_release(kLedBcmPin);
	return 0;
}
