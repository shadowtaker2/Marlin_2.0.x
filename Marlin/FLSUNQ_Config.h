/*==========================================================================
*=================== FLSunQ - DELTA Printers ===============================
*================= With pins_FLSUN_HiSPEED.h BOARD (QQS-Pro)================
*================= With pins_MKS_ROBIN_NANO.h BOARD (Q5)====================
*===========================================================================
*
* For a Delta printer start with one of the configuration files in the
* config/examples/delta/FLSUN/ directory and customize for your machine.
* 
* Wiki: https://github.com/Foxies-CSTL/Marlin_2.0.x/wiki
* 
* TIPS/NOTES:
* -For TMC mode UART, look the "pins_FLSUN_HISPEED.h" file (src/pins/stm32f1/) for more information to wire.
* -Comment/Uncomment line to add or modify some options. 
*  Default is for QQS and it's uncommented ;-)
*/
//#define XP
//#define DBUG
/*_______________________1___________________________*/
//==================== Hardware =====================//
/*-------------Motherboard/Printer-(1 CHOICE)-------*/
#define QQSP                       //  (Default_QQS) env = flsun_hispeedv1
//#define Q5                         // env = mks_nano_robin35 (change in platformio.ini file or 
                                     // click on the "Default" icon on the bottom edge of the window and 
                                     // choose "mks_robin_nano35").

/*________________________2___________________________*/
          /*-----Type Drivers-(1 CHOICE)-----*/
/* MODE STOCK for QQS & Q5 */
#define STOCK                      // (S) (Default_QQS) For 4xA4988(green or red color).
                                     // (S) (Default_Q5) For 3xTMC2208+1xA4988.

/* MODE STANDALONE XYZ+E for QQS & Q5 */
//#define ALL_TMC8                    //(8) For 4xTMC2208_STANDALONE
//#define ALL_TMC9                    //(9) For 4xTMC2209_STANDALONE

/* MODE UART XYZ+E for QQS & Q5 */
//#define Q_UART8                    //(U8) 4xTMC2208 Note: remove on your printer the module WIFI and wire your TMC.
//#define Q_UART9                    //(U9) 4xTMC2209 Note: remove on your printer the module WIFI and wire your TMC.

/* SPECIAL MODE UART XYZ+E for QQS-Pro */
//#define QQS_UARTH                  //(UH) Mode special 2209 wiring with one I/O pin (Remove module ESP12)

/**========================2bis=================================//
 * -- If you have an other stepper driver for EXTRUDER----------//
 * -- Uncomment and choose Options: ----------------------------//
 * -- A4988/DRV8825/LV8729/...      ----------------------------//
 * -- TMC2208_STANDALONE/TMC2209_STANDALONE/TMC2208/TMC2209. ---//
 * =============================================================//
 */
//#define DRIVER_EXT A4988  //TMC2209_STANDALONE //LV8729//
//Only WITH Q5 older stepper(A4988/DRV8825/LV8729)
//#define INV_EXT

/*__________________________3________________________________*/
        /** =============================
        * =====Type of TFT screen ======
        * = Driver TFT Color (1 CHOICE)=
        * ==============================
        */
#define MKS_ROBIN_TFT32            //  (Default) Mks_Robin_TFT_V2.0
//#define MKS_TS35_V2_00             // Only for NanoV2 or V3
//#define TFT_GENERIC                // For the user who haven't the same screen.

                /*--- Choice UI TFT ----*/
#define TFT_COLOR_UI               //(C) (Default) UI MARLIN
//#define TFT_CLASSIC_UI             //(F) UI STANDARD (type LCD)

#define TOUCH_SCREEN               //(C/F) (Default) UI MARLIN

/* ======================================//
* === Note:Languages already integrated==// 
* ==in the menu UI_COLOR(fr, de, es, it)=//
* =======================================//
*/
//#define LCD_LANGUAGE en            // Change for your country ('bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'el':'Greek', 'fi':'Finnish', 'hr':'Croatian', 'hu':'Hungarian', 'jp_kana':'Japanese', 'nl':'Dutch', 'pl':'Polish', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', etc)
//#define BOOT_MARLIN_LOGO_SMALL     // Small Logo Marlin to reduce de binary. Comment to have normal LOGO(Default).

/*__________________________4______________________________*/
                  /*----  Modules -----*/

#define MKS_WIFI                   //(W) (Default_QQS) Module ESP8266/ESP12
//#define ESP3D_30                   //(w) Enable firmware ESP3D v3.0 (ESP8266/ESP12)

