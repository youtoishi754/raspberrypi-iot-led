# raspberrypi-iot-led

Raspberry Pi で LED を制御するためのシンプルな C プロジェクトです。

## 構成

- `src/main.c` : エントリポイント
- `src/gpio.c` / `src/gpio.h` : GPIO 制御の共通処理
- `docs/requirements.md` : 要件メモ
- `docs/system_architecture.png` : システム構成図
- `docs/circuit_diagram.png` : 回路図
- `Makefile` : ビルド定義

`images/` は必要になったら追加します。今回は jpg は入れません。

## ビルド

```bash
make
```

## 実行

Raspberry Pi 上で GPIO 権限を持つ状態で実行してください。

```bash
./bin/raspberrypi-iot-led
```
