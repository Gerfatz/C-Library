#include "Convert.h"

uint16_t Bintodec(uint64_t bin) {
	uint16_t dec = 0;
	int8_t i = 0;
	int8_t rem;
	while (bin != 0) {
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}

//Convert decimal to binary
uint64_t Dectobin(uint16_t dec) {
	uint64_t bin = 0;
	uint8_t rem;
	uint64_t i = 1;
	while (dec != 0) {
		rem = dec % 2;
		dec /= 2;
		bin += (uint64_t)rem * i;
		i *= 10;
	}
	return bin;
}