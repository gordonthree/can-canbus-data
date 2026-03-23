#pragma once
/* === Project Defs === */

/* random project defs */
#define DEBUG_MSG_SIZE         (256)       /**< Size of debug message buffer */
#define DEBUG_QUEUE_LEN        (16)        /**< Max number of debug message buffers in queue */
#define CAN_TX_QUEUE_LEN       (16)        /**< Max number of CAN messages in the TX queue */
#define CAN_RX_QUEUE_LEN       (16)        /**< Max number of CAN messages in the RX queue */
#define CAN_MSG_POOL_LEN       (16)        /**< Max number of CAN messages in the pool */
#define PWM_SCALING_FACTOR     (100U)
#define MOM_SW_SCALING_FACTOR  (10U)
#define BLINK_SCALING_FACTOR   (1U)
#define LEDC_MAX_TIMERS        (4U)        /* there are four low speed timers, allow one LED per timer */
#define MAX_PIXEL_COUNT        (255U)      /* Maximum LEDs supported per submodule */
#define MAX_ARGB_STRIPS        (1U)        /* Maximum ARGB strips supported per node */
#define CAN_ERROR_AGE_MS       (30000U)    /* forget errors after 30 seconds */
#define BYTE_SHIFT3            (24U)       /**< shift 3 bytes */
#define BYTE_SHIFT2            (16U)       /**< shift 2 bytes */
#define BYTE_SHIFT             (8U)        /**< shift single byte */
#define BYTE_MASK              (0xFFU)     /**< mask for byte access */

/* module limits */
#define MAX_ARGB_SUBMODULES    (4U)        /**< Hardware limit for ARGB strips */
#define MAX_SUB_MODULES        (8U)        /**< Memory limit for submodules */
#define MAX_REMOTE_NODES       (8U)        /**< Memory limit for remote nodes */

/* CAN constants */
#define CAN_MAX_DLC            (8U)
#define CAN_NODE_ID_LEN        (4U)
#define CAN_DATAMSG_MIN_DLC    (6U)         /**< Minimum data message length */

// time stuff
#define NTP_SERVER             ("us.pool.ntp.org")
#define UTC_OFFSET             (0)
#define UTC_OFFSET_DST         (0)

/* sizes for various byte-arrays */
#define NODE_ID_SIZE           (4U)        /* node ID length in bytes */
#define NODE_MOD_MAX_cnt       (8U)        /* maximum number of modules per node */
#define NODE_MOD_MSG_SIZE      (2U)        /* enough room for an 11-bit message ID */
#define FEATURE_MASK_SIZE      (2U)        /* size of feature mask in bytes */

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
#define MODULE_DISPLAY        (0x700)       /** display modules 0x700:0x70F */
#define MODULE_INPUTS         (0x710)       /** physical input modules 0x710:0x71F */
#define MODULE_SENSORS1       (0x720)       /** sensor modules group 2 0x720:0x72F */
#define MODULE_SENSORS2       (0x730)       /** sensor modules group 2 0x730:0x73F */
#define MODULE_OUTPUTS        (0x740)       /** output switches range 0x740:0x74F */

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

/**
 * @brief Sub-module configuration constants
 */
#define SUBMOD_FLAG_NONE         (0U)        /**< No flags */
#define SUBMOD_FLAG_SAVE_STATE   (1U << 0)   /**< Save output state to non-volatile memory */
#define SUBMOD_FLAG_DIRTY        (1U << 1)   /**< Sub-module state has changed */
#define SUBMOD_FLAG_DISABLED     (1U << 2)   /**< Sub-module is disabled */
#define SUBMOD_FLAG_READ_ONLY    (1U << 3)   /**< Sub-module is read-only */
#define SUBMOD_FLAG_VIRTUAL      (1U << 4)   /**< Sub-module is virtual */
#define SUBMOD_FLAG_DISPLAY      (1U << 5)   /**< Sub-module is a display or ui element */
#define SUBMOD_FLAG_INPUT        (1U << 6)   /**< Sub-module is an input */
#define SUBMOD_FLAG_OUTPUT       (1U << 7)   /**< Sub-module is an output */

