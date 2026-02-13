#ifndef CAN_FLAGS_H
#define CAN_FLAGS_H

#include <Arduino.h>

/** * Use extern to prevent multiple definition errors.
 * These are now declarations, not definitions.
 */
extern uint8_t FLAG_SEND_INTRODUCTION;
extern uint8_t FLAG_BEGIN_NORMAL_OPER;
extern uint8_t FLAG_HALT_NORMAL_OPER;
extern uint8_t FLAG_SEND_HEALTHCHECK;
extern uint8_t FLAG_SEND_NODECHECK;
extern uint8_t FLAG_PRINT_TIMESTAMP;

#endif