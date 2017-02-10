#ifndef LIB_ROBO6_H
#define LIB_ROBO6_H

#include "rp6_c.h"

class Robo6 {
public:
  static void begin();
  static int readRegisters(  RP6_registers* regs );
  static int powerOFF( );
  static int powerON( );
  static int config( uint8_t arg1 , uint8_t arg2 , uint8_t arg3 , uint8_t arg4 , uint8_t arg5 , uint8_t arg6 );
  static int setLEDs( RP6_LEDs leds );
  static int stop( );
  static int moveAtSpeed( uint8_t desired_speed_left , uint8_t desired_speed_right );
  static int changeDirection( RP6_DIRECTION dir );
  static int move( uint8_t desired_speed , RP6_DIRECTION dir , uint16_t distance );
  static int rotate( uint8_t desired_speed , uint8_t dir , uint16_t angle );
  static int setACSPower( RP6_ACS_POWER level );
  static int sendRC5( uint8_t addr , uint8_t cmd );
  static int setWDT( uint8_t abool );
  static int setWDTRequest( uint8_t abool );
};

extern Robo6 Rp6;

#endif

