#ifndef CANBUS_STRUCT_H
#define CANBUS_STRUCT_H

#ifndef CANBUS_DEFS_H
#include "canbus_defs.h"
#endif

#ifndef CANBUS_FLAGS_H
#include "canbus_flags.h"
#endif

/* output switches */
struct outputSwitch {  
    uint8_t  swState = 0;          // switch state on, off, momentary
    uint8_t  swMode  = 0;          // switch mode 0 toggle, 1 momentary, 2 blinking, 3 strobe, 4 pwm, 5 disabled
    uint8_t  swType  = 0;          // mosfet, relay, sink
    uint8_t  featuresMask[2];      // feature mask
    uint16_t pwmDuty = 20;         // pwm duty cycle
    uint16_t pwmFreq = 1000;       // pwm frequency
    uint16_t blinkDelay = 5000;    // blink delay in ms
    uint16_t momPressDur = 500;    // momentary press duration in ms
    uint8_t  strobePat = 1;        // strobe pattern
    uint8_t  stateMemory = 1;      // state memory
    time_t   lastSeen = 0;         // last time seen
  };

  /* various sensors */
  struct outputSensor {
    bool     present         = false;       // flag indicating sensor presence
    uint16_t sensorType      = 0;           // sensor type 
    uint16_t sensorMsg       = 0;           // send our data using this message id
    bool     privMsg         = false;       // set to true when controller assigns us a private msg channel
    uint8_t  featuresMask[2] = {0};         // feature mask
    int32_t  i32Value        = 0;           // signed long int
    float    fltValue        = 0.0;         // floating point
    uint8_t  dataSize        = 4;           // how many bytes is the data, more than 4 requires a private message
    time_t   lastUpdate      = 0;           // timestamp
  };
  
  /* IMU sensor data */
  struct imuDataType {
    float xaccel = 0.0;    
    float yaccel = 0.0;
    float zaccel = 0.0;
    float xgyro  = 0.0;
    float ygyro  = 0.0;
    float zgyro  = 0.0;
    float temperature = 0.0;
    uint32_t timestamp = 0;
  };

  /* remote nodes */
  struct remoteNode {
    // 32-bit node id number
    uint8_t   nodeID[NODE_ID_SIZE] = {0,0,0,0}; 
    // 11-bit can bus message id and node type
    uint16_t  nodeType             = 0;
    // node feature mask storaege (optional)
    uint8_t   featureMask[2]       = {0,0};
    // storage for any sub modules
    uint16_t  subModuleList[8]     = {0}; 
    // sub module count for each sub module
    uint8_t   subModCntList[8]     = {0};
    // total sub module count
    uint8_t   moduleCnt            = 0; 
    // last time message received from node 
    uint32_t  lastSeen             = 0;
    // first time message received from node 
    uint32_t  firstSeen            = 0;
  } ; 

/**
  * @brief Structure to store all info about a node and associated modules
  *
  **/
  struct canNodeInfo {                                 
    
    uint16_t  nodeType             = 0;                 /**  An 11-bit message id that defines the node type, used for introduction, set to 0 if node not present. */
    uint8_t   nodeID[NODE_ID_SIZE] = {0,0,0,0};         /**  Unique 32-bit node id number. */
    uint8_t   featureMask[2]       = {0,0};             /**  Two bytes of data to send with node introduction (optional.) */
    uint8_t   subModCnt            = 0;                 /**  Sub module count for this node. */
    time_t    lastSeen             = 0;                 /**  Last time a message was received from this node.  */
    time_t    firstSeen            = 0;                 /**  First time a message was received from this node. */
    
    struct    {                                         /** Storage for sub modules. */
                uint16_t modType         = 0;           /** 11-bit message id that defines module type, used for introduction.  */
                uint8_t  modCount        = 0;           /** Number of modules associated with the current modType. This information might be included in the feature mask. */
                uint8_t  featureMask[2] = {0,0};        /** Feature mask to send with introduction.  */
                bool     sendFeatureMask = false;       /** Send feature mask during introduction. */
                uint16_t txMsgID         = 0;           /** Module sends data using this message id.  */
                bool     privMsg         = false;       /** Flag indicating txMsgID is a private channel.  */
                uint8_t  u8Value         = 0;           /** Byte data field use for switch state or sensor data.  */
                int32_t  i32Value        = 0;           /** Signed int data field.  */
                float    fltValue        = 0.0;         /** Floating point data field.  */
                uint8_t  dataSize        = 4;           /** Sensor data size in bytes, more than 4 requires a private message.  */
                uint8_t  outMode         = 0;           /** Current output mode - see defines. */
                uint16_t pwmDuty         = 0;           /** Current PWM duty cycle.  */
                uint16_t pwmFreq         = 1000;        /** Current PWM frequency.  */
                uint16_t blinkDelay      = 5000;        /** Blink delay in milliseconds.   */
                uint16_t momPressDur     = 500;         /** Momentary press duration in milliseconds.  */
                uint8_t  strobePat       = 0;           /** Strobe pattern - see defines.  */
                uint8_t  stateMemory     = 1;           /** Output state memory - see defines.  */
                time_t   timestamp       = 0;           /** Last seen timestamp for this module.  */
              } subModules[8];  
  };    // end canNodeInfo 

  #endif // end CANBUS_STRUCT_H