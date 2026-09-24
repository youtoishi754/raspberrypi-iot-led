# raspberrypi-iot-led

<div align="center">
	<img alt="C" src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" />
	<img alt="wiringPi" src="https://img.shields.io/badge/wiringPi-2D5BFF?logo=raspberrypi&logoColor=white" />
	<img alt="Raspberry Pi 4 Model B" src="https://img.shields.io/badge/Raspberry%20Pi-4%20Model%20B-C51A4A?logo=raspberrypi&logoColor=white" />
	<img alt="gcc" src="https://img.shields.io/badge/gcc-00599C?logo=gnu&logoColor=white" />
</div>

Raspberry Pi 4 Model B で wiringPi を使い、LED をサイクルごとに不規則に点滅させるシンプルな C プロジェクトです。

## 概要

* `src/main.c` : LED 点滅処理プログラム
* `docs/requirements.md` : 要件メモ
* `docs/project-prerequisites.md` : 実装前の前提条件

## 前提

以下の環境を使用します。

* Raspberry Pi OS
* Raspberry Pi 4 Model B
* Git
* gcc
* wiringPi

## 環境構築

Raspberry Pi 上で以下の手順を上から順番に実行してください。

### 1. パッケージ情報を更新

```bash
sudo apt update
```

### 2. Git をインストール

```bash
sudo apt install git
```

### 3. wiringPi を取得

Git を使用して wiringPi のリポジトリを取得します。

```bash
git clone https://github.com/WiringPi/WiringPi.git
```

### 4. wiringPi をビルド・インストール

取得した `WiringPi` ディレクトリへ移動します。

```bash
cd WiringPi
./build
```

### 5. wiringPi のインストールを確認

以下のコマンドを実行します。

```bash
gpio -v
```

バージョン情報が表示されれば、wiringPi が利用できる状態です。

## リポジトリの取得

GitHub から本プロジェクトを Raspberry Pi に取得します。

```bash
git clone git@github.com:youtoishi754/raspberrypi-iot-led.git
cd raspberrypi-iot-led
```

## ビルド

`src` ディレクトリへ移動し、`main.c` をコンパイルします。

```bash
cd src
gcc main.c -o main -lwiringPi
```

コンパイルが正常に完了すると、`src` ディレクトリに `main` が生成されます。

## 実行

`src` ディレクトリで以下のコマンドを実行します。

```bash
./main
```

プログラムを実行すると、Raspberry Pi に接続した LED がサイクルごとに不規則に点滅します。

## 動作確認

実際の動作は以下の動画で確認できます。

https://github.com/user-attachments/assets/03e6dda3-f160-4d29-89f8-44078c25167a
