#include "stdio.h"
#include "GetSection.h"
#include "Zweierkomplement.h"
#include "Test.h"
#include "common.h"
#include "Convert.h"


void RunTest(const char* name, Bool(*testFunction)(void)) {
    if (testFunction()) {
        printf("%s - Erfolgreich\n", name);
    }
    else 
    {
        printf("%s - Fehlgeschlagen\n", name);
    }
}

void TestGetSection() {
    RunTest("GetSection Basis Test", &GetSectionBasicTest);
    RunTest("GetSection Start Parameter Test", &GetSectionInvalidStartParamTest);
    RunTest("GetSection End Parameter Test", &GetSectionInvalidEndParamTest);
    RunTest("GetSection Start larger than End Test", &GetSectionEndLargerThanStartTest);
}

void TestZweierkomplement()
{
    RunTest("Zweierkomplement Test", &ZweierkomplementTest);
    RunTest("Zweierkomplement buffer too small Test", &ZweierkomplementTooSmallBufferTest);
}

void ConversionsTest()
{
    RunTest("DecToBin", &DecToBinTest);
    RunTest("BinToDec", &BinToDecTest);
}

int main()
{
    TestGetSection();
    printf("\n");
    TestZweierkomplement();
    printf("\n");
    ConversionsTest();
    return 0;
}