#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

void bit_util_OR( void *dataA, void *dataB,  uint8_t datasize,  void *result, uint8_t ressize);