/* Input mode flag masks */
#define INPUT_FLAG_MASK_PULL     (0x03U)   /**< Pull-up or pull-down 0b0000 0011 */
#define INPUT_FLAG_MASK_INV      (0x04U)   /**< Invert logic 0b0000 0100 */
#define INPUT_FLAG_MASK_MODE     (0x38U)   /**< Input mode 0b0011 1000 */
#define INPUT_FLAG_MASK_RESERVED (0xC0U)   /**< Reserved 0b1100 0000 */

/* Input flag getters */
#define INPUT_FLAG_GET_PULL(f)   ((f) & INPUT_FLAG_MASK_PULL)                               /**< Get the input resistor mode */
#define INPUT_FLAG_GET_INV(f)    (((f) & INPUT_FLAG_MASK_INV)  >> 2)                         /**< Get the logic invert state */
#define INPUT_FLAG_GET_MODE(f)   (((f) & INPUT_FLAG_MASK_MODE) >> 3)                        /**< Get the input switch type mode */

/* Input flag setters */
#define INPUT_FLAG_SET_PULL(f,v)  (((f) & ~INPUT_FLAG_MASK_PULL) | ((v) & 0x03))             /**< Set the input resistor mode */
#define INPUT_FLAG_SET_INV(f,v)   (((f) & ~INPUT_FLAG_MASK_INV)  | (((v) & 0x01) << 2))      /**< Set the logic invert state */
#define INPUT_FLAG_SET_MODE(f,v)  (((f) & ~INPUT_FLAG_MASK_MODE) | (((v) & 0x07) << 3))      /**< Set the input switch type mode */

/* Input resistor modes */
#define INPUT_FLAG_PULL_FLOAT      (0x00U)  /**< 00: floating */
#define INPUT_FLAG_PULL_UP         (0x01U)  /**< 01: pull-up */
#define INPUT_FLAG_PULL_DOWN       (0x02U)  /**< 10: pull-down */

/* Input logic invert states */
#define INPUT_FLAG_INVERT           (0x04U)  /**< 1 << 2: invert logic */

/* Input switch type modes */
#define INPUT_FLAG_MODE_NORMAL      (0x00U)  /**< 000 << 3 */
#define INPUT_FLAG_MODE_MOMENTARY   (0x08U)  /**< 001 << 3 */
#define INPUT_FLAG_MODE_TOGGLE      (0x10U)  /**< 010 << 3 */
#define INPUT_FLAG_MODE_LATCH       (0x18U)  /**< 011 << 3 */

/* input flags - reserved */
#define INPUT_FLAG_RESERVED_6       (0x40U)  /**< bit 6 */
#define INPUT_FLAG_RESERVED_7       (0x80U)  /**< bit 7 */

/* === Producer Constants === */
#define PRODUCER_FLAG_NONE         (0x00U)   /**< Producer publishing disabled */
#define PRODUCER_FLAG_ENABLED      (0x01U)   /**< Producer publishing enabled */
#define PRODUCER_FLAG_CHANGE_ONLY  (0x02U)   /**< Producer publish on change only */
#define PRODUCER_FLAG_RESERVED1    (0x04U)
#define PRODUCER_FLAG_RESERVED2    (0x08U)

#define DEFAULT_PUBLISH_RATE       (1000U)    /**< Default publish period in ms (1 Hz) */
#define PRODUCER_PUBLISH_DISABLED  (0U)       /**< Publish period disabled */

#define PRODUCER_RATEMS_1HZ        (1000U)    /**< Publish period 1000ms 1 Hz */
#define PRODUCER_RATEMS_10HZ       (100U)     /**< Publish period 100ms 10 Hz */
#define PRODUCER_RATEMS_100HZ      (10U)      /**< Publish period 10ms 100 Hz */

/* === GPIO ISR Constants === */

/* GPIO state values */
#define GPIO_LEVEL_LOW              (0U)      /**< Low level output */
#define GPIO_LEVEL_HIGH             (1U)      /**< High level output */

/* Momentary mode output values */
#define MOMENTARY_RELEASE_VALUE     (10u)     /**< Flag to indicate momentary button release state */
#define MOMENTARY_ACTIVE_VALUE      (11u)     /**< Flag to indicate momentary button active state */

