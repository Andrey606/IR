#include "../../ToshibaDaiseikaiHeatpumpIR.h"

using namespace std;

IRSenderPWM irSender(9);     // IR led on Duemilanove digital pin 3, using Arduino PWM
//IRSenderBlaster irSender(3); // IR led on Duemilanove digital pin 3, using IR Blaster (generates the 38 kHz carrier)

ToshibaDaiseikaiHeatpumpIR *heatpumpIR;

int main()
{
  heatpumpIR = new ToshibaDaiseikaiHeatpumpIR();

  cout << "Starting" << endl;

  const char* buf;
  cout << "Sending IR to ";

  // Print the model
  buf = heatpumpIR->model();
  // 'model' is a PROGMEM pointer, so need to write a byte at a time
  cout << buf;

  cout << ", info: ";
  // Print the info
  buf = heatpumpIR->info();
  // 'info' is a PROGMEM pointer, so need to write a byte at a time
  cout << buf  << endl;

  heatpumpIR->send(irSender, POWER_ON, MODE_AUTO, FAN_AUTO, 24, VDIR_AUTO, HDIR_AUTO);

  return 0;
}

