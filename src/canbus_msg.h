#ifndef CANBUS_MSG_H
#define CANBUS_MSG_H

#define MASK_24BIT 0xFF0  // returns 0x7x0 if message ID is between 0x7x0 and 0x7xF
#define MASK_25BIT 0xFF8  // returns 0x7x8 if message ID is between 0x7x8 and 0x7XF

#define ACCEPT_CODE 0x13F       // 0001 0011 1111 
#define ACCEPT_MASK 0xFFE00000  // 1111 1111 1110 0000 0000 0000 0000 0000

                               // introduction message types
#define INTRO_INTERFACE 0x700  // introduction messages for interface nodes
#define INTRO_BOX       0x750  // introduction messages for box nodes
#define INTRO_OUTPUT    0x718  // introduction messages for output switch modules
#define INTRO_DATA      0x700  // introduction for data modules
#define INTRO_SENSOR    0x740  // introduction for sensor modules
#define INTRO_DIAG      0x730  // introduction for diagnostic modules

                                                          // feature masks for node types
const uint8_t FEATURE_BOX_SW_6GANG_HIGH[] = {0x8E,0xC0};  // feature mask for 6-gang switch box, 4 high, 2 low
const uint8_t FEATURE_BOX_SW_3GANG[] = {0x8E,0x60};       // feature mask for 3-gang output, 2 high, 1 low
const uint8_t FEATURE_BOX_SW_2GANG_LOW[] = {0x8E,0x40};   // feature mask for 2-gang switch box, 2 low
const uint8_t FEATURE_BOX_SW_4GANG[] = {0x8E,0x80};       // feature mask for 4-gang switch box, 2 high, 2 low
const uint8_t FEATURE_BOX_SW_4RELAY[] = {0x8C,0x08};      // feature mask for 4-gang relay output box
const uint8_t FEATURE_BOX_SW_6GANG_LOW[] = {0x8E,0xC0};   // feature mask for 6-gang switch box, 2 high, 4 low
const uint8_t FEATURE_BOX_SW_2GANG_HIGH[] = {0x8E,0x40};  // feature mask for 2-gang switch box, 2 high
const uint8_t FEATURE_BOX_SW_8RELAY[] = {0x8C,0x10};      // feature mask for 8-gang relay output box
const uint8_t FEATURE_BOX_MULTI_4X4IO[] = {0xCC,0x08};    // feature mask for input - output box, 4 in, 4 out
const uint8_t FEATURE_BOX_MULTI_4XTEMP[] = {0xCC,0x00};   // feature mask for 4-digital multi temp input box
const uint8_t FEATURE_BOX_MULTI_TVA[] = {0xBC,0x00};      // feature mask for temp, volt, current input box

const uint8_t FEATURE_IFACE_8X4_ARGB[]           = {0xC1,0xA4};  // feature mask for 8x4 argb keypad
const uint8_t FEATURE_IFACE_4X4_ARGB[]           = {0xA1,0xA4};  // feature mask for 4x4 argb keypad
const uint8_t FEATURE_IFACE_TOUCHSCREEN_TYPE_A[] = {0x81,0xD8};  // feature mask for touchscreen type a
const uint8_t FEATURE_IFACE_TOUCHSCREEN_TYPE_B[] = {0x81,0xD8};  // feature mask for touchscreen type b
const uint8_t FEATURE_IFACE_NEXTION_TYPE_A[]     = {0x81,0xD8};  // feature mask for nextion type a
const uint8_t FEATURE_IFACE_NEXTION_TYPE_B[]     = {0x81,0xD8};  // feature mask for nextion type b
const uint8_t FEATURE_IFACE_6_AXIS_IMU[]         = {0x91,0x80};  // feature mask for 6-axis IMU
const uint8_t FEATURE_IFACE_3X5_BUTTON_BOX[]     = {0x9F,0x80};  // feature mask for 3x5 button box
const uint8_t FEATURE_IFACE_4x6_BUTTON_BOX[]     = {0xB1,0x80};  // feature mask for 4x6 button box
const uint8_t FEATURE_DISP_ANALOG_LED_STRIP[]    = {0x81,0xE2};  // feature mask for analog led strip
const uint8_t FEATURE_DISP_ARGBW_LED_STRIP[]     = {0x81,0xE4};  // feature mask for argbw led strip
const uint8_t FEATURE_DISP_ARGB_LED_STRIP[]      = {0x80,0x64};  // feature mask for argb led strip
const uint8_t FEATURE_DISP_OLED[]                = {0x80,0x40};  // feature mask for non-touch oled display
const uint8_t FEATURE_DISP_LCD[]                 = {0x80,0x48};  // feature mask for non-touch lcd display