/* Normal mode */
#define GPIO_LONG_PRESS             (2U)       /**< Long press flag */
#define GPIO_DOUBLE_CLICK           (3U)       /**< Double click flag */
#define GPIO_SINGLE_CLICK           (1U)       /**< Single click flag */
/**
 * @brief Producer behavioral type.
 */
typedef enum
{
    PRODUCER_KIND_NONE     = 0,  /**< No producer / disabled */
    PRODUCER_KIND_DIGITAL,       /**< Digital producer (0/1) */
    PRODUCER_KIND_ANALOG,        /**< Analog producer (0–4095, etc.) */
    PRODUCER_KIND_COUNTER,       /**< Counter / incrementing producer */
    PRODUCER_KIND_TIMER,         /**< Timer / decrementing producer */
    PRODUCER_KIND_PERIODIC,      /**< Periodic value producer */
    PRODUCER_KIND_CUSTOM         /**< User-defined or extended behavior */

} producer_kind_t;

/* 13-bit LEDC duty cycles */
#define LEDC_13BIT_0PCT           (0)        /**< 0% is 0 */
#define LEDC_13BIT_10PCT          (819)      /**< 10% of 2^13 */
#define LEDC_13BIT_25PCT          (2048)     /**< 25% of 2^13 */
#define LEDC_13BIT_50PCT          (4096)     /**< 50% of 2^13 */
#define LEDC_13BIT_100PCT         (8192)     /**< 100% of 2^13 */

/* === ENUMERATIONS === */


/* input resistor mode (pull-mode) */
typedef enum {
    INPUT_PULL_FLOAT   = 0,  /**< 00: floating */
    INPUT_PULL_UP      = 1,  /**< 01: pull-up */
    INPUT_PULL_DOWN    = 2,  /**< 10: pull-down */
    INPUT_PULL_RSVD    = 3   /**< 11: reserved */
} inputPull_t;

/* logic invert states */
typedef enum {
    INPUT_INV_OFF = 0,  /**< normal logic */
    INPUT_INV_ON  = 1   /**< inverted logic */
} inputInvert_t;

/* input switch type */
typedef enum {
    INPUT_MODE_NORMAL    = 0,  /**< click / long press / double click */
    INPUT_MODE_MOMENTARY ,     /**< hold = active, release = inactive */
    INPUT_MODE_TOGGLE    ,     /**< press toggles state */
    INPUT_MODE_LATCH     ,     /**< press sets, second press clears */
    INPUT_MODE_RESERVED4 ,     /**< reserved input mode */
    INPUT_MODE_RESERVED5 ,     /**< reserved input mode */
    INPUT_MODE_RESERVED6 ,     /**< reserved input mode */
    INPUT_MODE_RESERVED7       /**< reserved input mode */
} inputModeType_t;


/* analog output mode enum */
typedef enum {
    DAC_MODE_ONESHOT = 0,
    DAC_MODE_CONTINUOUS
} analogMode_t;

/* analog sample count enum */
typedef enum {
    OVERSAMPLE_ESP32_MINIMUM = 0, 
    OVERSAMPLE_ESP32_LOW,
    OVERSAMPLE_ESP32_MEDIUM,
    OVERSAMPLE_ESP32_HIGH,
    OVERSAMPLE_ESP32_MAXIMUM
} analogOversampleCnt_t;

/**
 * @enum gpioInputRes_t
 * @brief GPIO Resistor configuration
 */
typedef enum {
    INPUT_RES_PULLUP,   /**< Internal pull-up resistor enabled */
    INPUT_RES_PULLDOWN, /**< Internal pull-down resistor enabled */
    INPUT_RES_FLOATING  /**< No internal resistor */
} gpioInputRes_t;

/**
 * @enum analogStrip_t
 * @brief LED strip color order constants
 *
 * 0: red
 * 1: green
 * 2: blue
 * 3: white
 * 4: RGB
 * 5: RGBW
 * 6: RGBA
 * 7: RGBCCT
 */
