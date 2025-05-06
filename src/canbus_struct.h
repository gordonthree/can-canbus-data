#ifndef CANBUS_STRUCT_H
#define CANBUS_STRUCT_H

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

  struct canNodeInfo {
    // flag to indicate this node is present / configured
    bool      present              = false;
    // unique 32-bit node id number
    uint8_t   nodeID[NODE_ID_SIZE] = {0,0,0,0}; 
    // 11-bit message id that defines the node type, used for introduction
    uint16_t  nodeType             = 0; 
    // two bytes of data to send with introduction (optional)
    uint8_t   featureMask[2]       = {0,0};
    // storage for sub modules
    struct    {
                bool     present         = false;       // flag indicating sensor presence
                uint16_t modType         = 0;           // 11-bit message id that defines module type, used for introduction
                uint8_t  featuresMask[2] = {0,0};       // feature mask to send with introduction
                uint16_t txMsgID         = 0;           // module sends data using this message id
                bool     privMsg         = false;       // flag indicating txMsgID is a private channel
                int32_t  i32Value        = 0;           // sensor data signed long int
                float    fltValue        = 0.0;         // sensor data floating point
                uint8_t  dataSize        = 4;           // sensor data size in bytes, more than 4 requires a private message
                uint8_t  u8Value         = 0;           // switch state or sensor data
                uint8_t  swMode          = 0;           // switch mode 0 toggle, 1 momentary, 2 blinking, 3 strobe, 4 pwm, 5 disabled USE DEFINES
                uint8_t  swType          = 0;           // mosfet, relay, sink USE DEFINES
                uint16_t pwmDuty         = 0;           // pwm duty cycle max 16-bit
                uint16_t pwmFreq         = 1000;        // pwm frequency max 16-bit
                uint16_t blinkDelay      = 5000;        // blink delay in ms max 16-bit
                uint16_t momPressDur     = 500;         // momentary press duration in ms max 16-bit
                uint8_t  strobePat       = 0;           // strobe pattern USE DEFINES
                uint8_t  stateMemory     = 1;           // state memory USE DEFINES
                time_t   timestamp       = 0;           // last seen timestamp
              } subModules[8];
    // sub module count
    uint8_t   subModCNT            = 0;
    // last time message received from node 
    uint32_t  lastSeen             = 0;
    // first time message received from node 
    uint32_t  firstSeen            = 0;
  }; 

  #endif // end CANBUS_STRUCT_H