// ======================= CUT HERE FOR SHEETS RESYNC ==========================
#define ERROR_OVER_CURRENT 0x100 // over current DLC 6
#define ERROR_OVER_TEMP 0x101 // over temp DLC 6
#define ERROR_OVER_VOLT 0x102 // over volt DLC 6

#define SW_RESERVED110 0x110 // reserved 110 DLC 
#define SW_RESERVED111 0x111 // reserved 111 DLC 
#define SW_SET_MODE 0x112 // set switch mode DLC 6
#define SW_SET_OFF 0x113 // switch off DLC 5
#define SW_SET_ON 0x114 // switch on DLC 5
#define SW_MOM_PRESS 0x115 // switch momentary press DLC 5
#define SW_SET_MOM_DUR 0x116 // set momentary switch duration ms DLC 7
#define SW_SET_PWM_DUTY 0x117 // switch set pwm duty DLC 7
#define SW_SET_PWM_FREQ 0x118 // switch set pwm freq DLC 7
#define SW_SET_BLINK_DELAY 0x119 // switch set blink delay in tenths of a second 1-100 DLC 7
#define SW_SET_STROBE_PAT 0x11A // switch set strobe pattern DLC 6
#define SW_SET_STATE_MEM 0x11B // enable / disable switch last state memory DLC 6

#define SET_DISPLAY_OFF 0x210 // set display off DLC 5
#define SET_DISPLAY_ON 0x211 // set display on DLC 5
#define SET_DISPLAY_CLEAR 0x212 // set display clear DLC 5
#define SET_DISPLAY_FLASH 0x213 // set display flash DLC 6
#define SET_ARGB_BUTTON_COLOR 0x214 // set argb button color DLC 7
#define SET_ARGB_BUTTON_BLINK 0x215 // set argb button blink DLC 6
#define SET_ARGB_BUTTON_STROBE 0x216 // set argb button strobe DLC 6
#define SET_ARGB_BUTTON_LED_MODE 0x217 // set argb button led mode DLC 6
#define SET_DISPLAY_BACKLIGHT_COLOR 0x218 // set display backlight color DLC 8
#define SET_DISPLAY_BACKLIGHT_BRIGHTNESS 0x219 // set display backlight brightness DLC 8
#define SET_RESERVED_21A 0x21A // set reserved 21a DLC 8
#define SET_OLED_REQ_FIELD_CONFIG 0x21B // set oled req field config DLC 8
#define SET_DISP_REQ_DATA 0x21C // set disp req data DLC 8
#define SET_OLED_FIELD_COLOR 0x21D // set oled field color DLC 8
#define SET_OLED_FIELD_BLINK 0x21E // set oled field blink DLC 7
#define SET_OLED_FIELD_STROBE 0x21F // set oled field strobe DLC 7
#define SET_RESERVED_220 0x220 // set reserved 220 DLC 
#define SET_ARGB_STRIP_COLOR 0x221 // set argb strip color DLC 7
#define SET_ARGBW_STRIP_COLOR 0x222 // set argbw strip color DLC 7
#define SET_ANALOG_STRIP_COLOR 0x223 // set analog strip color DLC 7
#define SET_ADDR_STRIP_EFFECT 0x224 // set addr strip effect DLC 7
#define SET_LED_STRIP_BRIGHTNESS 0x225 // set led strip brightness DLC 7
#define SET_LED_STRIP_OFF 0x226 // set led strip off DLC 5
#define SET_LED_STRIP_ON 0x227 // set led strip on DLC 5
#define SET_RESERVED_228 0x228 // set reserved 228 DLC 
#define SET_RESERVED_229 0x229 // set reserved 229 DLC 
#define DISPLAY_DATA_MSG 0x22A // display data msg DLC 8
#define DISPLAY_CONF_MSG 0x22B // display conf msg DLC 8
#define SET_RESERVED_22C 0x22C // set reserved 22c DLC 
#define SET_RESERVED_22D 0x22D // set reserved 22d DLC 
#define SET_RESERVED_22E 0x22E // set reserved 22e DLC 
#define SET_RESERVED_22F 0x22F // set reserved 22f DLC 

