#include "Convert.h"

int Bintodec(long long bin) {
	int dec = 0;
	int i = 0;
	int rem;
	while (bin != 0) {
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}

//Convert decimal to binary
long long Dectobin(int dec) {
	long long bin = 0;
	int rem;
	int i = 1;
	int step = 1;
	while (dec != 0) {
		rem = dec % 2;
		dec /= 2;
		bin += rem * i;
		i *= 10;
	}
	return bin;
}