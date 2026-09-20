# raspberrypi-iot-led

<div align="center">
	<img alt="C" src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" />
	<img alt="wiringPi" src="https://img.shields.io/badge/wiringPi-2D5BFF?logo=raspberrypi&logoColor=white" />
	<img alt="Raspberry Pi 4 Model B" src="https://img.shields.io/badge/Raspberry%20Pi-4%20Model%20B-C51A4A?logo=raspberrypi&logoColor=white" />
	<img alt="gcc" src="https://img.shields.io/badge/gcc-00599C?logo=gnu&logoColor=white" />
</div>

Raspberry Pi 4 Model B で wiringPi を使って LED をサイクルごとに不規則に点滅させるシンプルな C プロジェクトです。

## 概要

- `src/main.c` : LED 点滅処理プログラム
- `docs/requirements.md` : 要件メモ
- `docs/project-prerequisites.md` : 実装前の前提条件

## 前提

- Raspberry Pi OS
- Raspberry Pi 4 Model B
- Git
- gcc
- wiringPi

## wiringPi の導入

Raspberry Pi 上で以下の手順を実行します。

**1. パッケージ情報を更新**

```bash
sudo apt update
```

**2. Git をインストール**

```bash
sudo apt install git
```

**3. wiringPi を取得**

```bash
git clone https://github.com/WiringPi/WiringPi.git
```

**4. wiringPi をビルド・インストール**

```bash
cd WiringPi
./build
```

**5. インストール確認**

```bash
gpio -v
```

バージョン情報が表示されれば、wiringPi の導入は完了です。



## ビルド

`src/main.c` を直接コンパイルします。

```text
gcc main.c -o main -lwiringPi
```

## 実行

Raspberry Pi 4 Model B 上で wiringPi が使える状態で実行してください。

```text
./src/raspberrypi-iot-led
```
##動作確認
https://github.com/user-attachments/assets/03e6dda3-f160-4d29-89f8-44078c25167a


