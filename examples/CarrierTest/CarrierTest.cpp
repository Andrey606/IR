#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>

#include "../../CarrierHeatpumpIR.h"

using namespace std;

IRSenderPWM irSender(9);     // IR led on Duemilanove digital pin 3, using Arduino PWM
//IRSenderBlaster irSender(3); // IR led on Duemilanove digital pin 3, using IR Blaster (generates the 38 kHz carrier)

CarrierNQVHeatpumpIR *heatpumpIR;

int main()
{
  heatpumpIR = new CarrierNQVHeatpumpIR();

  cout << "Starting" << endl;

  const char* buf;
  cout << "Sending IR to " << endl;

  // Print the model
  buf = heatpumpIR->model();
  // 'model' is a PROGMEM pointer, so need to write a byte at a time
  cout << buf;

  cout << ", info: ";
  // Print the info
  buf = heatpumpIR->info();
  // 'info' is a PROGMEM pointer, so need to write a byte at a time
  cout << buf  << endl;

  heatpumpIR->send(irSender, POWER_ON, MODE_HEAT, FAN_AUTO, 24, VDIR_AUTO, HDIR_AUTO);

  return 0;
}
