/*
  mks_tinybee_1_0_map.h - An embedded CNC Controller with rs274/ngc (g-code) support

  Driver code for ESP32

  Part of grblHAL

  Copyright (c) 2022 Ennio Sesana
  Copyright (c) 2023-2024 Terje Io (added SD card, ModBus and MPG options)

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

#define BOARD_NAME "BTT Rodent 1.0"
#define BOARD_URL "NA"

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#if KEYPAD_ENABLE == 1
#error "No free pins for I2C keypad!"
#endif

#define USE_I2S_OUT
#define I2S_OUT_PIN_BASE 64

#define UART2_RX_PIN        GPIO_NUM_16 // EXP_1
#define UART2_TX_PIN        GPIO_NUM_17 // EXP_1

// timer definitions
#define STEP_TIMER_GROUP    TIMER_GROUP_0
#define STEP_TIMER_INDEX    TIMER_0

#define I2S_OUT_BCK         GPIO_NUM_22
#define I2S_OUT_WS          GPIO_NUM_17
#define I2S_OUT_DATA        GPIO_NUM_21

#define X_STEP_PIN          I2SO(2) 
#define X_DIRECTION_PIN     I2SO(1) 
#define X_ENABLE_PIN        I2SO(0) 
#define X_LIMIT_PIN         GPIO_NUM_35

#define Y_STEP_PIN          I2SO(5)
#define Y_DIRECTION_PIN     I2SO(4)
#define Y_ENABLE_PIN        I2SO(7)
#define Y_LIMIT_PIN         GPIO_NUM_34

#define Z_STEP_PIN          I2SO(10)
#define Z_DIRECTION_PIN     I2SO(9)
#define Z_ENABLE_PIN        I2SO(8)
#define Z_LIMIT_PIN         GPIO_NUM_33

/*
#if PROBE_ENABLE || N_ABC_MOTORS == 0
#define AUXINPUT1_PIN       GPIO_NUM_35 // MT_DET
#endif
*/

#if N_ABC_MOTORS >= 1
#define M3_AVAILABLE        // E0
#define M3_STEP_PIN         I2SO(10)
#define M3_DIRECTION_PIN    I2SO(11)
#define M3_ENABLE_PIN       I2SO(9)
/*#ifndef AUXINPUT1_PIN*/
#define M3_LIMIT_PIN        GPIO_NUM_32 // MT_DET
/*#elif SDCARD_ENABLE
#define M3_LIMIT_PIN        GPIO_NUM_12 // EXP2
#else
#define M3_LIMIT_PIN        GPIO_NUM_19 // EXP2
#endif*/
#endif

#if N_ABC_MOTORS == 2
#define M4_AVAILABLE        // E1
#define M4_STEP_PIN         I2SO(13)
#define M4_DIRECTION_PIN    I2SO(14)
#define M4_ENABLE_PIN       I2SO(12)
#if SDCARD_ENABLE
#define M4_LIMIT_PIN        GPIO_NUM_14 // EXP2
#else
#define M4_LIMIT_PIN        GPIO_NUM_18 // EXP2
#endif
#endif

#define AUXINPUT0_PIN       GPIO_NUM_39 // TB

// Define driver spindle pins

#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PIN         GPIO_NUM_2
#else
#define AUXOUTPUT0_PIN          GPIO_NUM_2
#endif

#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PIN   I2SO(18) // HE1
#else
#define AUXOUTPUT1_PIN          I2SO(18) // HE1
#endif

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PIN      I2SO(17) // HE0
#else
#define AUXOUTPUT2_PIN          I2SO(17) // HE0
#endif

// Define flood and mist coolant enable output pins.

#define COOLANT_FLOOD_PIN       I2SO(19) // FAN1
#define COOLANT_MIST_PIN        I2SO(20) // FAN2

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#define CYCLE_START_PIN         GPIO_NUM_36 // TH1
#define FEED_HOLD_PIN           GPIO_NUM_34 // TH2
//#define RESET_PIN             (use board hardware)

// Define probe switch input pin.
#if PROBE_ENABLE
#define PROBE_PIN               AUXINPUT1_PIN // MT_DET
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         AUXINPUT0_PIN // TB
#endif

#if MODBUS_ENABLE & MODBUS_RTU_DIR_ENABLED
#define MODBUS_DIRECTION_PIN    GPIO_NUM_13 // EXP_1
#elif MPG_ENABLE == 1
#define MPG_ENABLE_PIN          GPIO_NUM_13 // EXP_1
#endif

#if SDCARD_ENABLE
#define PIN_NUM_MISO            GPIO_NUM_19
#define PIN_NUM_MOSI            GPIO_NUM_23
#define PIN_NUM_CLK             GPIO_NUM_18
#define PIN_NUM_CS              GPIO_NUM_5
#endif
