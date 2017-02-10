#ifndef LIB_GENERIC_I2C_H
#define LIB_GENERIC_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

  struct GENERIC_I2C_STRUCT {
    void* athis;
    int (*read)( void* o , uint8_t addr , uint8_t reg , uint8_t* data );
    int (*readRegister)( void* o , uint8_t addr , uint8_t count , uint8_t* data );
    int (*readRegisters)( void* o , uint8_t addr , uint8_t reg , uint8_t count , uint8_t* data );
    int (*test)( void* o , uint8_t addr );
    int (*write)( void* o , uint8_t addr , uint8_t count , uint8_t* data );
    int (*writeRegister)( void* o , uint8_t addr , uint8_t reg , uint8_t data );
    int (*writeRegisters)( void* o , uint8_t addr , uint8_t reg , uint8_t count , uint8_t* data );
  };

  typedef struct GENERIC_I2C_STRUCT GENERIC_I2C;


#ifdef __cplusplus
}
#endif

#endif /* LIB_GENERIC_I2C_H */


