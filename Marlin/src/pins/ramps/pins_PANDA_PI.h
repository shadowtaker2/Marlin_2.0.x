

#ifndef BOARD_NAME
  #define BOARD_NAME "PANDA,PI"
#endif

#define BOARD_INFO_NAME      "PANDA,PI"


/* PANDAPI = 0 => U6 PANDAPI_STM32 */
/* PANDAPI = 1 => U8 PANDAPI */
/* PANDAPI = 2 => U8 KLIPPER */

//
// Servos
//
#if PANDAPIV28 < 1
  #define SERVO0_PIN    255// 0xBE
#else
  #define SERVO0_PIN    PA11   // PWM0 SERVOS
#endif
//
/**
#define X_MIN_PIN          1 
#define X_MAX_PIN          1 

#define Y_MIN_PIN          4 
#define Y_MAX_PIN          4 

#define Z_MAX_PIN          11 
#define Z_MIN_PIN          11 



#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN    255
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  7
#endif
 */
 
//
// TMC StallGuard DIAG pins
//
#if PANDAPIV28 < 1
  #define X_DIAG_PIN              1
  #define Y_DIAG_PIN              4
  #define Z_DIAG_PIN             11

  #define X_STEP_PIN            7  // E1DET
  #define E2_DIAG_PIN            21  // E2DET
#else
  #define X_DIAG_PIN             PA3   // "X-STOP"
  #define Y_DIAG_PIN             PA4   // "Y-STOP"
  #define Z_DIAG_PIN             PA1  // "Z-STOP"
  #define E0_DIAG_PI             PC2  // E0DET
  //#define E1_DIAG_PIN           26  // E1DET
#endif

//
// Limit Switches
//
#ifdef X_STALL_SENSITIVITY
  #define X_STOP_PIN            X_DIAG_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN          E1_DIAG_PIN  // X-MIN
  #else
    #define X_MAX_PIN          E1_DIAG_PIN  // E1DET
  #endif
#else
  #define X_STOP_PIN            X_DIAG_PIN  // X-STOP
#endif

#ifdef Y_STALL_SENSITIVITY
  #define Y_STOP_PIN            Y_DIAG_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN          E2_DIAG_PIN  // Y-MIN
  #else
    #define Y_MAX_PIN          E2_DIAG_PIN  // E2DET
  #endif
#else
  #define Y_STOP_PIN            Y_DIAG_PIN  // Y-STOP
#endif

#ifdef Z_STALL_SENSITIVITY
  #define Z_STOP_PIN            Z_DIAG_PIN
  #if Z_HOME_DIR < 0
    #define Z_MAX_PIN           Z_DIAG_PIN  // Z-MIN
  #else
    #define Z_MIN_PIN           Z_DIAG_PIN  // PWRDET
  #endif
#else
  #define Z_STOP_PIN            Z_DIAG_PIN  // Y-STOP
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PIN             X_STEP_PIN  //7 "PROBE"
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #if PANDAPIV28 < 1
		#define FIL_RUNOUT_PIN  255
	#else
		#define FIL_RUNOUT_PIN  PC2   // "E0-STOP"
	#endif
#endif

//
// Steppers
//
#if PANDAPIV28 < 1
  #define X_STEP_PIN          7 
  #define X_DIR_PIN           2
  #define X_ENABLE_PIN        0 

  #define Y_STEP_PIN         12 
  #define Y_DIR_PIN           5 
  #define Y_ENABLE_PIN        0 

  #define Z_STEP_PIN         14 
  #define Z_DIR_PIN          13 
  #define Z_ENABLE_PIN        0 

  #define E0_STEP_PIN        10  
  #define E0_DIR_PIN          6 
  #define E0_ENABLE_PIN       0 

  #define E1_STEP_PIN        26
  #define E1_DIR_PIN         25
  #define E1_ENABLE_PIN       0

  #define E2_STEP_PIN        31
  #define E2_DIR_PIN         21
  #define E2_ENABLE_PIN       0
  
  #if HAS_TRINAMIC
    #define X_HARDWARE_SERIAL  customizedSerial1
   //  #define X2_HARDWARE_SERIAL customizedSerial1
    #define Y_HARDWARE_SERIAL  customizedSerial1
   //  #define Y2_HARDWARE_SERIAL customizedSerial1
    #define Z_HARDWARE_SERIAL  customizedSerial1
    // #define Z2_HARDWARE_SERIAL customizedSerial1
    #define E0_HARDWARE_SERIAL customizedSerial1
    //#define E1_HARDWARE_SERIAL customizedSerial1
    //#define E2_HARDWARE_SERIAL customizedSerial1
  #endif
#else
  #define X_STEP_PIN         PB8
  #define X_DIR_PIN          PB6
  #define X_ENABLE_PIN       PB9
                                

  #define Y_STEP_PIN         PB5
  #define Y_DIR_PIN          PB4
  #define Y_ENABLE_PIN       PB9

  #define Z_STEP_PIN         PB3
  #define Z_DIR_PIN          PA15
  #define Z_ENABLE_PIN       PB9

  #define E0_STEP_PIN        PB15
  #define E0_DIR_PIN         PB14
  #define E0_ENABLE_PIN      PB9

  #define E1_STEP_PIN        PB2
  #define E1_DIR_PIN         PA7
  #define E1_ENABLE_PIN      PB9

  #define E2_STEP_PIN        PA6
  #define E2_DIR_PIN         PA5
  #define E2_ENABLE_PIN      PB9
