#ifndef CANBUS_MSG_H
#define CANBUS_MSG_H


#define           FEATURE_MASK_SIZE     2 // size of feature mask in bytes
#define           NODE_ID_SIZE          4 // node ID length in bytes

// Define clear return values for various error conditions
#define           NODE_NOT_FOUND        -1
#define           NODE_LIST_FULL        -5
#define           NODE_ID_INVALID       -2
#define           NODE_ALREADY_EXISTS   -6
#define           MODULE_NOT_FOUND      -10
#define           MODULE_ALREADY_EXISTS -3
#define           MODULE_LIST_FULL      -4

#define MASK_24BIT 0xFF0  // returns 0x7x0 if message ID is between 0x7x0 and 0x7xF

#define ACCEPT_CODE 0x13F       // 0001 0011 1111 
#define ACCEPT_MASK 0xFFE00000  // 1111 1111 1110 0000 0000 0000 0000 0000

// node and module masks 
#define INTRO_INTERFACE 0x700  // introduction interface nodes includes buttons, displays, leds
#define INTRO_BOX       0x750  // introduction box nodes includes switch boxes, relay boxes, input-output boxes
#define INTRO_DISPLAY   0x710  // introduction for data modules
#define INTRO_BUTTON    0x720  // introduction for button modules
#define INTRO_SENSOR    0x730  // introduction for sensors
#define INTRO_SENSOR2   0x740  // introduction for more sensors
#define INTRO_OUTPUT    0x760  // introduction for output switch modules

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

#define SET_DISPLAY_OFF 0x200 // set display off DLC 5
#define SET_DISPLAY_ON 0x201 // set display on DLC 5
#define SET_DISPLAY_CLEAR 0x202 // set display clear DLC 5
#define SET_DISPLAY_FLASH 0x203 // set display flash DLC 6
#define SET_DISPLAY_BACKLIGHT_COLOR 0x204 // set display backlight color DLC 7
#define SET_DISPLAY_BACKLIGHT_BRIGHTNESS 0x205 // set display backlight brightness DLC 6
#define REQ_DISPLAY_CONFIG 0x206 // req display config DLC 6
#define REQ_DISPLAY_DATA 0x207 // req display data DLC 6
#define SET_OLED_FIELD_COLOR 0x208 // set oled field color DLC 8
#define SET_OLED_FIELD_BLINK 0x209 // set oled field blink DLC 8
#define SET_OLED_FIELD_STROBE 0x20A // set oled field strobe DLC 8
#define SET_DISPLAY_RESERVED_20B 0x20B // set display reserved 20b DLC 8
#define SET_DISPLAY_RESERVED_20C 0x20C // set display reserved 20c DLC 8
#define DISPLAY_DATA_MSG 0x20D // display data msg DLC 8
#define DISPLAY_DATA_ACK 0x20E // display data ack DLC 8
#define SET_DISPLAY_RESERVED_20F 0x20F // set display reserved 20f DLC 
#define SET_ARGB_STRIP_COLOR 0x210 // set argb strip color DLC 
#define SET_ARGBW_STRIP_COLOR 0x211 // set argbw strip color DLC 7
#define SET_ANALOG_STRIP_COLOR 0x212 // set analog strip color DLC 7
#define SET_ADDR_STRIP_EFFECT 0x213 // set addr strip effect DLC 7
#define SET_LED_STRIP_BRIGHTNESS 0x214 // set led strip brightness DLC 7
#define SET_LED_STRIP_OFF 0x215 // set led strip off DLC 7
#define SET_LED_STRIP_ON 0x216 // set led strip on DLC 5
#define SET_LED_RESERVED_217 0x217 // set led reserved 217 DLC 5
#define SET_LED_RESERVED_218 0x218 // set led reserved 218 DLC 
#define SET_LED_RESERVED_219 0x219 // set led reserved 219 DLC 
#define SET_LED_RESERVED_21A 0x21A // set led reserved 21a DLC 
#define SET_LED_RESERVED_21B 0x21B // set led reserved 21b DLC 
#define SET_LED_RESERVED_21C 0x21C // set led reserved 21c DLC 
#define SET_LED_RESERVED_21D 0x21D // set led reserved 21d DLC 
#define SET_LED_RESERVED_21E 0x21E // set led reserved 21e DLC 
#define SET_LED_RESERVED_21F 0x21F // set led reserved 21f DLC 
#define SET_ARGB_BUTTON_COLOR 0x220 // set argb button color DLC 
#define SET_ARGB_BUTTON_LED_MODE 0x221 // set argb button led mode DLC 
#define SET_BUTTON_MODE 0x222 // set button mode 0 disabled, 1 toggle, 2 momentary DLC 

