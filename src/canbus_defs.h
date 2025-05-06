#ifndef CANBUS_DEFS_H
#define CANBUS_DEFS_H
// time stuff
#define NTP_SERVER             "us.pool.ntp.org"
#define UTC_OFFSET             0
#define UTC_OFFSET_DST         0

// sizes for various byte-arrays
#define FEATURE_MASK_SIZE      2           // size of feature mask in bytes
#define NODE_ID_SIZE           4           // node ID length in bytes
#define CAN_MAX_DLC            8           // maximum number of bytes in a legal CAN message

// Define clear return values for various error conditions
#define NODE_NOT_FOUND        -1
#define NODE_LIST_FULL        -5
#define NODE_ID_INVALID       -2
#define NODE_ALREADY_EXISTS   -6
#define MODULE_NOT_FOUND      -10
#define MODULE_ALREADY_EXISTS -3
#define MODULE_LIST_FULL      -4

#define MAX_SENSOR_CNT         8           // maximum number of sensors per node
#define SENSOR_DATA_SIZE       8           // maximum bytes for sensor data 
#define SENSOR_MSG_SIZE        2           // enough room for an 11-bit message ID

#define ACCEPT_CODE            0x13F       // 0001 0011 1111 
#define ACCEPT_MASK            0xFFE00000  // 1111 1111 1110 0000 0000 0000 0000 0000
                 
#define NODE_MOD_MASK          0x780       // 0x700 to 0x77F are sub modules, 0x780 and above are remote nodes
#define ADDR_FIRST_NODE        0x780       // first valiud address for remote nodes
#define ADDR_FIRST_MODULE      0x700       // first valid address for sub modules
           
#define MSG_CTRL_SWITCHES      0x110       // switch box controls
#define MASK_CTRL_SWITCHES     0x180       // address range 0x100:0x17F
#define MSG_CTRL_IFACE         0x200       // interface node controls
#define MASK_CTRL_IFACE        0x280       // address range 0x100:0x17F
#define MSG_REQ_INTRO          0x400       // messages related to introductions
#define MASK_REQ_INTRO         0x480       // address range 0x400:0x47F
#define MSG_NODE_DATA          0x500       // nodes send data back to the controller
#define MASK_NODE_DATA         0x580       // address range 0x500:0x57F


#endif // end CANBUS_DEFS_H