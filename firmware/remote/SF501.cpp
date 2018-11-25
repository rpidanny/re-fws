#include "SF501.h"

SF501::SF501(uint8_t pin) {
  _pin = pin;

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, HIGH);
}

void SF501::test() {
  for (uint8_t i = 0; i < 134; i++) {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(_low_time);
    digitalWrite(_pin, LOW);
    delayMicroseconds(_low_time);
  }
}

void SF501::transfer(bool bit) {
  if (bit) {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(_high_time);
    digitalWrite(_pin, LOW);
    delayMicroseconds(_low_time);
  } else {
    // No need to turn pin low as low by default?
    digitalWrite(_pin, LOW);
    delayMicroseconds(_high_time + _low_time);
  }
}

void SF501::press(bool *frame, uint8_t length, uint8_t times) {
  for (uint8_t i = 0; i < times; i++) {
    // Press button
    sendFrame(frame, length);
  }
}

void SF501::sendFrame(bool *frame, uint8_t length) {
  for (uint8_t i = 0; i < length; i++) {
    transfer(frame[i]);
  }
  digitalWrite(_pin, LOW);
  delay(_frame_spacing);
}
