#ifndef BYTE_CONVERSION_H
#define BYTE_CONVERSION_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Concatenates two arrays into a destination buffer.
 * * NOTE: Removed malloc to prevent heap fragmentation in FreeRTOS.
 * * @param dest The destination buffer (must be at least n1+n2 bytes).
 * @param arr1 First array (e.g., Node ID).
 * @param n1   Size of arr1.
 * @param arr2 Second array (e.g., Command Data).
 * @param n2   Size of arr2.
 */
static inline void BC_MessageBuilder(uint8_t* dest, const uint8_t* arr1, uint8_t n1, const uint8_t* arr2, uint8_t n2) {
    if (dest == NULL) return;
    if (arr1 != NULL) memcpy(dest, arr1, n1);
    if (arr2 != NULL) memcpy(dest + n1, arr2, n2);
}

/**
 * @brief Convert 4-byte array (Big Endian) to uint32_t.
 */
static inline uint32_t BC_Unchunk32(const uint8_t* dataBytes) {
    if (dataBytes == NULL) return 0;
    return ((uint32_t)dataBytes[0] << 24) |
           ((uint32_t)dataBytes[1] << 16) |
           ((uint32_t)dataBytes[2] << 8)  |
           ((uint32_t)dataBytes[3]);
}

/**
 * @brief Convert 2-byte array (Big Endian) to uint16_t.
 */
static inline uint16_t BC_Unchunk16(const uint8_t* dataBytes) {
    if (dataBytes == NULL) return 0;
    return ((uint16_t)dataBytes[0] << 8) |
           ((uint16_t)dataBytes[1]);
}

/**
 * @brief Convert uint32_t to 4-byte array (Big Endian).
 */
static inline void BC_Chunk32(uint32_t inVal, uint8_t* outArray) {
    if (outArray != NULL) {
        outArray[0] = (uint8_t)(inVal >> 24);
        outArray[1] = (uint8_t)(inVal >> 16);
        outArray[2] = (uint8_t)(inVal >> 8);
        outArray[3] = (uint8_t)(inVal);
    }
}

/**
 * @brief Convert uint16_t to 2-byte array (Big Endian).
 */
static inline void BC_Chunk16(uint16_t inVal, uint8_t* outArray) {
    if (outArray != NULL) {
        outArray[0] = (uint8_t)(inVal >> 8);
        outArray[1] = (uint8_t)(inVal);
    }
}

#endif // BYTE_CONVERSION_H