typedef enum {
    ANALOG_STRIP_RED = 0,
    ANALOG_STRIP_GREEN,
    ANALOG_STRIP_BLUE,
    ANALOG_STRIP_WHITE,
    ANALOG_STRIP_RGB,
    ANALOG_STRIP_RGBW,
    ANALOG_STRIP_RGBA,
    ANALOG_STRIP_RGBCCT
} analogStrip_t;

typedef enum {
    ARGB_COLOR_ORDER_RGB = 0,
    ARGB_COLOR_ORDER_BGR,
    ARGB_COLOR_ORDER_RGBA,
    ARGB_COLOR_ORDER_BGRA,
    ARGB_COLOR_ORDER_RGBW,
    ARGB_COLOR_ORDER_BGRW
} argbColorOrder_t;

/**
 * @enum displayMode_t
 * @brief Display modes for the LCD / OLED display
 */
typedef enum {
    DISPLAY_MODE_OFF = 0, /**< Turn off the display */
    DISPLAY_MODE_ON,      /**< Turn on the display */
    DISPLAY_MODE_CLEAR,   /**< Clear the display */
    DISPLAY_MODE_FLASH    /**< Flash the display */
} displayMode_t;

/**
 * @enum outputState_t
 * @brief Enum for output states
 */
typedef enum {
    OUT_STATE_OFF       = 0x00, /**< output is off */
    OUT_STATE_ON        = 0x01, /**< output is on */
    OUT_STATE_TOGGLE    = 0x02, /**< output is toggle */
    OUT_STATE_MOMENTARY = 0x03, /**< output is momentary */
    OUT_STATE_FOLLOW    = 0x04, /**< output following an external event */
    OUT_STATE_STROBE    = 0x05, /**< output is strobing */
    OUT_STATE_PWM       = 0x06, /**< output is pwm */
    OUT_STATE_BLINK     = 0x07, /**< output is blinking, pwm with slower timing */
    OUT_STATE_DISABLED  = 0x80, /**< output is disabled */
    OUT_STATE_INVALID   = 0xFF, /**< invalid output state */
} outputState_t;

/**
 * @enum outputMode_t
 * @brief Enum for output modes
 */
typedef enum {
    OUT_MODE_ALWAYS_OFF = 0x00, /**< output is disabled and always-off */
    OUT_MODE_ALWAYS_ON  = 0x01, /**< output is disabled and always-on */
    OUT_MODE_TOGGLE     = 0x02, /**< output acts like a standard on/off switch */
    OUT_MODE_MOMENTARY  = 0x03, /**< output acts like a momentary push button switch */
    OUT_MODE_FOLLOW     = 0x04, /**< output follows an external event */
    OUT_MODE_STROBE     = 0x05, /**< output strobes various timing patterns */
    OUT_MODE_PWM        = 0x06, /**< output uses pulse width modulation */
    OUT_MODE_BLINK      = 0x07, /**< output blinks, pwm with slower timing */
    OUT_MODE_INVALID    = 0xFF, /**< invalid output mode */
} outputMode_t;

/**
 * @enum outSaveState_t
 * @brief Enum to control if the output state should be saved to memory.
 */
typedef enum {
    OUT_SAVE_STATE_OFF = 0x00, /**< Disable saving the output state to memory. */
    OUT_SAVE_STATE_ON  = 0x01  /**< Enable saving the output state to memory. */
} outSaveState_t;

/**
 * @brief Enum for strobe patterns
 * @enum strobePattern_t
 */
typedef enum strobePattern_t {
    STROBE_PATTERN_1 = 0x01, /**< repeating three flashes and a pause */
    STROBE_PATTERN_2 = 0x02, /**< repeating 3x flash pause 5x flash pause */
    STROBE_PATTERN_3 = 0x03, /**< tbd */
    STROBE_PATTERN_4 = 0x04, /**< tbd */
    STROBE_PATTERN_5 = 0x05, /**< tbd */
} strobePattern_t;

/**
 * @brief Enum for individual data bytes in a CAN message
 * @enum msg_data_t
 */
typedef enum {
    MSG_DATA_0 = 0,
    MSG_DATA_1,
    MSG_DATA_2,
    MSG_DATA_3,
    MSG_DATA_4,
    MSG_DATA_5,
    MSG_DATA_6,
    MSG_DATA_7
} msg_data_t;
