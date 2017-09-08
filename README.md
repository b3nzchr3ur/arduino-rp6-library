# Introduction

This library makes it possible to control an RP6 base board over I2C via an Arduino.

## Credits

The library used [RP6-I2C-Demo](https://github.com/christiankarsch/RP6-I2C-Demo) as a starting point.

## Setup

+ Connect your Arduino via I2C to an Rp6 base board.
+ Install the [RPBase_I2CSlave](https://github.com/b3nzchr3ur/rp6/tree/master/RP6Examples_20120725f/RP6BASE_EXAMPLES/RP6Base_I2CSlave) code on the Rp6 base board.
+ Make sure the RP6 control board does not have I2C code that could cause conflicts.
+ Run the example as found in [examples/rp6-master](examples/rp6-master) for a short demonstration.
