# Project Guidelines

## Overview

Raspberry Pi 4 Model B 上で LED を単純に点滅させる最小構成のサンプルを、Copilot 向けのプロジェクト指示書としてまとめます。
機能はシンプルに保ち、配線・制御・ビルド・テストの整合性を優先します。

## Tech Stack

| 項目 | 内容 |
|---|---|
| 言語 | C |
| ライブラリ | wiringPi |
| 実行環境 | Raspberry Pi 4 Model B / Raspberry Pi OS |
| ビルド | gcc |

## Architecture

- 対象は Raspberry Pi の GPIO を使った LED 点滅です。
- LED の ON/OFF 制御を中心にし、余計な機能は追加しません。
- GPIO の初期化、出力制御、終了処理を 1 本の流れで扱います。
- 点滅間隔は固定値にして、挙動を単純に保ちます。
- 配線と GPIO 番号の対応がコードと README で一致することを優先します。

## Build and Test

```text
gcc -o src/raspberrypi-iot-led src/main.c -lwiringPi
./src/raspberrypi-iot-led
```

## Testing Conventions

- ローカルで実機確認できることを優先します。
- コンパイル時の警告をできるだけ残さないようにします。
- GPIO 初期化失敗時は異常終了できることを確認します。
- LED が一定間隔で点滅することを確認します。

## Conventions

- README は概要と利用方法を中心にします。
- 詳細な前提条件はこの文書に集約します。
- 実装は最小構成を維持し、不要な分割は避けます。
- 定数名やメッセージはこのプロジェクト独自のものにします。
- 将来の機能追加は、まず GPIO 周りの責務を崩さない範囲で検討します。

## Branch Strategy

- `main`: 動作確認済みの安定版
- `develop`: 開発の統合ブランチ
- 作業ブランチは `develop` から切り、PR を経て `develop` → `main` の順にマージします。
- `main` と `develop` への直接 push は避けます。

ブランチ名は `feature/*`（機能追加）、`fix/*`（不具合修正）、`docs/*`（ドキュメント更新）とします。
例: `feature/blink-fixed-interval`
## Commit Message Format

コミットメッセージは Conventional Commits を基本にします。

```text
<型>(スコープ): タイトル

本文（任意）

フッター（任意）
```

### 型の一覧

| 型 | 用途 |
|---|---|
| `feat` | 点滅処理や GPIO 制御の追加 |
| `fix` | 不具合修正 |
| `test` | テストや確認手順の修正 |
| `refactor` | 動作を変えない整理 |
| `style` | フォーマットや見た目の修正 |
| `docs` | README や説明文の更新 |
| `chore` | ビルド設定や補助作業 |

### 例

```text
feat(blink): 点滅間隔を乱数化する
```

```text
fix(gpio): 初期化失敗時に終了する
```

```text
docs(readme): 配線手順を整理する
```

## Key Files

- `src/main.c` — LED 点滅のメイン処理
- `src/gpio.c` — GPIO 操作用の分離実装がある場合の候補
- `src/gpio.h` — GPIO 関連の定義がある場合の候補
- `docs/project-prerequisites.md` — 実装前の前提条件
- `docs/requirements.md` — LED アプリの要件
- `README.md` — プロジェクト概要と使い方
