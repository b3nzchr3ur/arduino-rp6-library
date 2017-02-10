#include <Wire.h>
#include "rp6_i2c.h"
#include <stdlib.h>

int readRegisters( void* o , uint8_t addr , uint8_t reg , uint8_t count , uint8_t* data )
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(addr, count);    // request 6 bytes from slave device #2

  uint8_t index = 0;
  while(Wire.available())    // slave may send less than requested
  {
    data[index] = Wire.read();    // receive a byte as character
    index++;
  }

  return 0;
}

int write( void* o , uint8_t addr , uint8_t count , uint8_t* data ) {
  Wire.beginTransmission(addr);
  Wire.write(data,count);
  return Wire.endTransmission();
}


GENERIC_I2C* I2C_RP6::create_new_i2c() {
  GENERIC_I2C* i2c;

  i2c = (GENERIC_I2C*) malloc(sizeof(GENERIC_I2C));

  i2c->write = write;
  i2c->readRegisters = readRegisters;

  /* Not used by RP6 library: 
   i2c->read = read;
   i2c->readRegisters = readRegisters;
   i2c->test = test;
   i2c->writeRegister = writeRegister;
   i2c->writeRegister = writeRegister;
   */

  Wire.begin();

  return i2c;
}