#define ACK_INTRO 0x400 // acknowledge introduction, clear flag on remote device DLC 4
#define REQ_NODE_INTRO 0x401 // general intro request for all node types DLC 4
#define MSG_NORM_OPER 0x402 // message to all nodes to being normal operation, sent after introduction and enumeration are complete DLC 4
#define MSG_HALT_OPER 0x403 // message to all nodes to stop transmitting messages and wait for instructions DLC 4
#define REQ_NODECHECK 0x404 // remote nodes should respond with their node id and last boot timestamp DLC 4
#define REQ_HEALTHCHECK 0x405 // remote nodes should respond with diagnostic sensor data DLC 4
#define REQ_IFACE 0x406 // req interfaces node include buttons, displays leds and sensors DLC 4
#define REQ_SWITCHBOX 0x407 // req switch boxes nodes include anything that controls a load DLC 4

#define REQ_BUTTONS 0x410 // req buttons DLC 
#define REQ_OUTPUTS 0x411 // req outputs DLC 
#define REQ_DISPLAYS 0x412 // req displays DLC 
#define REQ_TEMP_SENSOR 0x413 // req temp sensor DLC 
#define REQ_VOLT_SENSOR 0x414 // req volt sensor DLC 
#define REQ_AMP_SENSOR 0x415 // req amp sensor DLC 
#define REQ_CLOSURE_INPUT 0x416 // req closure input DLC 
#define REQ_AMBIENT_LIGHT 0x417 // req ambient light sensors DLC 
#define REQ_IMU_SENSORS 0x418 // req imu sensors DLC 

#define DATA_BUTTON_DOWN 0x500 // button down DLC 7
#define DATA_BUTTON_UP 0x501 // button up DLC 7
#define DATA_KEYSWITCH_LOCK 0x502 // keyswitch lock DLC 7
#define DATA_KEYSWITCH_UNLOCK 0x503 // keyswitch unlock DLC 7
#define DATA_KNOB_CLOCKWISE 0x504 // knob clockwise DLC 7
#define DATA_KNOB_COUNTER_CLOCKWISE 0x505 // knob counter clockwise DLC 7
#define DATA_KNOB_CLICK 0x506 // knob click DLC 7
#define DATA_RFID_READ 0x507 // rfid read DLC 7
#define DATA_CONTACT_CLOSED 0x508 // contact closed DLC 7
#define DATA_CONTACT_OPENED 0x509 // contact opened DLC 7
#define DATA_RESERVED 0x50A // reserved DLC 7
#define DATA_INTERNAL_PCB_VOLTS 0x50B // internal pcb volts DLC 7
#define DATA_INTERNAL_PCB_CURRENT 0x50C // internal pcb current DLC 7
#define DATA_EXTERNAL_TEMP 0x50D // external temp DLC 7
#define DATA_EXTERNAL_VOLTS 0x50E // external volts DLC 7
#define DATA_EXTERNAL_CURRENT 0x50F // external current DLC 7
#define DATA_AMBIENT_LIGHT 0x510 // ambient light DLC 7
#define DATA_IMU_X_AXIS 0x511 // IMU X Axis DLC 7
#define DATA_IMU_Y_AXIS 0x512 // IMU Y Axis DLC 7
#define DATA_IMU_Z_AXIS 0x513 // IMU Z Axis DLC 7
#define DATA_IMU_X_GYRO 0x514 // IMU X Gyro DLC 7
#define DATA_IMU_Y_GYRO 0x515 // IMU Y Gyro DLC 7
#define DATA_IMU_Z_GYRO 0x516 // IMU Z Gyro DLC 7
#define DATA_RESERVED_527 0x517 // reserved 527 DLC 7
#define DATA_RESERVED_528 0x518 // reserved 528 DLC 7
#define DATA_OUTPUT_SWITCH_MOM_PUSH 0x519 // output switch mom push DLC 7
#define DATA_NODE_CPU_TEMP 0x51A // node cpu temp DLC 6
#define DATA_NODE_LAST_BOOT_TIMESTAMP 0x51B // node last boot timestamp DLC 8
#define DATA_NODE_PCB_TEMP 0x51C // node pcb temp DLC 6
#define DATA_OUTPUT_SWITCH_OFF 0x51D // output switch off DLC 5
#define DATA_OUTPUT_SWITCH_ON 0x51E // output switch on DLC 5
#define DATA_OUTPUT_SWITCH_MODE 0x51F // output switch mode DLC 6
#define DATA_DISPLAY_OFF 0x520 // display off DLC 5
#define DATA_DISPLAY_ON 0x521 // display on DLC 5
#define DATA_DISPLAY_CLEAR 0x522 // display clear DLC 5
#define DATA_DISPLAY_FLASHING 0x523 // display flashing DLC 6
#define DATA_ARGB_BUTTON_COLOR 0x524 // argb button color DLC 7
#define DATA_ARGB_BUTTON_LED_MODE 0x525 // argb button led mode DLC 7
#define DATA_EPOCH 0x526 // epoch from controller DLC 

