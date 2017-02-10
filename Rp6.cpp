#include "Rp6.h"
#include "rp6_c.h"
#include "rp6_i2c.h"

static RP6_C* rp6;

int write( void* o , uint8_t addr , uint8_t count , uint8_t* data );
int readRegisters( void* o , uint8_t addr , uint8_t reg , uint8_t count , uint8_t* data );

void Robo6::begin() { 
  GENERIC_I2C* i2c = I2C_RP6::create_new_i2c();
  
  rp6 = RP6_new(i2c);
}

int Robo6::readRegisters(  RP6_registers* regs ) { 
  return rp6->readRegisters(rp6,regs);
}

int Robo6::powerOFF( ) { 
  return rp6->powerOFF(rp6);
}

int Robo6::powerON( ) { 
  return rp6->powerON(rp6);
}

int Robo6::config( uint8_t arg1 , uint8_t arg2 , uint8_t arg3 , uint8_t arg4 , uint8_t arg5 , uint8_t arg6 ) { 
  return rp6->config(rp6,arg1,arg2,arg3,arg4,arg5,arg6);
}

int Robo6::setLEDs( RP6_LEDs leds ) { 
  return rp6->setLEDs(rp6,leds);
}

int Robo6::stop( ) { 
  return rp6->stop(rp6);
}

int Robo6::moveAtSpeed( uint8_t desired_speed_left , uint8_t desired_speed_right ) { 
  return rp6->moveAtSpeed(rp6,desired_speed_left,desired_speed_right);
}

int Robo6::changeDirection( RP6_DIRECTION dir ) { 
  return rp6->changeDirection(rp6,dir);
}

int Robo6::move( uint8_t desired_speed , RP6_DIRECTION dir , uint16_t distance ) { 
  return rp6->move(rp6,desired_speed,dir,distance);
}

int Robo6::rotate( uint8_t desired_speed , uint8_t dir , uint16_t angle ) { 
  return rp6->rotate(rp6,desired_speed,dir,angle);
}

int Robo6::setACSPower( RP6_ACS_POWER level ) { 
  return rp6->setACSPower(rp6,level);
}

int Robo6::sendRC5( uint8_t addr , uint8_t cmd ) {
  return rp6->sendRC5(rp6,addr,cmd);
}

int Robo6::setWDT( uint8_t abool ) {
  return rp6->setWDT(rp6,abool);
}


int Robo6::setWDTRequest( uint8_t abool) {
  return rp6->setWDTRequest(rp6,abool);
}








