/*
  xPro_v5_map.h - An embedded CNC Controller with rs274/ngc (g-code) support

  Driver code for ESP32

  Part of grblHAL

  Copyright (c) 2021-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

#if KEYPAD_ENABLE == 1
#error No free pins for I2C keypad!
#endif

#define BOARD_NAME "BTT Rodent"
#define HAS_BOARD_INIT
#if TRINAMIC_ENABLE != 5160
#error Rodent has soldered TMC5160 drivers.
#endif


#define USE_I2S_OUT
#define I2S_OUT_PIN_BASE 64

#define I2S_OUT_BCK GPIO_NUM_22
#define I2S_OUT_WS GPIO_NUM_17
#define I2S_OUT_DATA GPIO_NUM_21

#define TRINAMIC_MIXED_DRIVERS 0

// timer definitions
#define STEP_TIMER_GROUP TIMER_GROUP_0
#define STEP_TIMER_INDEX TIMER_0

// Define step pulse output pins.
#define X_STEP_PIN          I2SO(2)
#define Y_STEP_PIN          I2SO(5)
#define Z_STEP_PIN          I2SO(10)

// Define step direction output pins.
#define X_DIRECTION_PIN     I2SO(1)
#define Y_DIRECTION_PIN     I2SO(4)
#define Z_DIRECTION_PIN     I2SO(9)

// Define homing/hard limit switch input pins and limit interrupt vectors.
#define X_LIMIT_PIN         GPIO_NUM_34
#define Y_LIMIT_PIN         GPIO_NUM_35
#define Z_LIMIT_PIN         GPIO_NUM_33

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         I2SO(13)
#define M3_DIRECTION_PIN    I2SO(12)
#define M3_LIMIT_PIN        I2SO(15)
#endif

// Define driver spindle pins

//#if DRIVER_SPINDLE_PWM_ENABLE && !(MODBUS_ENABLE & MODBUS_RTU_ENABLED)
//#define SPINDLE_PWM_PIN     GPIO_NUM_25
//#else
//#define AUXOUTPUT0_PIN      GPIO_NUM_25
//#endif
//
//#if DRIVER_SPINDLE_ENABLE && !(MODBUS_ENABLE & MODBUS_RTU_ENABLED)
//#define SPINDLE_ENABLE_PIN  GPIO_NUM_4
//#else
//#define AUXOUTPUT1_PIN      GPIO_NUM_4
//#endif
//
//#define AUXINPUT0_PIN       GPIO_NUM_13
//#define AUXINPUT1_PIN       GPIO_NUM_0
//#define AUXINPUT2_PIN       GPIO_NUM_22

// Define flood and mist coolant enable output pins.
// Only one can be enabled!

//#define COOLANT_MIST_PIN    GPIO_NUM_21
//#define COOLANT_FLOOD_PIN   GPIO_NUM_21
// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.

//#define RESET_PIN           GPIO_NUM_16

// Define probe switch input pin.
#if PROBE_ENABLE
#define PROBE_PIN           AUXINPUT2_PIN
#endif

// Pin mapping when using SPI mode.
// With this mapping, SD card can be used both in SPI and 1-line SD mode.
// Note that a pull-up on CS line is required in SD mode.
#define PIN_NUM_MISO        GPIO_NUM_19
#define PIN_NUM_MOSI        GPIO_NUM_23
#define PIN_NUM_CLK         GPIO_NUM_18
#define MOTOR_CS_PIN        GPIO_NUM_0
#if SDCARD_ENABLE
#define PIN_NUM_CS          GPIO_NUM_5
#endif
