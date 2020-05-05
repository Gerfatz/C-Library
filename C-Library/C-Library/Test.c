#include "Test.h"
#include "GetSection.h"


/*
	20 = 0b10100
	Ausschneiden von bit 1, 2 und 3.
	Erwartetes Resultat: 2
*/
uint8_t GetSectionBasicTest(void) 
{
	int32_t result = 0;
	int8_t statuscode = GetSection(20, 1, 3, &result);

	return !statuscode && result == 2;
}

uint8_t GetSectionInvalidStartParamTest(void) 
{
	int32_t result = 0;
	return GetSection(20, SIZE_IN_BITS(int32_t) + 1, 3, &result) == 0x02 && result == 0;
}

uint8_t GetSectionInvalidEndParamTest(void) 
{
	int32_t result = 0;
	return GetSection(20, 1, SIZE_IN_BITS(int32_t) + 1, &result) == 0x03 && result == 0;
}

uint8_t GetSectionEndLargerThanStartTest(void) 
{
	int32_t result = 0;
	return GetSection(20, 6, 3, &result) == 0x01 && result == 0;
}