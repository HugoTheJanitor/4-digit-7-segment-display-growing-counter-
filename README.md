# 4-Digit 7-Segment Display Growing Counter

A beginner-friendly Arduino project using a 4-digit 7-segment display.

The display counts from **0 to 9999**, and the counting speed gradually increases until it reaches the maximum speed.

This project is focused on learning how 4-digit 7-segment displays work, how multiplexing works, and how to control the speed of a program.

---

## About

The project uses an **Arduino Mega 2560** and a 4-digit 7-segment display.

The counter works like this:

```text
0 → 1 → 2 → 3 → ... → 9998 → 9999 → 0
```

At the beginning, the counter changes slowly.

As the number increases, the delay between numbers becomes smaller, making the counter progressively faster.

The minimum delay is limited to **20 ms**.

---

## Hardware

### Components

- Arduino Mega 2560
- 4-digit 7-segment display
- 8x resistors
- 20x jumper wires
- Breadboard
- USB cable

### Wiring

**Digit pins:**

- Digit 1 → A1
- Digit 2 → A2
- Digit 3 → A3
- Digit 4 → A4

**Segment pins:**

- A → Pin 5
- B → Pin 6
- C → Pin 7
- D → Pin 8
- E → Pin 9
- F → Pin 10
- G → Pin 11
- DP → Pin 12

The decimal point (DP) is connected to Pin 12, although it is not currently used by the counter logic.

See the [Photos](https://github.com/HugoTheJanitor/4-digit-7-segment-display-growing-counter-/tree/main/Photos) folder for photos of the wiring and project.

---

## How to Use

### Arduino IDE

1. Open Arduino IDE.
2. Open `ArduinoIDE/7-segment_display_counter.ino`.
3. Select **Tools → Board → Arduino Mega 2560**.
4. Select **Tools → Port → Your COM port**.
5. Click **Upload**.

### Visual Studio Code

A Visual Studio Code version is also included in the repository.

Open the `VisualStudioCode/` folder and use your Arduino development setup to upload the project.

---

## How It Works

### 1. Displaying Numbers

The program stores the segment patterns for numbers `0–9` in an array:

```cpp
int numbers[10][7];
```

Each number contains information about which segments should be turned on.

For example:

```text
A
---
F   B
---
G
---
E   C
---
D
```

The Arduino uses these patterns to create each number on the display.

---

### 2. Multiplexing

The 4-digit display uses the same segment pins for all four digits.

Instead of turning all four digits on at the same time, the Arduino activates them one by one very quickly.

```text
Digit 1 → Digit 2 → Digit 3 → Digit 4 → repeat
```

Because this happens very quickly, our eyes perceive all four digits as being displayed simultaneously.

The `displayNumber()` function handles this process.

---

### 3. Counting

The counter starts at:

```cpp
int value = 0;
```

Every time the required amount of time passes, the value increases:

```cpp
value++;
```

When it reaches `9999`, it starts again from `0`:

```cpp
if (value > 9999) {
    value = 0;
}
```

---

### 4. Increasing Speed

The initial delay is:

```cpp
int speedDelay = 500;
```

Every time the number increases, the delay becomes smaller:

```cpp
if (speedDelay > 20) {
    speedDelay -= 2;
}
```

This makes the counter gradually become faster.

The speed stops increasing when the delay reaches approximately **20 ms**.

---

## What I Learned

- How a 4-digit 7-segment display works
- How multiplexing works
- How to control individual display segments
- Using arrays to store segment patterns
- Using `digitalWrite()`
- Splitting a number into individual digits
- Using `millis()` for timing
- Creating an automatic counter
- Changing program speed dynamically
- Working with Arduino Mega 2560 pins
- Organizing an Arduino project on GitHub

---

## Project Structure

```text
4-digit-7-segment-display-growing-counter-/
│
├── ArduinoIDE/
│   └── 7-segment_display_counter.ino
│
├── VisualStudioCode/
│   └── ...
│
├── Photos/
│   ├── FullPhotoOfProject.png
│   └── PinsOfMega2560Arduino.png
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## Learning Note

This project is part of my Arduino and Embedded Systems learning journey.

The original display logic was used as a learning starting point and was modified and simplified for this project.

The current version focuses specifically on a **0–9999 counter with progressively increasing speed**.

---

## License

This project is licensed under the MIT License.

See [LICENSE](https://github.com/HugoTheJanitor/4-digit-7-segment-display-growing-counter-/blob/main/LICENSE) for details.

---

Made while learning Arduino and Embedded Systems.
