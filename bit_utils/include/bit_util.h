#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum 
{
    BIT_PRNT_LVL_NON=0, //none
    BIT_PRNT_LVL_DBG,   //print debug data
    BIT_PRNT_LVL_ERR,   //print error data
    BIT_PRNT_LVL_WAR,   //print warning data
    BIT_PRNT_LVL_INF    //print info data
}BIT_PRNT_LVL;

void bit_util_print(BIT_PRNT_LVL lvl, const char* format, ...);
void bit_util_set_dbg_lvl( BIT_PRNT_LVL lvl );
BIT_PRNT_LVL bit_util_get_dbg_lvl( void );

uint8_t bit_util_decimal_to_binary( void* data, uint8_t dataSize, char** binStr );

uint64_t bit_util_get_val( void *data, uint8_t dataSize );

bool bit_util_OR( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes);
bool bit_util_AND( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes);
bool bit_util_XOR( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes);
bool bit_util_NOT( void *dataA, uint8_t dataSize,  void **dataRes);

bool bit_util_LEFT_SHIFT( void *dataA, uint8_t dataSize, uint8_t shift, void **dataRes);
bool bit_util_RIGHT_SHIFT( void *dataA, uint8_t dataSize, uint8_t shift, void **dataRes);

bool bit_util_ROTATE_BITS_LEFT(void *dataA, uint8_t dataSize, uint8_t rotate, void **dataRes);
bool bit_util_ROTATE_BITS_RIGHT(void *dataA, uint8_t dataSize, uint8_t rotate, void **dataRes);

bool bit_util_BITWISE_OR( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes);
bool bit_util_BITWISE_AND( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes);
bool bit_util_BITWISE_XOR( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes);

bool bit_util_CHECK_BIT( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes);


bool bit_util_ISOLATE_RIGHTMOST_1( void *dataA, uint8_t dataSize, void **dataRes);
bool bit_util_CLEAR_RIGHTMOST_1( void *dataA, uint8_t dataSize);

bool bit_util_FLIP_ALL_BITS( void *dataA, uint8_t dataSize, void **dataRes);
bool bit_util_COMPUTE_2S( void *dataA, uint8_t dataSize, void **dataRes);

bool bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( void *dataA, uint8_t dataSize, void **dataRes);
bool bit_util_TURN_ON_ALL_EXP_RIGHTMOST( void *dataA, uint8_t dataSize, void **dataRes);