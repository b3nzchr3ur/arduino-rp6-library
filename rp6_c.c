#include "rp6_dev.h"
#include "rp6_c.h"

#include <stdlib.h> /* malloc(); EXIT_FAILURE; EXIT_SUCCESS; */

RP6_C* RP6_new( GENERIC_I2C* i2c ) {
	RP6_C* t;

	if ( i2c == NULL ) {
		return NULL;
	}

	t = (RP6_C*) malloc( sizeof(RP6_C) );
	if ( t == NULL ) {
		return NULL;
	}

	t->athis = t;

	t->i2c = i2c;

	t->changeDirection = RP6_changeDirection;
	t->config = RP6_config;
	t->move = RP6_move;
	t->moveAtSpeed = RP6_moveAtSpeed;
	t->powerOFF = RP6_powerOFF;
	t->powerON = RP6_powerON;
	t->readRegisters = RP6_readRegisters;
	t->rotate = RP6_rotate;
	t->sendRC5 = RP6_sendRC5;
	t->setACSPower = RP6_setACSPower;
	t->setLEDs = RP6_setLEDs;
	t->setWDT = RP6_setWDT;
	t->setWDTRequest = RP6_setWDTRequest;
	t->stop = RP6_stop;

	return t;
}

int RP6_changeDirection( void* o , RP6_DIRECTION dir ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 3 ] = { 0 , RP6_CMD_CHANGE_DIR , dir };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 3 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_config( void* o , uint8_t arg1 , uint8_t arg2 , uint8_t arg3 , uint8_t arg4 , uint8_t arg5 , uint8_t arg6 ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 8 ] = { 0 , RP6_CMD_CONFIG , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 8 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_move( void* o , uint8_t desired_speed , RP6_DIRECTION dir , uint16_t distance ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 6 ] = { 0 , RP6_CMD_MOVE , desired_speed , dir , distance >> 8 , distance };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 6 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_moveAtSpeed( void* o , uint8_t desired_speed_left , uint8_t desired_speed_right ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 4 ] = { 0 , RP6_CMD_MOVE_AT_SPEED , desired_speed_left , desired_speed_right };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 4 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_powerOFF( void* o ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 2 ] = { 0 , RP6_CMD_POWER_OFF };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 2 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_powerON( void* o ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 2 ] = { 0 , RP6_CMD_POWER_ON };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 2 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_readRegisters( void* o , RP6_registers* regs ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	if ( t->i2c->readRegisters( t->i2c , RP6_SLAVE_ADDR , 0 , 30 , regs->array ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_rotate( void* o , uint8_t desired_speed , uint8_t dir , uint16_t angle ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 6 ] = { 0 , RP6_CMD_ROTATE , desired_speed , dir , angle >> 8 , angle };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 6 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_sendRC5( void* o , uint8_t addr , uint8_t cmd ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 4 ] = { 0 , RP6_CMD_SEND_RC5 , addr , cmd };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 4 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_setACSPower( void* o , RP6_ACS_POWER level ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 3 ] = { 0 , RP6_CMD_SET_ACS_POWER , level };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 3 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_setLEDs( void* o , RP6_LEDs leds ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	leds.reserved = 0;

	uint8_t data[ 3 ] = { 0 , RP6_CMD_SETLEDS , leds.byte };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 3 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_setWDT( void* o , uint8_t abool ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 3 ] = { 0 , RP6_CMD_SET_WDT , abool };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 3 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_setWDTRequest( void* o , uint8_t abool ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 3 ] = { 0 , RP6_CMD_SET_WDT_RQ , abool };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 3 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int RP6_stop( void* o ) {
	RP6_C* t = ( (RP6_C*) o )->athis;

	uint8_t data[ 2 ] = { 0 , RP6_CMD_STOP };

	if ( t->i2c->write( t->i2c , RP6_SLAVE_ADDR , 2 , data ) ) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


