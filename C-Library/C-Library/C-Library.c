#include "stdio.h"
#include "GetSection.h"
#include "Test.h"
#include "Convert.h"

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
    TestGetSection();
    int n;
    printf("Enter a decimal number (max. 1023): ");
    scanf_s("%d", &n);
    printf("%d in decimal = %lld in binary", n, Dectobin(n));

    long long i;
    printf("\nEnter a binary number: ");
    scanf_s("%lld", &i);
    printf("%lld in binary = %d in decimal", i, Bintodec(i));
    return 0;
}