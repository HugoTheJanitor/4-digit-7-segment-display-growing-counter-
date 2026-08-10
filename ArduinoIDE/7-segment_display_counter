// 4-digit 7-segment display counter
// Arduino Mega 2560

// Pins for the 4 digits
int digitPins[] = {A1, A2, A3, A4};

// Pins for segments: A, B, C, D, E, F, G
int segmentPins[] = {5, 6, 7, 8, 9, 10, 11};

// Segment patterns for numbers 0-9
// {A, B, C, D, E, F, G}
int numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

// Number currently displayed
int value = 0;

// Time between counter increments
int speedDelay = 500;

unsigned long previousMillis = 0;

void setup() {

  // Set digit pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }

  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

}

void loop() {

  // Continuously refresh the display
  displayNumber(value);

  // Check if it is time to increase the number
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= speedDelay) {

    previousMillis = currentMillis;

    value++;

    // After 9999, start again from 0
    if (value > 9999) {
      value = 0;
    }

    // Make the counter faster
    if (speedDelay > 20) {
      speedDelay -= 2;
    }
  }
}


void displayNumber(int number) {

  // Split the number into four digits
  int digits[4];

  digits[0] = number / 1000;
  digits[1] = (number / 100) % 10;
  digits[2] = (number / 10) % 10;
  digits[3] = number % 10;

  // Display each digit one by one
  for (int i = 0; i < 4; i++) {

    // Turn all digits off before changing segments
    for (int j = 0; j < 4; j++) {
      digitalWrite(digitPins[j], HIGH);
    }

    // Set segments for current number
    for (int k = 0; k < 7; k++) {
      digitalWrite(segmentPins[k], numbers[digits[i]][k]);
    }

    // Turn on current digit
    digitalWrite(digitPins[i], LOW);

    // Short delay so the digit is visible
    delay(1);

    // Turn current digit off
    digitalWrite(digitPins[i], HIGH);
  }
}