#define IFACE_8X4_ARGB_KEYPAD 0x700 // 8x4 argb keypad DLC 
#define IFACE_4X4_ARGB_KEYPAD 0x701 // 4x4 argb keypad DLC 
#define IFACE_TOUCHSCREEN_TYPE_A 0x702 // touchscreen type a DLC 6
#define IFACE_TOUCHSCREEN_TYPE_B 0x703 // touchscreen type b DLC 6
#define IFACE_NEXTION_TYPE_A 0x704 // nextion type a DLC 6
#define IFACE_NEXTION_TYPE_B 0x705 // nextion type b DLC 6
#define IFACE_RESERVED_706 0x706 // iface reserved 706 DLC 6
#define IFACE_RESERVED_707 0x707 // iface reserved 707 DLC 6
#define IFACE_RESERVED_708 0x708 // iface reserved 708 DLC 6
#define IFACE_6_AXIS_IMU 0x709 // 6 axis imu DLC 6
#define IFACE_3X5_BUTTON_BOX 0x70A // 3x5 button box DLC 6
#define IFACE_4X6_BUTTON_BOX 0x70B // 4x6 button box DLC 6
#define IFACE_RESERVED_70C 0x70C // iface reserved 70c DLC 6
#define IFACE_RESERVED_70D 0x70D // iface reserved 70d DLC 6
#define IFACE_RESERVED_70E 0x70E // iface reserved 70e DLC 6
#define IFACE_RESERVED_70F 0x70F // iface reserved 70f DLC 6
#define DISP_ANALOG_LED_STRIP 0x710 // analog led strip DLC 8
#define DISP_ARGBW_LED_STRIP 0x711 // argbw led strip DLC 8
#define DISP_ARGB_LED_STRIP 0x712 // argb led strip DLC 8
#define DISP_RESERVED_713 0x713 // disp reserved 713 DLC 8
#define DISP_RESERVED_714 0x714 // disp reserved 714 DLC 8
#define DISP_OLED 0x715 // non-touch oled display DLC 8
#define DISP_RESERVED_716 0x716 // disp reserved 716 DLC 8
#define DISP_LCD 0x717 // non-touch lcd display DLC 8
#define DISP_RESERVED_718 0x718 // disp reserved 718 DLC 
#define DISP_RESERVED_719 0x719 // disp reserved 719 DLC 
#define DISP_RESERVED_71A 0x71A // disp reserved 71a DLC 
#define DISP_RESERVED_71B 0x71B // disp reserved 71b DLC 
#define DISP_RESERVED_71C 0x71C // disp reserved 71c DLC 
#define DISP_RESERVED_71D 0x71D // disp reserved 71d DLC 
#define DISP_RESERVED_71E 0x71E // disp reserved 71e DLC 
#define DISP_RESERVED_71F 0x71F // disp reserved 71f DLC 
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
#define BUTTON_CONTACT_PULL_DOWN 0x72C // button contact pull down DLC 
#define BUTTON_CONTACT_PULL_UP 0x72D // button contact pull up DLC 
#define CONTACT_CLOSURE_RESERVED 0x72E // contact closure reserved DLC 5
#define CONTACT_CLOSURE_RESERVED 0x72F // contact closure reserved DLC 5
#define INPUT_DIGITAL_TEMP 0x730 // input digital temp DLC 5
#define INPUT_K_TYPE_TEMP 0x731 // input k type temp DLC 5
#define NODE_LASTBOOT 0x732 // last boot timestamp DLC 5
#define NODE_PCB_TEMP 0x733 // node pcb temp DLC 5
#define NODE_CPU_TEMP 0x734 // node cpu temp DLC 5
#define INPUT_EXT_VOLTAGE_SENSOR 0x735 // input ext voltage sensor DLC 5
#define NODE_INT_VOLTAGE_SENSOR 0x736 // node int voltage sensor DLC 5
#define NODE_RESERVED_737 0x737 // reserved 737 DLC 5
#define NODE_INT_CURRENT_SENSOR 0x738 // node int current sensor DLC 5
#define INPUT_EXT_CURRENT_SHUNT 0x739 // input ext current shunt DLC 5
#define INPUT_EXT_CURRENT_HALL 0x73A // input ext current hall DLC 5
#define GPS_ALTITUDE 0x73B // GPS altitude DLC 5
#define GPS_STATUS 0x73C // GPS status DLC 5
#define SENSOR_RESERVED_0X73D 0x73D // reserved 0x73D DLC 5
#define SENSOR_RESERVED_0X73E 0x73E // reserved 0x73E DLC 5
#define SENSOR_RESERVED_0X73F 0x73F // reserved 0x73F DLC 5
#define INPUT_AMBIENT_LIGHT 0x740 // input ambient light DLC 5
#define IMU_X_AXIS_SENSOR 0x741 // IMU X Axis sensor DLC 5
#define IMU_Y_AXIS_SENSOR 0x742 // IMU Y Axis sensor DLC 5
#define IMU_Z_AXIS_SENSOR 0x743 // IMU Z Axis sensor DLC 5
#define IMU_X_GYRO_SENSOR 0x744 // IMU X Gyro sensor DLC 5
#define IMU_Y_GYRO_SENSOR 0x745 // IMU Y Gyro sensor DLC 5
#define IMU_Z_GYRO_SENSOR 0x746 // IMU Z Gyro sensor DLC 5
#define GPS_UTC_TIME 0x747 // GPS utc time DLC 5
#define GPS_LATITUDE 0x748 // GPS latitude DLC 
#define GPS_NS_IND 0x749 // GPS NS IND DLC 
#define GPS_LONGITUDE 0x74A // GPS longitude DLC 
#define GPS_EW_IND 0x74B // GPS EW IND DLC 
#define SENSOR2_RESERVED_74C 0x74C // sensor2 reserved 74c DLC 
#define SENSOR2_RESERVED_74D 0x74D // sensor2 reserved 74d DLC 
#define SENSOR2_RESERVED_74E 0x74E // sensor2 reserved 74e DLC 
#define SENSOR2_RESERVED_74F 0x74F // sensor2 reserved 74f DLC 
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
#define BOX_RESERVED_75B 0x75B // box reserved 75b DLC 
#define BOX_RESERVED_75C 0x75C // box reserved 75c DLC 
#define BOX_RESERVED_75D 0x75D // box reserved 75d DLC 
#define BOX_RESERVED_75E 0x75E // box reserved 75e DLC 
#define BOX_RESERVED_75F 0x75F // box reserved 75f DLC 
#define OUT_HIGH_CURRENT_SW 0x760 // high current solid state switch DLC 
#define OUT_LOW_CURRENT_SW 0x761 // low current solid state switch DLC 
#define OUT_OPEN_DRAIN 0x762 // open drain output DLC 
#define OUT_MECH_RELAY 0x763 // mechanical relay DLC 
#define OUT_RESERVED_0X764 0x764 // reserved 0x764 DLC 
#define OUT_RESERVED_0X765 0x765 // reserved 0x765 DLC 
#define OUT_RESERVED_0X766 0x766 // reserved 0x766 DLC 
#define OUT_RESERVED_0X767 0x767 // reserved 0x767 DLC 
#define OUT_RESERVED_0X768 0x768 // reserved 0x768 DLC 
#define OUT_RESERVED_0X769 0x769 // reserved 0x769 DLC 
#define OUT_RESERVED_0X76A 0x76A // reserved 0x76A DLC 
#define OUT_RESERVED_0X76B 0x76B // reserved 0x76B DLC 
#define OUT_RESERVED_0X76C 0x76C // reserved 0x76C DLC 
#define OUT_RESERVED_0X76D 0x76D // reserved 0x76D DLC 
#define OUT_RESERVED_0X76E 0x76E // reserved 0x76E DLC 
#define OUT_RESERVED_0X76F 0x76F // reserved 0x76F DLC 
// ======================= CUT HERE FOR SHEETS RESYNC ==========================

#endif