#ifndef __CABUS_ROUTES_H
#define __CABUS_ROUTES_H

#ifndef CANBUS_FLAGS_H
#include "canbus_flags.h"
#include "canbus_defs.h"
#endif

#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint8_t  parameters[8];  // configuration information (8 bytes)
    uint8_t  node_id[4];     // source or target node ID (4 bytes)

    uint16_t source_msg_id;  // source message ID (2 bytes)
    uint16_t target_msg_id;  // target message ID (2 bytes)
    uint8_t  source_msg_dlc; // source message DLC (1 byte)
    uint8_t  target_msg_dlc; // target message DLC (1 byte)
    
    uint8_t  source_sub_idx; // source submodule index (1 byte)
    uint8_t  target_sub_idx; // target submodule index (1 byte)

    uint8_t  event_type;     // event type (1 byte)
    uint8_t  action_type;    // action type (1 byte)

    uint8_t  param_len;      // number of parameter used (1 byte)

    uint8_t  enabled;        // enabled flag (1 byte)
} route_entry_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    uint8_t sub_idx;        // submodule index (0–7)

    uint8_t rate_hz;        // broadcast rate (0 = disabled)
    uint8_t flags;          // bitmask: PRODUCER_FLAG_*

    uint8_t reserved;       // alignment / future use
} producer_cfg_t;
#pragma pack(pop)

#define PRODUCER_FLAG_ENABLED      0x01
#define PRODUCER_FLAG_CHANGE_ONLY  0x02
#define PRODUCER_FLAG_RESERVED1    0x04
#define PRODUCER_FLAG_RESERVED2    0x08


#endif // __CABUS_ROUTES_H