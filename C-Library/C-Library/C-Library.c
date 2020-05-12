#include "stdio.h"
#include "GetSection.h"
#include "Test.h"
#include "FindBit.h"

void Runtest(const char* name, uint8_t(*testFunction)(void)) {
    if (testFunction()) {
        printf("%s - Erfolgreich\n", name);
    }
    else 
    {
        printf("%s - Fehlgeschlagen\n", name);
    }
}

void TestGetSection() {
    Runtest("GetSection Basis Test", &GetSectionBasicTest);
    Runtest("GetSection Start Parameter Test", &GetSectionInvalidStartParamTest);
    Runtest("GetSection End Parameter Test", &GetSectionInvalidEndParamTest);
    Runtest("GetSection Start larger than End Test", &GetSectionEndLargerThanStartTest);
}

int main()
{
    FindLastBit("100");
    FindLastBit(100);
    return 0;
}
