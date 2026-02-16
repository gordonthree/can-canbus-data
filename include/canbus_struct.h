#ifndef CANBUS_STRUCT_H
#define CANBUS_STRUCT_H

#ifndef CANBUS_DEFS_H
#include "canbus_defs.h"
#endif

#ifndef CANBUS_FLAGS_H
#include "canbus_flags.h"
#endif

#include <stdint.h>

/**
 * @brief 64-bit Union for the CAN data payload.
 * Total size: 8 bytes.
 */
typedef union {
    uint64_t raw;
    struct __attribute__((packed)) {
        uint32_t nodeID;      /**< D0-D3 */
        uint8_t  data_d4;     /**< D4 */
        uint8_t  data_d5;     /**< D5 */
        uint8_t  data_d6;     /**< D6 */
        uint8_t  data_d7;     /**< D7 */
    } fields; /**< 64-bit union */
} CANMessagePayload;

/**
 * @brief Complete CAN Message structure for RTOS Queues/Pools.
 * This wraps the ID and the Payload together.
 */
typedef struct {
    CANMessagePayload payload; /**< The 8-byte data block */
    uint32_t canID;            /**< The CAN Arbitration ID */
    uint8_t  DLC;              /**< Data Length Code */
  } CAN_Msg_t;
  

/* output switches */
struct outputSwitch {  
    uint32_t lastSeen;               /* last time seen */
    uint16_t pwmDuty;                /* pwm duty cycle */
    uint16_t pwmFreq;                /* pwm frequency */
    uint16_t blinkDelay;             /* blink delay in ms */
    uint16_t momPressDur;            /* momentary press duration in ms */
    uint8_t  swState;                /* switch state on, off, momentary */
    uint8_t  swMode;                 /* switch mode 0 toggle, 1 momentary, 2 blinking, 3 strobe, 4 pwm, 5 disabled */
    uint8_t  swType;                 /* mosfet, relay, sink */
    uint8_t  featuresMask[2];        /* feature mask */
    uint8_t  strobePat;              /* strobe pattern */
    uint8_t  stateMemory;            /* state memory */
  };

  /* various sensors */
  struct outputSensor {
    float    fltValue;               /* floating point */
    uint32_t lastUpdate;             /* timestamp */
    int32_t  i32Value;               /* signed long int */
    uint16_t sensorType;             /* sensor type */
    uint16_t sensorMsg;              /* send our data using this message id */
    uint8_t  featuresMask[2];        /* feature mask */
    uint8_t  dataSize;               /* how many bytes is the data, more than 4 requires a private message */
    bool     present;                /* flag indicating sensor presence */
    bool     privMsg;                /* set to true when controller assigns us a private msg channel */
  };
  
  /* IMU sensor data */
