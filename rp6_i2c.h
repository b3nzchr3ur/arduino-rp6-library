#ifndef LIB_RP6_I2C_H
#define LIB_RP6_I2C_H

#include "generic_i2c.h"

class I2C_RP6 {
public: 
  static GENERIC_I2C* create_new_i2c();
};

#endif



