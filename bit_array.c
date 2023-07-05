#include <stdio.h>
#include <stdint.h>
#define BIT_ARRAY_SIZE 73
#define BITS_PER_INT (sizeof(unsigned int) * 8)

// Set the bit at the specified index in the array
void setBit(unsigned int* array, int index) {
    int arrayIndex = index / BITS_PER_INT;
    int bitIndex = index % BITS_PER_INT;
    array[arrayIndex] |= (1u << bitIndex);
}

// Clear the bit at the specified index in the array
void clearBit(unsigned int* array, int index) {
    int arrayIndex = index / BITS_PER_INT;
    int bitIndex = index % BITS_PER_INT;
    array[arrayIndex] &= ~(1u << bitIndex);
}

// Check if the bit at the specified index is set in the array
int isBitSet(unsigned int* array, int index) {
    int arrayIndex = index / BITS_PER_INT;
    int bitIndex = index % BITS_PER_INT;
    return (array[arrayIndex] >> bitIndex) & 1u;
}

int main() {
    unsigned int bitArray[BIT_ARRAY_SIZE / BITS_PER_INT] = { 0 }; // Initialize the bit array with all bits set to 0
    uint32_t readData[16];
    printf("Read data %d , uint32_t %d \n", sizeof(readData), sizeof(uint32_t));
    setBit(bitArray, 2); // Set the bit at index 2
    setBit(bitArray, 5); // Set the bit at index 5
    setBit(bitArray, 73); // Set the bit at index 73
    printf("Bit array: side= %d :: ", BIT_ARRAY_SIZE / BITS_PER_INT);
    for (int i = 0; i < BIT_ARRAY_SIZE / BITS_PER_INT; i++) {
        printf("%08x ", bitArray[i]);
    }
    printf("\n");

    printf("Is bit at index 2 set? %s\n", isBitSet(bitArray, 2) ? "Yes" : "No");
    printf("Is bit at index 3 set? %s\n", isBitSet(bitArray, 3) ? "Yes" : "No");
    printf("Is bit at index 73 set? %s\n", isBitSet(bitArray, 73) ? "Yes" : "No");

    clearBit(bitArray, 73); // Clear the bit at index 5

    printf("Bit array after clearing bit at index 5: ");
    for (int i = 0; i < BIT_ARRAY_SIZE / BITS_PER_INT; i++) {
        printf("%08x ", bitArray[i]);
    }
    printf("\n");

    return 0;
}