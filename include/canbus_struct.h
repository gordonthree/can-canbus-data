#pragma once

#include "canbus_defs.h"
#include "canbus_flags.h"

#include <stdint.h>

/**
 * @brief 64-bit Union for the CAN data payload.
 * Total size: 8 bytes.
 */
// typedef union {
//     uint64_t raw;
//     struct __attribute__((packed)) {
//         uint32_t nodeID;      /**< D0-D3 */
//         uint8_t  data_d4;     /**< D4 */
//         uint8_t  data_d5;     /**< D5 */
//         uint8_t  data_d6;     /**< D6 */
//         uint8_t  data_d7;     /**< D7 */
//     } fields; /**< 64-bit union */
// } CANMessagePayload;

/**
 * @brief Complete CAN Message structure for RTOS Queues/Pools.
 * This wraps the ID and the Payload together.
 */
// typedef struct {
//     CANMessagePayload payload; /**< The 8-byte data block */
//     uint32_t canID;            /**< The CAN Arbitration ID */
//     uint8_t  DLC;              /**< Data Length Code */
//   } node_CAN_Msg_t;
  

/* output switches */
// struct outputSwitch {  
//     uint32_t lastSeen;               /* last time seen */
//     uint16_t pwmDuty;                /* pwm duty cycle */
//     uint16_t pwmFreq;                /* pwm frequency */
//     uint16_t blinkDelay;             /* blink delay in ms */
//     uint16_t momPressDur;            /* momentary press duration in ms */
//     uint8_t  swState;                /* switch state on, off, momentary */
//     uint8_t  swMode;                 /* switch mode 0 toggle, 1 momentary, 2 blinking, 3 strobe, 4 pwm, 5 disabled */
//     uint8_t  swType;                 /* mosfet, relay, sink */
//     uint8_t  featuresMask[2];        /* feature mask */
//     uint8_t  strobePat;              /* strobe pattern */
//     uint8_t  stateMemory;            /* state memory */
//   };

  /* various sensors */
  // struct outputSensor {
  //   float    fltValue;               /* floating point */
  //   uint32_t lastUpdate;             /* timestamp */
  //   int32_t  i32Value;               /* signed long int */
  //   uint16_t sensorType;             /* sensor type */
  //   uint16_t sensorMsg;              /* send our data using this message id */
  //   uint8_t  featuresMask[2];        /* feature mask */
  //   uint8_t  dataSize;               /* how many bytes is the data, more than 4 requires a private message */
  //   bool     present;                /* flag indicating sensor presence */
  //   bool     privMsg;                /* set to true when controller assigns us a private msg channel */
  // };
  
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
 
  // struct remoteNode {
  //   uint32_t  lastSeen;       /**< last time message received from node */
  //   uint32_t  firstSeen;      /**< first time message received from node */
  //   uint32_t  nodeID;         /**< 32-bit node id number */
  //   uint16_t  nodeType;       /**< 11-bit can bus message id and node type */
  //   uint8_t   subModuleCount; /**< count of sub modules associated with this node */
  //   uint8_t   featureMask[2]; /**< node feature mask storage */
  // };



  struct __attribute__((packed)) colorPickerList_t {
    uint32_t  remoteNodeID;           /**< 32-bit remote node id number */
    uint32_t  lastSeen;               /**< timestamp of the last time a message was received from node */
    uint16_t  dataMsgId;              /**< Msg ID used to communicate with remote node */
    uint8_t   dataMsgDLC;             /**< Data length code for the data message. */
    uint8_t   ledIndex;               /**< submodule index (0-7) */
    uint8_t   colorIndex;             /**< color index on the custom 32 color palette */
  }; /**< Storage structure for nodes with a color picker, used for remote control */

//   typedef struct __attribute__((packed)) {
//     uint8_t raw[4];     // Up to 32 bits of runtime data
//     uint8_t dlc;        // How many bytes are valid
// } submoduleRuntime_t;
