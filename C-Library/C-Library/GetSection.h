#pragma once
#include "stdint.h"

#define SIZE_IN_BITS(type) sizeof(type) * 8

#define SET_STATUS_FAILIURE(code) *result = 0; return code;

int8_t GetSection(int32_t number, uint8_t start, uint8_t end, int32_t * result);
