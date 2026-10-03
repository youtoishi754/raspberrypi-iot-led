## LED回路図・GPIO制御

Raspberry Pi 4 Model B の GPIO17 を使用してLEDを制御します。

### 回路図

```text
          Raspberry Pi 4 Model B

3V3 o─────|>|─────/\/\/─────o GPIO17
          LED       330Ω        │
                                │
                           GPIO出力回路
                                │
                               GND
```

| 記号       | 部品・端子  | 
| -------- | ------ | 
| `o`      | 端子     |  
| `>`       | LED      |
| `/\/\/`  | 抵抗     |  
| `3V3`    | 3.3V電源 |  
| `GPIO17` | GPIO17 |  
| `GND`    | グランド   | 

> **注意:** GPIO17からGNDへ直接配線しているわけではありません。GPIO17をLOWにすると、GPIOの出力回路を介してGND側へ電流が流れます。

### GPIO17の動作

```text
HIGH → GPIO17 ≒ 3.3V → 電位差ほぼ0 → LED消灯
LOW  → GPIO17 ≒ 0V   → 電位差あり → LED点灯
```

この回路は **Active-Low** 構成です。

### 電流の流れ

#### GPIO17 = HIGH

```text
3V3 → LED → 330Ω → GPIO17（約3.3V）

電位差がほぼない
        ↓
      消灯
```

#### GPIO17 = LOW

```text
3V3 → LED → 330Ω → GPIO17（約0V）
                       ↓
                  GPIO出力回路
                       ↓
                      GND

電位差が生じる
        ↓
      点灯
```
