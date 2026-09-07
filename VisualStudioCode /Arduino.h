#ifndef ARDUINO_STUB_H
#define ARDUINO_STUB_H

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#define INPUT_PULLUP 2

#define A1 55
#define A2 56
#define A3 57
#define A4 58

typedef unsigned char byte;

inline void pinMode(int, int) {}
inline void digitalWrite(int, int) {}
inline int digitalRead(int) { return HIGH; }
inline void analogWrite(int, int) {}
inline void delay(unsigned long) {}
inline void delayMicroseconds(unsigned int) {}
inline unsigned long millis() { return 0; }
inline unsigned long pulseIn(int, int) { return 0; }

#endif
