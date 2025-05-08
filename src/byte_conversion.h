#ifndef BYTE_CONVERSION_H
#define BYTE_CONVERSION_H

#include <cstdint>

namespace ByteConversion {

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