/*For LedStrip which need an external power source on Vcc pin.*/
//#define NEOPIXEL_LED               //(N) Use port GPIO Wifi module (PC7)

/**=========================================================
 * =========================================================
 * = QQS/Q5 Stock have a clone (T)ITAN EXtruder(Default),===
 * = If you have another choose by uncomment your extruder.=
 * = Also you can change the direction.=====================
 * ====== Default eStep (T=397/422)/(B=417)/(H+702) ========
 * =========================================================
 */
//#define INV_EXT                    // Uncommment to reverse direction for BMG/Sherpa.

// BMG Extruder (B) Extruder step(417).
//#define BMG                        //(B) Uncommment for BMG Left/Right.
//#define SHERPA                     //(h) Uncommment for Mini-Sherpa.

/*__________________________5_____________________________*/
      /** =============================
      * ======= MODE LEVELING==========
      * == type Calibration UBL or ABL=
      * ========= 1 CHOICE)============
      * ===============================
      */

//#define DELTA_HOME_TO_SAFE_ZONE    // Option to move down after homing to a height where XYZ movement is unconstrained.
#define PREHEAT_BEFORE_PROBING     //(P) (Default) Run a PreHeat bed at 60°C
//#define PREHEAT_BEFORE_LEVELING    
#define AUTO_BED_LEVELING_UBL      //(U) (Default) Wizard UBL includes. 
#define UBL_HILBERT_CURVE          // (Default)

//--------IF YOUR USED ABL, DISABLE "SPECIAL MENU DELTA"= #define CUSTOM_MENU_MAIN
//#define AUTO_BED_LEVELING_BILINEAR //(A)


/*__________________________6__________________________*/
    //======Many options for Modules: ===========//
#define LIN_ADVANCE                //(L) (Default2209) with K=0 For TMC_UART2208 prefer mode spreadCycle(by TFT menu) or commented if problem.
#define ARC_SUPPORT                //(R) (Default)
#define POWER_LOSS_RECOVERY        // (Default) Continue print after Power-Loss.

//=================================================================================//
//======================== End_Hardware ===========================================//
//=================================================================================//

/*__________________________7__________________________*/
/** =====================================================
 *  ==== For users who dont have a terminal ============= 
 * = like (Prontoface/Octoprint/HostRepertier/Astoprint)=
 * ====== Choice add menu on TFT: (OPT) =================
 */
#define DELTA_CALIBRATION_MENU     //  (Default) Auto for CLASSIC and COLOR.
#define CUSTOM_MENU_MAIN           //  (Default) Main Menu UBL: "Menu Special Delta".
#define PID_EDIT_MENU              //  (Default) Tune PID Bed and Nozzle.
#define PID_AUTOTUNE_MENU          //  (Default) Tune auto PID.
#define LCD_INFO_MENU              //  (Default) Informations printer.
#define PROBE_OFFSET_WIZARD        //  (Default) Add Menu to manage the Z_OffSet.
//#define PREHEAT_SHORTCUT_MENU_ITEM // Add preheat/temperature menu (first page)
//#define CANCEL_OBJECTS             // Add menu "Cancel Objet"

// For user who change their nozzle thermistor by another one ex: "ATC Semitec 104GT-2" = 5 
//#define TEMP_SENSOR_0 13             // uncomment with a good number/type.

// ---Expe tools Levelling-------
//#define LEVEL_BED_CORNERS
//#define G26_MESH_VALIDATION          // Print Mesh Validation Pattern tool(By menu).

/*__________________________8__________________________*/
/** ===================================================
* == Option for Host (OCTOPRINT,REPETIER,PRONTERFACE,ESP3D, etc)
* ======================================================
*/
//#define HOST_ACTION_COMMANDS        // Action Command Prompt support Message on Octoprint

//------ Support for MeatPack G-code compression (OCTOPRINT)--------//
#define MEATPACK_ON_SERIAL_PORT_1   //(M) With connection USB
//#define MEATPACK_ON_SERIAL_PORT_2   // With other connection like Tx/Rx Wifi socket.

/** ========================================
* == Options for Modules Hardware MKS_WIFI
* ==========================================
* Note:You must update the Wifi module with
* the ESP3D firmware or the MKS(Stock) firmware.
* https://github.com/Foxies-CSTL/Marlin_2.0.x/wiki/5.Firmware-Wifi
*/
// 
#ifdef MKS_WIFI
  #define ESP_WIFI
  #ifdef ESP3D_30
    #define MKS_WIFI_MODULE           // Work with TFT_LVGL_UI(Modern UI using LVGL-MKS)
    #define USES_MKS_WIFI_FUNCTION    // Bin transfert MKS for ESP3D firmware v3.0 or others
  #endif
  //#define BINARY_FILE_TRANSFER     // Bin transfert for ESP3D firmware v2.1 or others.
                                     // Not compatible with the MEATPACK option. 