#define ACK_INTRO 0x400 // acknowledge introduction, clear flag on remote device DLC 4
#define REQ_NODE_INTRO 0x401 // general intro request for all node types DLC 4
#define MSG_NORM_OPER 0x402 // message to all nodes to being normal operation, sent after introduction and enumeration are complete DLC 
#define MSG_HALT_OPER 0x403 // message to all nodes to stop transmitting messages and wait for instructions DLC 
#define REQ_IFACE 0x404 // req interfaces DLC 4
#define REQ_BUTTONS 0x405 // req buttons DLC 4
#define REQ_OUTPUTS 0x406 // req outputs DLC 4
#define REQ_DISPLAYS 0x407 // req displays DLC 4
#define REQ_TEMP_SENSOR 0x408 // req temp sensor DLC 4
#define REQ_VOLT_SENSOR 0x409 // req volt sensor DLC 4
#define REQ_AMP_SENSOR 0x40A // req amp sensor DLC 4
#define REQ_CLOSURE_INPUT 0x40B // req closure input DLC 4
#define REQ_AMBIENT_LIGHT 0x40C // req ambient light sensors DLC 4
#define REQ_IMU_SENSORS 0x40D // req imu sensors DLC 4
#define REQ_SWITCHBOX 0x40E // req boxes DLC 4
#define REQ_NODECHECK 0x40F // remote nodes should respond with their node id and last boot timestamp DLC 4
#define REQ_HEALTHCHECK 0x410 // remote nodes should respond with diagnostic sensor data DLC 4

#define DATA_BUTTON_DOWN 0x510 // button down DLC 7
#define DATA_BUTTON_UP 0x511 // button up DLC 7
#define DATA_KEYSWITCH_LOCK 0x512 // keyswitch lock DLC 7
#define DATA_KEYSWITCH_UNLOCK 0x513 // keyswitch unlock DLC 7
#define DATA_KNOB_CLOCKWISE 0x514 // knob clockwise DLC 7
#define DATA_KNOB_COUNTER_CLOCKWISE 0x515 // knob counter clockwise DLC 7
#define DATA_KNOB_CLICK 0x516 // knob click DLC 7
#define DATA_RFID_READ 0x517 // rfid read DLC 7
#define DATA_CONTACT_CLOSED 0x518 // contact closed DLC 7
#define DATA_CONTACT_OPENED 0x519 // contact opened DLC 7
#define DATA_RESERVED 0x51A // reserved DLC 7
#define DATA_INTERNAL_PCB_VOLTS 0x51B // internal pcb volts DLC 7
#define DATA_INTERNAL_PCB_CURRENT 0x51C // internal pcb current DLC 7
#define DATA_EXTERNAL_TEMP 0x51D // external temp DLC 7
#define DATA_EXTERNAL_VOLTS 0x51E // external volts DLC 7
#define DATA_EXTERNAL_CURRENT 0x51F // external current DLC 7
#define DATA_AMBIENT_LIGHT 0x520 // ambient light DLC 7
#define DATA_IMU_X_AXIS 0x521 // IMU X Axis DLC 7
#define DATA_IMU_Y_AXIS 0x522 // IMU Y Axis DLC 7
#define DATA_IMU_Z_AXIS 0x523 // IMU Z Axis DLC 7
#define DATA_IMU_X_GYRO 0x524 // IMU X Gyro DLC 7
#define DATA_IMU_Y_GYRO 0x525 // IMU Y Gyro DLC 7
#define DATA_IMU_Z_GYRO 0x526 // IMU Z Gyro DLC 7
#define DATA_RESERVED_527 0x527 // reserved 527 DLC 7
#define DATA_RESERVED_528 0x528 // reserved 528 DLC 7
#define DATA_OUTPUT_SWITCH_MOM_PUSH 0x529 // output switch mom push DLC 7
#define DATA_NODE_CPU_TEMP 0x52A // node cpu temp DLC 6
#define DATA_NODE_LAST_BOOT_TIMESTAMP 0x52B // node last boot timestamp DLC 8
#define DATA_NODE_PCB_TEMP 0x52C // node pcb temp DLC 6
#define DATA_OUTPUT_SWITCH_OFF 0x52D // output switch off DLC 5
#define DATA_OUTPUT_SWITCH_ON 0x52E // output switch on DLC 5
#define DATA_OUTPUT_SWITCH_MODE 0x52F // output switch mode DLC 6
#define DATA_DISPLAY_OFF 0x530 // display off DLC 5
#define DATA_DISPLAY_ON 0x531 // display on DLC 5
#define DATA_DISPLAY_CLEAR 0x532 // display clear DLC 5
#define DATA_DISPLAY_FLASHING 0x533 // display flashing DLC 6
#define DATA_ARGB_BUTTON_COLOR 0x534 // argb button color DLC 7
#define DATA_ARGB_BUTTON_LED_MODE 0x535 // argb button led mode DLC 7

