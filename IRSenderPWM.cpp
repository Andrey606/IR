
#include "IRSender.h"

IRSenderPWM::IRSenderPWM(uint8_t pin) : IRSender(pin)
{
  std::cout << "IRSenderPWM::IRSenderPWM(int)" << std::endl;
}


// Set the PWM frequency. The selected pin determines which timer to use
void IRSenderPWM::setFrequency(int frequency)
{
  std::cout << "IRSenderPWM::setFrequency(int)" << std::endl;
}


// Send an IR 'mark' symbol, i.e. transmitter ON
void IRSenderPWM::mark(int markLength)
{
  std::cout << "IRSenderPWM::mark(int)" << std::endl;
}


// Send an IR 'space' symbol, i.e. transmitter OFF
void IRSenderPWM::space(int spaceLength)
{
  std::cout << "IRSenderPWM::space(int)" << std::endl;
}
