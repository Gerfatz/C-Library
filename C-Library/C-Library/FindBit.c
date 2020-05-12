
#include "FindBit.h"

int8_t FindLastBitt(int32_t binaryNumber) {
    int8_t foundBit = 0;
    int8_t counter = -1;
    while (!foundBit) {
        if ((binaryNumber % 10) > 0) {
            foundBit = 1;
        }
        binaryNumber /= 10;
        counter++;
    }
    return counter;
}

int8_t FindLastBit(char* binaryNumber) {
    int8_t foundBit = 0;
    int8_t counter = -1;
    while (!foundBit) {
       char bit = binaryNumber[strlen(binaryNumber) - 1];
       if (bit == '1') {
           foundBit = 1;
       }
       counter++;
    }
    return counter;

}
