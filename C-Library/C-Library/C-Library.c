#include "stdio.h"
#include "GetSection.h"
#include "Zweierkomplement.h"
#include "Test.h"
#include "common.h"

void Runtest(const char* name, Bool(*testFunction)(void)) {
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

void TestZweierkomplement()
{
    Runtest("Zweierkomplement Test", &ZweierkomplementTest);
    Runtest("Zweierkomplement buffer too small Test", &ZweierkomplementTooSmallBufferTest);
}

int main()
{
    TestGetSection();
    printf("\n");
    TestZweierkomplement();

    return 0;
}
