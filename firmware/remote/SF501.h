#ifndef SF501_H
#define SF501_H
#include <Arduino.h>

class SF501 {
  public:
    /**
     * @param pin The RF data pin
     * @return void
     **/
    SF501(uint8_t pin);
    void test();    
    void press(bool *frame, uint8_t length, uint8_t times = 8);
  private:
    uint16_t _high_time = 354;
    uint16_t _low_time = 408;
    uint8_t _repeat = 8;
    uint8_t _frame_spacing = 20;
    uint8_t _pin; // RF data pin

    void transfer(bool bit);
    void sendFrame(bool *frame, uint8_t length);
};

#endif
