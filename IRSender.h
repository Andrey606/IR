/*
    Class to send IR signals using the Arduino PWM
*/
#ifndef IRSender_h
#define IRSender_h

#include <cstring>
#include <cstdio>
#include <stdint.h>

#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

// disable Arduino functions
#define PROGMEM
#define pinMode(a, b) 
#define digitalWrite(a, b) 
#define delayMicroseconds(a) 
#define micros() 0 // Returns the number of microseconds
#define delay(a) 
#define pgm_read_byte(a) *(a) //pgm_read_byte(&(temperatures[(temperature-17)]));
#define memcpy_P(a, b, c) memcpy(a, b, c) // memcpy_P(sendBuffer, sendBufferMaintenance1, sizeof(sendBufferMaintenance1));    

class IRSender
{
  protected:
    IRSender(uint8_t pin); // Cannot create generic IRSender instances

  public:
    virtual ~IRSender() = default;
    void setFrequency(int frequency);
    void sendIRbyte(uint8_t sendByte, int bitMarkLength, int zeroSpaceLength, int oneSpaceLength);
    uint8_t bitReverse(uint8_t x);
    void space(int spaceLength);
    void mark(int markLength);

  protected:
    uint8_t _pin;
};


class IRSenderPWM : public IRSender
{
  public:
    IRSenderPWM(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);
};


class IRSenderBlaster : public IRSender
{
  public:
    IRSenderBlaster(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);
};

class IRSenderBitBang : public IRSender
{
  public:
    IRSenderBitBang(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);

  protected:
    int _halfPeriodicTime;
};

#ifdef ESP32
class IRSenderESP32 : public IRSender
{
  public:
    IRSenderESP32(uint8_t pin, uint8_t pwmChannel);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);

  protected:
    uint32_t _frequency;
    uint8_t _pwmChannel;
};
#endif

#ifdef ESP8266
class IRSenderIRremoteESP8266 : public IRSender
{
  public:
    IRSenderIRremoteESP8266(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);

  private:
    IRsend _ir;
};

class IRSenderESP8266 : public IRSender
{
  public:
    IRSenderESP8266(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);

  protected:
    uint32_t _halfPeriodicTime;
};

class IRSenderESP8266Alt : public IRSender
{
  public:
    IRSenderESP8266Alt(uint8_t pin);
    void setFrequency(int frequency);
    void space(int spaceLength);
    void mark(int markLength);

  protected:
    uint32_t _halfPeriodicTime;
};
#endif

#endif
