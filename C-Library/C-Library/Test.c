#include "Test.h"
#include "GetSection.h"
#include "Zweierkomplement.h"
#include "Convert.h"


/*********************************************
***************** GetSection *****************
*********************************************/
Bool GetSectionBasicTest(void) 
{
	int32_t result = 0;
	int8_t statuscode = GetSection(20, 1, 3, &result);

	return !statuscode && result == 2;
}

Bool GetSectionInvalidStartParamTest(void) 
{
	int32_t result = 0;
	return GetSection(20, SIZE_IN_BITS(int32_t) + 1, 3, &result) == 0x02 && result == 0;
}

Bool GetSectionInvalidEndParamTest(void) 
{
	int32_t result = 0;
	return GetSection(20, 1, SIZE_IN_BITS(int32_t) + 1, &result) == 0x03 && result == 0;
}

Bool GetSectionEndLargerThanStartTest(void) 
{
	int32_t result = 0;
	return GetSection(20, 6, 3, &result) == 0x01 && result == 0;
}

/*********************************************
************** Zweierkomplement **************
*********************************************/
Bool ZweierkomplementTest(void)
{
	char zweierkomplement[9];
	int8_t code = GetZweierKomplement(20, zweierkomplement, 9);

	return !strcmp(zweierkomplement, "11101100") && !code;
}

Bool ZweierkomplementTooSmallBufferTest(void)
{
	char zweierkomplement[8];
	return GetZweierKomplement(20, zweierkomplement, 8); //Expects code 0x01
}

/*********************************************
****************** Convert ******************
*********************************************/
Bool DecToBinTest(void)
{
	uint64_t result = Dectobin(2000);
	return result == 0x296448ED0;
}

Bool BinToDecTest(void)
{
	uint16_t result = Bintodec(0x296448ED0);
	return result == 2000;
}

