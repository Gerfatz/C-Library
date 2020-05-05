#include "GetSection.h"

int8_t GetSection(int32_t number, uint8_t start, uint8_t end, int32_t* result) 
{
	if (end > SIZE_IN_BITS(int32_t))
	{
		SET_STATUS_FAILIURE(0x03)
	}
	else if (start > SIZE_IN_BITS(int32_t)) 
	{
		SET_STATUS_FAILIURE(0x02)
	}
	else if (start > end)
	{
		SET_STATUS_FAILIURE(0x01)
	}
	else 
	{
		uint8_t numberOfBits = end - start + 1;
		register uint32_t mask = 0x00;

		for (int32_t i = 0; i < numberOfBits; i++) {
			mask++;
			mask <<= 1;
		}

		for (int32_t i = 0; i < start - 1; i++) {
			mask <<= 1;
		}

		*result = number & mask;

		while (!(mask & 0x01))
		{
			*result >>= 1;
			mask >>= 1;
		}

		return 0x00;
	}
}