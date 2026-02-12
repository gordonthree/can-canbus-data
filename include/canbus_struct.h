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

  struct subModule_t {
    uint32_t   lastSeen;              /**< last seen timestamp for this submodule */
    union {                           /* Union: only takes the space of the largest member */
        float   fltValue;             /**< Floating point data field.  */
        int32_t i32Value;             /**< Signed int data field.  */
        uint8_t u8Value;              /**< Byte data field use for switch state or sensor data.  */
    } data;                           /**< data field */
    uint16_t modType          ;       /**< NOT CAN MSG ID - 11-bit message id that defines module type, used for introduction.  */
    uint16_t pwmDuty         ;        /**< Current PWM duty cycle.  */
    uint16_t pwmFreq         ;        /**< Current PWM frequency.  */
    uint16_t blinkDelay      ;        /**< Blink delay in milliseconds.   */
    uint16_t momPressDur     ;        /**< Momentary press duration in milliseconds.  */
    uint16_t dataMsgId;               /**< Module actually sends data using this message id */
    uint8_t  featureMask[2]  ;        /**< Feature mask to send with introduction.  */
    uint8_t  dataSize        ;        /**< Sensor data size in bytes, more than 4 requires a private message.  */

    // Bit-packing flags and small modes into 2 bytes total
    uint16_t  outMode         : 4;         /**< Current output mode - see defines. */
    uint16_t  strobePat       : 4;         /**< Strobe pattern - see defines.  */
    uint16_t  stateMemory     : 4;         /**< Output state memory - see defines.  */
    uint16_t  useFeatureMask  : 1;         /**< Send feature mask during introduction. */
    uint16_t  privMsg         : 1;         /**< Flag indicating sub module uses privateMsgID as a private channel.  */
    uint16_t  reserved        : 2;         /**< Reserved - fills remaining 16 bits.  */
  };


  struct canNodeInfo {                                 
    uint32_t  nodeID;           /**< Unique 32-bit node id number. */
    uint16_t  nodeTypeMsg;      /**< An 11-bit message id that defines the node type, used for introduction, set to 0 if node not present. */
    uint8_t   featureMask[2];   /**< Two bytes of data to send with node introduction (optional.) */
    uint8_t   subModCnt;        /**< Sub module count for this node. */
    uint8_t   nodeTypeDLC;      /**< Data length code for the node type message. */
    
    struct subModule_t subModules[8];
  };    // end canNodeInfo 

  #endif // end CANBUS_STRUCT_H