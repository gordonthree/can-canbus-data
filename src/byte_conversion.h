#ifndef BYTE_CONVERSION_H
#define BYTE_CONVERSION_H

#include <cstdint>

namespace ByteConversion {

/**
 * @brief Concatenate arrays to build a data packet for sending with a CAN message.
 *        All parameters are required.
 * 
 * @param arr1 uint8_t* Typically containing the 4-byte node id we are sending from or to.
 * @param n1 uint8_t The size of the elements contained in arr1. 
 * @usage example: uint8_t n1 = sizeof(arr1) / sizeof(arr1[0]);
 * @param arr2 uint8_t* Typically containing four more bytes to send along with the node id.
 * @param n2 uint8_t The size of the elements contained in arr2.
 * 
 * @returns uint8_t* Array containing the merged contents of arr1 and arr2.
 * 
 */
uint8_t* messageBuilder(uint8_t arr1[], uint8_t n1, uint8_t arr2[], uint8_t n2) {
  uint8_t *buf = (u_int8_t*)malloc(sizeof(uint8_t) * n1 * n2);

  memcpy(buf, arr1, n1 * sizeof(uint8_t)); // copy the first array to the buffer

  memcpy(buf + n1, arr2, n2 * sizeof(uint8_t)); // copy the second array to the buffer

  return buf; // that's all folks return complete array
}

/**
 * @brief Convert a 4-byte array into a 32-bit unsigned integer.
 *
 * This function takes a pointer to an array of 4 bytes and combines them
 * into a single 32-bit unsigned integer, assuming network byte order
 * (big-endian format).
 *
 * @param dataBytes Pointer to the array of 4 bytes.
 * @return uint32_t 32-bit unsigned integer representation of the byte array.
 *                  Returns 0 if the input pointer is null.
 */
inline uint32_t unchunk32(const uint8_t* dataBytes) {
  if (dataBytes == nullptr) {
    return 0;
  }
  return (static_cast<uint32_t>(dataBytes[0]) << 24) |
         (static_cast<uint32_t>(dataBytes[1]) << 16) |
         (static_cast<uint32_t>(dataBytes[2]) << 8)  |
         (static_cast<uint32_t>(dataBytes[3]));
}

/**
 * @brief Convert a 2-byte array into a 16-bit unsigned integer.
 *
 * This function takes a pointer to an array of 2 bytes and combines them
 * into a single 16-bit unsigned integer, assuming network byte order
 * (big-endian format).
 *
 * @param dataBytes Pointer to the array of 2 bytes.
 * @return uint16_t 16-bit unsigned integer representation of the byte array.
 *                  Returns 0 if the input pointer is null.
 */
inline uint16_t unchunk16(const uint8_t* dataBytes) {
  if (dataBytes == nullptr) {
    return 0;
  }
  return (static_cast<uint16_t>(dataBytes[0]) << 8) |
         (static_cast<uint16_t>(dataBytes[1]));
}

/**
 * @brief Convert a 32-bit number into a 4-byte array.
 *
 * This function takes a 32-bit unsigned integer and breaks it into a 4-byte
 * array, with the bytes in network byte order (big-endian format).
 *
 * @param inVal The 32-bit unsigned integer to convert.
 * @param outArray Pointer to a 4-byte array where the result will be stored.
 */
inline void chunk32(uint32_t inVal, uint8_t* outArray) {
  if (outArray != nullptr) {
    outArray[0] = (inVal >> 24) & 0xFF;
    outArray[1] = (inVal >> 16) & 0xFF;
    outArray[2] = (inVal >> 8) & 0xFF;
    outArray[3] = inVal & 0xFF;
  }
}

/**
 * @brief Convert a 16-bit number into a two-byte array.
 *
 * This function takes a 16-bit unsigned integer and breaks it into a 2-byte
 * array, with the bytes in network byte order (big-endian format).
 *
 * @param inVal The 16-bit unsigned integer to convert.
 * @param outArray Pointer to a 2-byte array where the result will be stored.
 */
inline void chunk16(uint16_t inVal, uint8_t* outArray) {
  if (outArray != nullptr) {
    outArray[0] = (inVal >> 8) & 0xFF;
    outArray[1] = inVal & 0xFF;
  }
}

} // namespace ByteConversion

#endif // BYTE_CONVERSION_H