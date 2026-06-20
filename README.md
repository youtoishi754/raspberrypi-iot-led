# raspberrypi-iot-led

Raspberry Pi 4 Model B で wiringPi を使って LED を制御するためのシンプルな C プロジェクトです。

## 構成

- `src/main.c` : エントリポイント
- `src/gpio.c` / `src/gpio.h` : wiringPi ベースの GPIO 制御
- `docs/requirements.md` : 要件メモ
- `docs/system_architecture.png` : システム構成図
- `docs/circuit_diagram.png` : 回路図
- `Makefile` : ビルド定義

`images/` は必要になったら追加します。今回は jpg は入れません。

## 依存

- wiringPi
- gcc

## ビルド

```bash
make
```

## 実行

Raspberry Pi 4 Model B 上で wiringPi が使える状態で実行してください。

```bash
./bin/raspberrypi-iot-led
```
