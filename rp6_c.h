#ifndef LIB_RP6_H
#define LIB_RP6_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "generic_i2c.h"

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (1)

  enum RP6_DIRECTION_ENUM {
    RP6_FORWARD, RP6_BACKWARD, RP6_LEFT, RP6_RIGHT
  };
  typedef enum RP6_DIRECTION_ENUM RP6_DIRECTION;

  enum RP6_ACS_POWER_ENUM {
    RP6_OFF, RP6_LOW, RP6_MEDIUM, RP6_HIGH
  };
  typedef enum RP6_ACS_POWER_ENUM RP6_ACS_POWER;

  union RP6_status1_UNION {
    uint8_t byte;
    struct {
#if defined OR32
      /* Big Ending
       		 *
       		 * OpenRisc/IBM-Mainframe/MIPS/SPARC/PowerPC/Motorola 6800/68k/Atmel AVR32/MS9900
       		 */
uint8_t driveSystemChange :
      1;
uint8_t obstacleRight :
      1;
uint8_t obstacleLeft :
      1;
uint8_t RC5transmitReady :
      1;
uint8_t RC5reception :
      1;
uint8_t bumperRight :
      1;
uint8_t bumperLeft :
      1;
uint8_t batLow :
      1;
#else
      /* Little Ending
       		 *
       		 * x86/Alpha/Altera Nios/Atmel AVR8/SH3/SH4/VAX
       		 */
uint8_t batLow :
      1;
uint8_t bumperLeft :
      1;
uint8_t bumperRight :
      1;
uint8_t RC5reception :
      1;
uint8_t RC5transmitReady :
      1;
uint8_t obstacleLeft :
      1;
uint8_t obstacleRight :
      1;
uint8_t driveSystemChange :
      1;
#endif
    };
  };
  typedef union RP6_status1_UNION RP6_status1;

  union RP6_status2_UNION {
    uint8_t byte;
    struct {
#if defined OR32
uint8_t unused :
      3;
uint8_t wdtRequestEnable :
      1;
uint8_t wdtRequest :
      1;
uint8_t watchDogTimer :
      1;
uint8_t ACSactive :
      1;
uint8_t powerOn :
      1;
#else
uint8_t powerOn :
      1;
uint8_t ACSactive :
      1;
uint8_t watchDogTimer :
      1;
uint8_t wdtRequest :
      1;
uint8_t wdtRequestEnable :
      1;
uint8_t unused :
      3;
#endif
    };
  };
  typedef union RP6_status2_UNION RP6_status2;

  union RP6_status3_UNION {
    uint8_t byte;
    struct {
#if defined OR32
uint8_t unused :
      3;
uint8_t direction :
      2;
uint8_t motorOvercurrent :
      1;
uint8_t motorsOn :
      1;
uint8_t movementComplete :
      1;
#else
uint8_t movementComplete :
      1;
uint8_t motorsOn :
      1;
uint8_t motorOvercurrent :
      1;
uint8_t direction :
      2;
uint8_t unused :
      3;
#endif
    };
  };
  typedef union RP6_status3_UNION RP6_status3;

  union RP6_LEDs_UNION {
    uint8_t byte;
    struct {
#if defined OR32
uint8_t reserved :
      2;
uint8_t LEDsL :
      3;
uint8_t LEDsR :
      3;
#else
uint8_t LEDsR :
      3;
uint8_t LEDsL :
      3;
uint8_t reserved :
      2;
#endif
    };
    struct {
#if defined OR32
uint8_t reserved2 :
      1;
uint8_t reserved1 :
      1;
uint8_t LED6 :
      1;
uint8_t LED5 :
      1;
uint8_t LED4 :
      1;
uint8_t LED3 :
      1;
uint8_t LED2 :
      1;
uint8_t LED1 :
      1;
#else
uint8_t LED1 :
      1;
uint8_t LED2 :
      1;
uint8_t LED3 :
      1;
uint8_t LED4 :
      1;
uint8_t LED5 :
      1;
uint8_t LED6 :
      1;
uint8_t reserved1 :
      1;
uint8_t reserved2 :
      1;
#endif
    };
  };
  typedef union RP6_LEDs_UNION RP6_LEDs;

  union RP6_registers_UNION {
    uint8_t array[ 30 ];
    struct {
      RP6_status1 STATUS1;
      RP6_status2 STATUS2;
      RP6_status3 STATUS3;
      uint8_t POWER_LEFT;
      uint8_t POWER_RIGHT;
      uint8_t SPEED_LEFT;
      uint8_t SPEED_RIGHT;
      uint8_t DES_SPEED_LEFT;
      uint8_t DES_SPEED_RIGHT;
      uint8_t DIST_LEFT_L;
      uint8_t DIST_LEFT_H;
      uint8_t DIST_RIGHT_L;
      uint8_t DIST_RIGHT_H;
      uint8_t ADC_LSL_L;
      uint8_t ADC_LSL_H;
      uint8_t ADC_LSR_L;
      uint8_t ADC_LSR_H;
      uint8_t ADC_MOTOR_CURL_L;
      uint8_t ADC_MOTOR_CURL_H;
      uint8_t ADC_MOTOR_CURR_L;
      uint8_t ADC_MOTOR_CURR_H;
      uint8_t ADC_UBAT_L;
      uint8_t ADC_UBAT_H;
      uint8_t ADC_ADC0_L;
      uint8_t ADC_ADC0_H;
      uint8_t ADC_ADC1_L;
      uint8_t ADC_ADC1_H;
      uint8_t RC5_ADR;
      uint8_t RC5_DATA;
      RP6_LEDs LEDS;
    };
  };
  typedef union RP6_registers_UNION RP6_registers;

  struct RP6_STRUCT {
    void* athis;

    GENERIC_I2C* i2c;

    int (*readRegisters)( void* o , RP6_registers* regs );
    int (*powerOFF)( void* o );
    int (*powerON)( void* o );
    int (*config)( void* o , uint8_t arg1 , uint8_t arg2 , uint8_t arg3 , uint8_t arg4 , uint8_t arg5 , uint8_t arg6 );
    int (*setLEDs)( void* o , RP6_LEDs leds );
    int (*stop)( void* o );
    int (*moveAtSpeed)( void* o , uint8_t desired_speed_left , uint8_t desired_speed_right );
    int (*changeDirection)( void* o , RP6_DIRECTION dir );
    int (*move)( void* o , uint8_t desired_speed , RP6_DIRECTION dir , uint16_t distance );
    int (*rotate)( void* o , uint8_t desired_speed , uint8_t dir , uint16_t angle );
    int (*setACSPower)( void* o , RP6_ACS_POWER level );
    int (*sendRC5)( void* o , uint8_t addr , uint8_t cmd );
    int (*setWDT)( void* o , uint8_t abool );
    int (*setWDTRequest)( void* o , uint8_t abool );
  };
  typedef struct RP6_STRUCT RP6_C;

  RP6_C* RP6_new( GENERIC_I2C* i2c );

  int RP6_readRegisters( void* o , RP6_registers* regs );
  int RP6_powerOFF( void* o );
  int RP6_powerON( void* o );
  int RP6_config( void* o , uint8_t arg1 , uint8_t arg2 , uint8_t arg3 , uint8_t arg4 , uint8_t arg5 , uint8_t arg6 );
  int RP6_setLEDs( void* o , RP6_LEDs leds );
  int RP6_stop( void* o );
  int RP6_moveAtSpeed( void* o , uint8_t desired_speed_left , uint8_t desired_speed_right );
  int RP6_changeDirection( void* o , RP6_DIRECTION dir );
  int RP6_move( void* o , uint8_t desired_speed , RP6_DIRECTION dir , uint16_t distance );
  int RP6_rotate( void* o , uint8_t desired_speed , uint8_t dir , uint16_t angle );
  int RP6_setACSPower( void* o , RP6_ACS_POWER level );
  int RP6_sendRC5( void* o , uint8_t addr , uint8_t cmd );
  int RP6_setWDT( void* o , uint8_t abool );
  int RP6_setWDTRequest( void* o , uint8_t abool );

#ifdef __cplusplus
}
#endif

#endif




