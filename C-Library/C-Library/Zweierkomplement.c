#include "Zweierkomplement.h"
#define MOVE_NEXT position--;zahl>>=1;
/*
	Berechnet das Zweierkomplement und schreibt es in einen string.

	returns:
		0x00: OK
		0x01: Buffer zu klein
*/
uint8_t GetZweierKomplement(int8_t zahl, char* result, uint8_t bufferLength)
{
	if (bufferLength < 9) 
	{
		return 0x01;
	}
	else
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			result[i] = '0';
		}

		result[8] = '\0';
	}

	uint8_t mask = 0x01;
	int8_t position = 7;

	while (!(zahl & mask) && position >= 0)
	{
		MOVE_NEXT
	}

	if (zahl & mask)
	{
		result[position] = '1';
		MOVE_NEXT
	}

	while (zahl && (position + 1) != 0)
	{
		result[position] = zahl & mask ? '0' : '1';
		MOVE_NEXT
	}
	
	while (position >= 0)
	{
		result[position] = '1';
		MOVE_NEXT
	}

	return 0x00;

}