/**
 * Default pins for TMC software SPI
 */
  #if HAS_TRINAMIC
    #define TMC_BAUD_RATE           19200
    #ifdef TMC_HARDWARE_SERIAL /*  TMC2209 */
      #define X_HARDWARE_SERIAL  MSerial1
    //  #define X2_HARDWARE_SERIAL MSerial1
      #define Y_HARDWARE_SERIAL  MSerial1
    //  #define Y2_HARDWARE_SERIAL MSerial1
      #define Z_HARDWARE_SERIAL  MSerial1
      // #define Z2_HARDWARE_SERIAL MSerial1
      #define E0_HARDWARE_SERIAL MSerial1
      #define E1_HARDWARE_SERIAL MSerial1
      #define E2_HARDWARE_SERIAL MSerial1
    #else
    //
    // Software serial
    //
      #define X_SERIAL_TX_PIN     PB10
      #define X_SERIAL_RX_PIN     PB11

      #define Y_SERIAL_TX_PIN     PB10
      #define Y_SERIAL_RX_PIN     PB11

      #define Z_SERIAL_TX_PIN     PB10
      #define Z_SERIAL_RX_PIN     PB11

      #define E0_SERIAL_TX_PIN    PB10
      #define E0_SERIAL_RX_PIN    PB11

      #define E1_SERIAL_TX_PIN    PB10
      #define E1_SERIAL_RX_PIN    PB11

      #define E2_SERIAL_TX_PIN    PB10
      #define E2_SERIAL_RX_PIN    PB11
    #endif
  #endif
#endif 

#if PANDAPIV28 < 1
  #if ENABLED(MAX31856_PANDAPI)
    #define MAX31856_CLK_PIN      29
    #define MAX31856_MISO_PIN     24
    #define MAX31856_MOSI_PIN     28
    #define MAX31856_CS_PIN       27
  #endif
#else
//
#endif

//
// Augmentation for auto-assigning RAMPS plugs
//
#if PANDAPIV28 < 1
  #if DISABLED(IS_RAMPS_EEB) && DISABLED(IS_RAMPS_EEF) && DISABLED(IS_RAMPS_EFB) && DISABLED(IS_RAMPS_EFF) && DISABLED(IS_RAMPS_SF) && !PIN_EXISTS(MOSFET_D)
    #if HOTENDS > 1
      #if TEMP_SENSOR_BED
        #define IS_RAMPS_EEB
      #else
        #define IS_RAMPS_EEF
      #endif
    #elif TEMP_SENSOR_BED
      #define IS_RAMPS_EFB
    #else
      #define IS_RAMPS_EFF
    #endif
  #endif
#endif


#if PANDAPIV28 < 1
//
// Heaters / Fans
//

  #ifndef MOSFET_D_PIN
    #define MOSFET_D_PIN     -1
  #endif

// heat connector index

  #define HOTBED_CODE       0
  #define HOTEND_0_CODE     1
  #define HOTEND_1_CODE     2

  #if ENABLED(MAX31856_PANDAPI)
    #define HEATER_0_PIN     30
  #else
    #define HEATER_0_PIN    255
  #endif

  #define HEATER_1_PIN      255
  #define HEATER_BED_PIN    255
  #define TEMP_0_PIN        255
  #define TEMP_1_PIN        255
  #define TEMP_BED_PIN      255
  #define TEMP_BOARD_PIN    255

  #define FAN_PIN           255
  #define FAN1_PIN          255
  #define FAN2_PIN          255
  #define FAN3_PIN          255

  #define CASE_LIGHT_PIN    255
  #define DTH11              22
#else
  #define TEMP_0_PIN        PB0  // Analog Input "TH0"
  #define TEMP_1_PIN        PB1  //
  #define TEMP_2_PIN        PA2  //255

  #define TEMP_BED_PIN     TEMP_1_PIN
  #define TEMP_BOARD_PIN   TEMP_3_PIN  //255

  #if HOTENDS == 1
    #if TEMP_SENSOR_PROBE
      #define TEMP_PROBE_PIN    TEMP_1_PIN
    #elif TEMP_SENSOR_CHAMBER
      #define TEMP_CHAMBER_PIN  TEMP_1_PIN
    #endif
  #endif
  #define HEATER_0_PIN     PB12 //255
  #define HEATER_1_PIN     PA12 //25

  #define HEATER_BED_PIN   PB13 //255

  #define FAN_SOFT_PWM
  #define FAN_PIN          PA8  //255
  #define FAN1_PIN         PA9  //255
  #define FAN2_PIN         PA10 //255
  #define FAN3_PIN         PB7  //255
#endif

//////////////////////////
// LCDs and Controllers //
//////////////////////////
#if PANDAPIV28 < 1
  #if ENABLED(ULTRA_LCD)
    // LCD Display output pins
    #ifdef REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
      #define LCD_PINS_RS      28 
      #define LCD_PINS_ENABLE  29 
      #define LCD_PINS_D4      27  
    #endif

    #define SD_DETECT_PIN   255   
     // LCD Display input pins
    #if ENABLED(NEWPANEL)
      #define BEEPER_PIN	 	24 
      #define BTN_ENC 	  	30 
      #define BTN_EN1 	  	22 
      #define BTN_EN2 	  	23 
    #endif // NEWPANEL
  #endif // ULTRA_LCD
#else
//
#endif