#define IFACE_RES700 0x700 // reserved 700 DLC 
#define IFACE_RES701 0x701 // reserved 701 DLC 
#define IFACE_8X4_ARGB_KEYPAD 0x702 // 8x4 argb keypad DLC 6
#define IFACE_4X4_ARGB_KEYPAD 0x703 // 4x4 argb keypad DLC 6
#define IFACE_TOUCHSCREEN_TYPE_A 0x704 // touchscreen type a DLC 6
#define IFACE_TOUCHSCREEN_TYPE_B 0x705 // touchscreen type b DLC 6
#define IFACE_NEXTION_TYPE_A 0x706 // nextion type a DLC 6
#define IFACE_NEXTION_TYPE_B 0x707 // nextion type b DLC 6
#define IFACE_RESERVED_708 0x708 // reserved 708 DLC 6
#define IFACE_RESERVED_709 0x709 // reserved 709 DLC 6
#define IFACE_RESERVED_70A 0x70A // reserved 70a DLC 6
#define IFACE_6_AXIS_IMU 0x70B // 6 axis imu DLC 6
#define IFACE_3X5_BUTTON_BOX 0x70C // 3x5 button box DLC 6
#define IFACE_4X6_BUTTON_BOX 0x70D // 4x6 button box DLC 6
#define IFACE_RESERVED_70E 0x70E // reserved 70e DLC 6
#define IFACE_RESERVED_70F 0x70F // reserved 70f DLC 6
#define DISP_ANALOG_LED_STRIP 0x710 // analog led strip DLC 8
#define DISP_ARGBW_LED_STRIP 0x711 // argbw led strip DLC 8
#define DISP_ARGB_LED_STRIP 0x712 // argb led strip DLC 8
#define DISP_RESERVED_713 0x713 // reserved 713 DLC 8
#define DISP_RESERVED_714 0x714 // reserved 714 DLC 8
#define DISP_OLED 0x715 // non-touch oled display DLC 8
#define DISP_RESERVED_716 0x716 // reserved 716 DLC 8
#define DISP_LCD 0x717 // non-touch lcd display DLC 8
#define DISP_RESERVED_719 0x718 // reserved 719 DLC 8
#define DISP_RESERVED 0x719 // reserved DLC 
#define OUT_HIGH_CURRENT_SW 0x71A // high current solid state switch DLC 8
#define OUT_LOW_CURRENT_SW 0x71B // low current solid state switch DLC 8
#define OUT_OPEN_DRAIN 0x71C // open drain output DLC 8
#define OUT_MECH_RELAY 0x71D // mechanical relay DLC 8
#define OUT_RESERVED_71E 0x71E // reserved 71e DLC 
#define OUT_RESERVED_71F 0x71F // reserved 71f DLC 
#define BUTTON_NO_BACKLIGHT 0x720 // button no backlight DLC 7
#define BUTTON_ARGB_BACKLIGHT 0x721 // button argb backlight DLC 7
#define BUTTON_ANALOG_BACKLIGHT 0x722 // button analog backlight DLC 7
#define BUTTON_VIRTUAL 0x723 // button virtual DLC 7
#define BUTTON_WITH_DISPLAY 0x724 // button with display DLC 7
#define BUTTON_ANALOG_KNOB 0x725 // analog knob input DLC 7
#define BUTTON_JOG_DIAL_CLICK 0x726 // jog dial with click DLC 7
#define BUTTON_KEY_SWITCH 0x727 // key switch DLC 7
#define BUTTON_MOTION_DET 0x728 // motion detector DLC 7
#define BUTTON_CAP_TOUCH 0x729 // capacitive touch switch stand-alone DLC 
#define BUTTON_JOG_DIAL_NOCLICK 0x72A // jog dial without click DLC 7
#define INPUT_RFID_READER 0x72B // RFID reader input DLC 
#define INPUT_RESERVED_72C 0x72C // reserved 72c DLC 
#define INPUT_RESERVED_72D 0x72D // reserved 72d DLC 
#define INPUT_DIGITAL_TEMP 0x72E // input digital temp DLC 5
#define INPUT_K_TYPE_TEMP 0x72F // input k type temp DLC 5
#define NODE_RESERVED_730 0x730 // reserved 730 DLC 5
#define NODE_LASTBOOT 0x731 // last boot timestamp DLC 5
#define NODE_PCB_TEMP 0x732 // node pcb temp DLC 5
#define NODE_CPU_TEMP 0x733 // node cpu temp DLC 5
#define INPUT_EXT_VOLTAGE_SENSOR 0x734 // input ext voltage sensor DLC 5
#define NODE_INT_VOLTAGE_SENSOR 0x735 // node int voltage sensor DLC 5
#define NODE_RESERVED_736 0x736 // reserved 736 DLC 5
#define NODE_RESERVED_737 0x737 // reserved 737 DLC 5
#define NODE_INT_CURRENT_SENSOR 0x738 // node int current sensor DLC 5
#define INPUT_EXT_CURRENT_SHUNT 0x739 // input ext current shunt DLC 5
#define INPUT_EXT_CURRENT_HALL 0x73A // input ext current hall DLC 5
#define GPS_ALTITUDE 0x73B // GPS altitude DLC 5
#define GPS_STATUS 0x73C // GPS status DLC 5
#define BUTTON_CONTACT_PULL_DOWN 0x73D // button contact pull down DLC 5
#define BUTTON_CONTACT_PULL_UP 0x73E // button contact pull up DLC 5
#define CONTACT_CLOSURE_RESERVED 0x73F // contact closure reserved DLC 5
#define CONTACT_CLOSURE_RESERVED 0x740 // contact closure reserved DLC 5
#define INPUT_AMBIENT_LIGHT 0x741 // input ambient light DLC 5
#define IMU_X_AXIS_SENSOR 0x742 // IMU X Axis sensor DLC 5
#define IMU_Y_AXIS_SENSOR 0x743 // IMU Y Axis sensor DLC 5
#define IMU_Z_AXIS_SENSOR 0x744 // IMU Z Axis sensor DLC 5
#define IMU_X_GYRO_SENSOR 0x745 // IMU X Gyro sensor DLC 5
#define IMU_Y_GYRO_SENSOR 0x746 // IMU Y Gyro sensor DLC 5
#define IMU_Z_GYRO_SENSOR 0x747 // IMU Z Gyro sensor DLC 5
#define IMU_RESERVED_748 0x748 // IMU reserved 748 DLC 
#define IMU_RESERVED_749 0x749 // IMU reserved 749 DLC 
#define IMU_RESERVED_74A 0x74A // IMU reserved 74a DLC 
#define GPS_UTC_TIME 0x74B // GPS utc time DLC 
#define GPS_LATITUDE 0x74C // GPS latitude DLC 
#define GPS_NS_IND 0x74D // GPS NS IND DLC 
#define GPS_LONGITUDE 0x74E // GPS longitude DLC 
#define GPS_EW_IND 0x74F // GPS EW IND DLC 
#define BOX_SW_3GANG 0x750 // 3 gang switch box, 2 high, 1 low DLC 6
#define BOX_SW_4GANG 0x751 // 4-gang switch box, 2 high, 2 low DLC 6
#define BOX_SW_6GANG_HIGH 0x752 // 6-gang switch box, 4 high, 2 low DLC 6
#define BOX_SW_6GANG_LOW 0x753 // 6-gang switch box, 2 high, 4 low DLC 6
#define BOX_SW_2GANG_HIGH 0x754 // 2-gang switch box, 2 high DLC 6
#define BOX_SW_2GANG_LOW 0x755 // 2-gang switch box, 2 low DLC 6
#define BOX_MULTI_4XTEMP 0x756 // 4-digital multi temp input box DLC 6
#define BOX_SW_4RELAY 0x757 // 4-gang relay output box DLC 6
#define BOX_MULTI_TVA 0x758 // temp, volt, current input box DLC 6
#define BOX_SW_8RELAY 0x759 // 8-gang relay output box DLC 6
#define BOX_MULTI_4X4IO 0x75A // input - output box, 4 in, 4 out DLC 6
// ======================= CUT HERE FOR SHEETS RESYNC ==========================

#endif