/*  struct imuDataType {
    float xaccel = 0.0;    
    float yaccel = 0.0;
    float zaccel = 0.0;
    float xgyro  = 0.0;
    float ygyro  = 0.0;
    float zgyro  = 0.0;
    float temperature = 0.0;
    uint32_t timestamp = 0;
  };
  */
 
  struct remoteNode {
    uint32_t  lastSeen;       /**< last time message received from node */
    uint32_t  firstSeen;      /**< first time message received from node */
    uint32_t  nodeID;         /**< 32-bit node id number */
    uint16_t  nodeType;       /**< 11-bit can bus message id and node type */
    uint8_t   subModuleCount; /**< count of sub modules associated with this node */
    uint8_t   featureMask[2]; /**< node feature mask storage */
  };

  /** structure to define a sub module */
  struct __attribute__((packed)) subModule_t {
    /* Configuration Personalities */
    union {
        /** Addressable LED Strips */
        struct {
            uint8_t  outputPin;      /**< Physical pin/bus index */
            uint16_t ledCount;       /**< Number of LEDs in this strip */
            uint8_t  colorOrder;     /**< GRB, RGB, etc. */
        } argbLed;

        /** Digital inputs such as physical switches and buttons */
        struct {
            uint8_t  inputPin;       /**< Physical pin/bus index */
            uint8_t  debounceMs;     /**< Button debounce time 10ms intervals */
            uint8_t  outputRes;      /**< Internal pull-up or pull-down enabled? */
            uint8_t  isInverted;     /**< Active High vs Active Low */
        } digitalInput;

        /** Analog ADC inputs */
        struct {
            uint8_t  inputPin;       /**< Physical pin/bus index */
            uint16_t overSampleCnt;  /**< ADC oversampling count */
            uint8_t  reserved;       /**< Padding - reserved */
        } analogInput;

        /** Digital outputs such as relays and mosfets */
        struct {
            uint8_t  outputPin;      /**< Physical pin/bus index */
            uint8_t  momPressDur;    /**< Momentary press duration in 10ms intervals.  */
            uint8_t  outputMode;     /**< See OUT_MODE defines in canbus_defs.h */
            uint8_t  isInverted;     /**< Active High vs Active Low */
        } digitalOutput;

        /** PWM outputs */
        struct {
            uint8_t  outputPin;      /**< Physical pin/bus index */
            uint16_t pwmFreq;        /**< Current PWM frequency in 100 hz increments.  */
            uint8_t  isInverted;     /**< Active High vs Active Low */
        } pwmOutput;
        
        /** Blinking and strobing outputs */
        struct {
            uint8_t  outputPin;      /**< Physical pin/bus index */
            uint8_t  blinkDelay;     /**< Blink delay in in 100 ms intervals.   */
            uint8_t  strobePat;      /**< Strobe pattern - see defines.  */
            uint8_t  isInverted;     /**< Active High vs Active Low */

        } blinkOutput;

        /** Analog RGB/RGBW strips */
        struct {
            uint8_t  stripIndex;     /**< Strip index index */
            uint8_t  colorIndex;     /**< 0 red 1 green 2 blue, 3 RGB, 4 RGBW or RGBA, 5 RGBCCT see defines */
            uint8_t  pinIndex;       /**< Pin configuration index (hard coded?) */
            uint8_t  reserved;       /**< Padding - reserved */
        } rgbLed;

        /** Analog DAC outputs */
        struct {
            uint8_t  outputPin;      /**< Physical pin/bus index */
            uint8_t  outputMode;     /**< Index for output mode, 0 = one-shot, 1 = cosine  */
            uint16_t reserved;       /**< Padding - reserved */
        } analogOutput;

        uint8_t rawConfig[4];        /**< Generic fallback */
    } config;

    /** Operational Data */
    union {
        float    fltValue;          /**< Floating point data (32-bits) */
        uint32_t u32Value;          /**< 32-bit unsigned int data */
        uint16_t u16Value;          /**< 16-bit unsigned int data */
        uint8_t  u8Value;           /**< 8-bit unsigned int data */
    } data;

    /** per-module configuration data */
    uint16_t modType;               /**< NOT CAN MSG ID - 11-bit message id that defines module type, used for introduction.  */
    uint16_t dataMsgId;             /**< Module actually sends data using this message id */
    uint8_t  dataMsgDLC;            /**< DLC for the data message  */
    uint8_t  saveState;             /**< Save output state on power loss?  */
  };


  struct __attribute__((packed)) nodeInfo_t {                                 
    struct subModule_t subModule[8]; /**< Sub module configurations associated with this node */
    uint32_t  nodeID;                 /**< Unique 32-bit node id number. */
    uint16_t  nodeTypeMsg;            /**< An 11-bit message id that defines the node type, used for introduction, set to 0 if node not present. */
    uint8_t   nodeTypeDLC;            /**< Data length code for the node type message. */
    uint8_t   subModCnt;              /**< Sub module count for this node. */
  };    

  #endif /* end CANBUS_STRUCT_H */