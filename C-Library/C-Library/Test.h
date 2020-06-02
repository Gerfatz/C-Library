#pragma once
#include "stdint.h"
#include "string.h"
#include "common.h"

Bool GetSectionBasicTest(void);
Bool GetSectionInvalidStartParamTest(void);
Bool GetSectionInvalidEndParamTest(void);
Bool GetSectionEndLargerThanStartTest(void);

Bool ZweierkomplementTest(void);
Bool ZweierkomplementTooSmallBufferTest(void);

Bool DecToBinTest(void);
Bool BinToDecTest(void);