#endif

//TFT Type For TFT_GENERIC
#if ENABLED(TFT_GENERIC)
  #define TFT_DRIVER AUTO
  #define TFT_INTERFACE_FSMC  //Default socket on MKS_nano, mini, hispeed.
  #define TFT_RES_320x240
#endif

// Options for Modules Hardware
#ifdef NEOPIXEL_LED
  #define LED_CONTROL_MENU            // To control LedStrip.
#endif

/** -------------------------------------------------
 * Special mod: Disable MKS_WIFI/TFT part/DELTA_MENU 
 *          TFT Type Mks_H43 
 */
//#define DGUS_LCD_UI_MKS             // Mks_H43_v1.0 Note: The wiring is done on the UART2
                                      // Wifi port(PA10/PA9) for Tx/Rx.
/**
 * =================================================
 * ===Part for Hardware definitions=================
 * ===Don't change if you're not sure how to do it.= 
 * =================================================
 */
// Variables to calculate steps and current
//eSteps
#ifdef BMG
  #define EXTRUDER_STEPS 417    // Extruder BMG(Left/Right)
#else
  #ifdef SHERPA
    #define EXTRUDER_STEPS 702  // Extruder Mini-Sherpa
  #else
    #define EXTRUDER_STEPS 405  // Extruder TITAN(Default)
  #endif
#endif

//Z_OffSet
#ifndef Q5
  #define Z_OFFSET       -16.2
#else
  #define Z_OFFSET       -18
#endif

// TMC
#ifndef XYZ_CURRENT
  #define XYZ_CURRENT       900
#endif
#ifndef XYZ_CURRENT_HOME
  #define XYZ_CURRENT_HOME  800
#endif  
#ifndef E_CURRENT
  #ifdef SHERPA
    #define E_CURRENT         300
  #else
    #define E_CURRENT         850
  #endif
#endif

// Set for QQS(4xA4988) or Q5(3x2208+A4988) 
#ifdef STOCK
  #ifdef Q5
    #define DRIVER_AXES TMC2208_STANDALONE
  #else
    #define DRIVER_AXES A4988
  #endif  
  #ifndef DRIVER_EXT
    #define DRIVER_EXT A4988
  #endif
#endif

// Set for TMC2208_STANDALONE
#ifdef ALL_TMC8
    #define Q_TMC
    #undef LIN_ADVANCE
    #define DRIVER_AXES TMC2208_STANDALONE
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2208_STANDALONE
    #endif
#endif
// Set for TMC2209_STANDALONE 
#ifdef ALL_TMC9
    #define Q_TMC
    #define DRIVER_AXES TMC2209_STANDALONE
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209_STANDALONE
    #endif
#endif

// Software Serial UART for TMC2208
#ifdef Q_UART8
    #define Q_TMC
    #undef LIN_ADVANCE
    #define DRIVER_AXES TMC2208
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2208
    #endif
#endif

// Software Serial UART for TMC2209
#ifdef Q_UART9
    #define Q_TMC
    #define STEALTHCHOP_E
    #define DRIVER_AXES TMC2209
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif
//Add definition for UART9 for Q5
#if BOTH(Q5, Q_UART8)||BOTH(Q5, Q_UART9)
    #define X_SERIAL_TX_PIN                   PA10  // RXD1
    #define X_SERIAL_RX_PIN                   PA10  // RXD1
    #define Y_SERIAL_TX_PIN                   PA9   // TXD1
    #define Y_SERIAL_RX_PIN                   PA9   // TXD1
    #define Z_SERIAL_TX_PIN                   PC7   // IO1
    #define Z_SERIAL_RX_PIN                   PC7   // IO1
    #define E0_SERIAL_TX_PIN                  PC13  // IO0
    #define E0_SERIAL_RX_PIN                  PC13  // IO0
    #define TMC_BAUD_RATE                    19200
#endif
// Note:
// HardwareSerial with one pins for four drivers
// Compatible with TMC2209. Provides best performance.
// Requires SLAVE_ADDRESS definitions in Configuration_adv.h
// and proper jumper configuration. Uses I/O pins PA8(Default QQS).
#ifdef QQS_UARTH
    #define Q_TMC
    #define TMC_HARDWARE_SERIAL
    #define STEALTHCHOP_E
    #define DRIVER_AXES TMC2209
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif
