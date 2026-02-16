#ifndef CANBUS_DEFS_H
#define CANBUS_DEFS_H

#define DEBUG_MSG_SIZE         (256)       /**< Size of debug message buffer */
#define DEBUG_QUEUE_LEN        (16)        /**< Max number of debug message buffers in queue */
#define CAN_TX_QUEUE_LEN       (16)        /**< Max number of CAN messages in the TX queue */
#define CAN_RX_QUEUE_LEN       (16)        /**< Max number of CAN messages in the RX queue */
#define CAN_MSG_POOL_LEN       (16)        /**< Max number of CAN messages in the pool */

/* digital IO stuff */
#define INPUT_RES_PULLUP       (0)
#define INPUT_RES_PULLDOWN     (1)
#define INPUT_RES_FLOATING     (2)

/** Analog LED strip color order constants */
/** 0 red 1 green 2 blue 3 white, 4 RGB, 5 RGBW, 6 RGBA, 7 RGBCCT */
#define ANALOG_STRIP_RED       (0)
#define ANALOG_STRIP_GREEN     (1)
#define ANALOG_STRIP_BLUE      (2)
#define ANALOG_STRIP_WHITE     (3)
#define ANALOG_STRIP_RGB       (4)
#define ANALOG_STRIP_RGBW      (5)
#define ANALOG_STRIP_RGBA      (6)
#define ANALOG_STRIP_RGBCCT    (7)

// time stuff
#define NTP_SERVER             ("us.pool.ntp.org")
#define UTC_OFFSET             (0)
#define UTC_OFFSET_DST         (0)

/* sizes for various byte-arrays */
#define NODE_ID_SIZE           (4U)        /* node ID length in bytes */
#define NODE_MOD_MAX_cnt       (8U)        /* maximum number of modules per node */
#define NODE_MOD_MSG_SIZE      (2U)        /* enough room for an 11-bit message ID */
#define FEATURE_MASK_SIZE      (2U)        /* size of feature mask in bytes */
#define CAN_MAX_DLC            (8U)        /* maximum number of bytes in a legal CAN message */

/**
 * Define clear return values for various error conditions
 */
#define NODE_NOT_FOUND        (-1)
#define NODE_LIST_FULL        (-5)
#define NODE_ID_INVALID       (-2)
#define NODE_ALREADY_EXISTS   (-6)
#define MODULE_NOT_FOUND      (-10)
#define MODULE_ALREADY_EXISTS (-3)
#define MODULE_LIST_FULL      (-4)
#define MODULE_DISPLAY         (0x700)       /** display modules 0x700:0x70F */
#define MODULE_INPUTS          (0x710)       /** physical input modules 0x710:0x71F */
#define MODULE_SENSORS1        (0x720)       /** sensor modules group 2 0x720:0x72F */
#define MODULE_SENSORS2        (0x730)       /** sensor modules group 2 0x730:0x73F */
#define MODULE_OUTPUTS         (0x740)       /** output switches range 0x740:0x74F */

/**
 * Define the size of data fields in messages
 */
#define DATA_SIZE_8BITS        (1)           /** one byte for 8 bits */
#define DATA_SIZE_12BITS       (2)           /** two bytes for 12 bits */
#define DATA_SIZE_16BITS       (2)           /** two bytes for 16 bits */
#define DATA_SIZE_24BITS       (3)           /** three bytes for 24 bits */
#define DATA_SIZE_32BITS       (4)           /** four bytes for 32 bit values */
#define DATA_SIZE_64BITS       (8)           /** eight bytes for float as string and other big data types */
#define MASK_BITS_11_TO_8      (0x780)       /** 0111 1000 0000 */
#define ACCEPT_MASK            (0xFFE00000)  // 1111 1111 1110 0000 0000 0000 0000 0000
                 
#define NODE_MOD_MASK          (0x780)       /** 0x700 to 0x77F are sub modules, 0x780 and above are remote nodes */
#define ADDR_FIRST_NODE        (0x780)       /** first valid address for remote nodes */
#define ADDR_FIRST_MODULE      (0x700)       /** first valid address for sub modules */
#define ADDR_LAST_MODULE       (0x7FF)       /** last valid address for sub modules */
           
#define MSG_CTRL_SWITCHES      (0x110)       /** switch box controls */
#define MASK_CTRL_SWITCHES     (0x180)       /** address range 0x100:0x17F */
#define MSG_CTRL_IFACE         (0x200)       /** interface node controls */
#define MASK_CTRL_IFACE        (0x280)       /** address range 0x100:0x17F */
#define MSG_REQ_INTRO          (0x400)       /** messages related to introductions */
#define MASK_REQ_INTRO         (0x480)       /** address range 0x400:0x47F */
#define MSG_NODE_DATA          (0x500)       /** nodes send data back to the controller */
#define MASK_NODE_DATA         (0x580)       /** address range 0x500:0x57F */

#define OUT_STATE_DISABLED     (0x00)        /** output is disabled */
#define OUT_STATE_OFF          (0x01)        /** output is off */
#define OUT_STATE_ON           (0x02)        /** output is on */
#define OUT_STATE_MOMENTARY    (0x03)        /** output is momentary */
#define OUT_STATE_BLINKING     (0x04)        /** output is blinking */
#define OUT_STATE_STROBE       (0x05)        /** output is strobing */
#define OUT_STATE_PWM          (0x06)        /** output is pwm */
#define OUT_STATE_INVALID      (0xFF)        /** invalid output state */

#define OUT_MODE_ALWAYS_OFF    (0x00)        /** output is disabled and always-off */
#define OUT_MODE_ALWAYS_ON     (0x01)        /** output is disabled and always-on */
#define OUT_MODE_TOGGLE        (0x02)        /** output acts like a standard on/off switch */
#define OUT_MODE_MOMENTARY     (0x03)        /** output acts like a momentary push button switch */
#define OUT_MODE_BLINKING      (0x04)        /** output blinks on and off like a turn signal */
#define OUT_MODE_STROBE        (0x05)        /** output strobes various timing patterns */
#define OUT_MODE_PWM           (0x06)        /** output uses pulse width modulation */
#define OUT_MODE_INVALID       (0xFF)        /** invalid output mode */

#define OUT_SAVE_STATE_OFF     (0x01)        /** disable save output state (memory) */
#define OUT_SAVE_STATE_ON      (0x01)        /** enable save output state (memory) */

#define STROBE_PATTERN_1       (0x01)        /** repeating three flashes and a pause */
#define STROBE_PATTERN_2       (0x02)        /** repeating 3x flash pause 5x flash pause */
#define STROBE_PATTERN_3       (0x03)        /** tbd */
#define STROBE_PATTERN_4       (0x04)        /** tbd */
#define STROBE_PATTERN_5       (0x05)        /** tbd */



#endif /** end CANBUS_DEFS_H  */
