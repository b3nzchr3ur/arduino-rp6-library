#include "Rp6.h"

RP6_registers regs;
RP6_LEDs leds;
RP6_DIRECTION dir = RP6_FORWARD;

void setup()
{
  Serial.begin(9600);

  Rp6.begin();
}

const int someDelay = 200;
const uint8_t someSpeed = 50;

void loop()
{
  Rp6.readRegisters(&regs);
  Serial.print("BumperLeft:");
  Serial.println(regs.STATUS1.bumperLeft);
  Serial.print("BumperRight:");
  Serial.println(regs.STATUS1.bumperRight);

  if (regs.STATUS1.bumperLeft || regs.STATUS1.bumperRight) {
    dir = (dir == RP6_FORWARD) ? RP6_BACKWARD : RP6_FORWARD;
    Rp6.move( 120 , dir , 600 );
    delay(500);
  }


}











