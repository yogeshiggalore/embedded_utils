#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include "bit_util.h"

static uint8_t print_lvl = BIT_PRNT_LVL_NON;
const char* print_lvl_code[] = {"NON", "DBG", "ERR", "WAR", "INF"};

void bit_util_print(BIT_PRNT_LVL lvl, const char* format, ...) 
{
    
    if( (lvl >= BIT_PRNT_LVL_DBG) && (lvl<= print_lvl)  )
    {
        printf("[%s]:", print_lvl_code[lvl]);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

void bit_util_set_dbg_lvl( BIT_PRNT_LVL lvl )
{
    print_lvl = lvl;

    bit_util_print(BIT_PRNT_LVL_DBG, "%s%s\n", "setting print level to ", print_lvl_code[print_lvl]);
}

BIT_PRNT_LVL bit_util_get_dbg_lvl( void )
{
    return print_lvl;
}

void bit_util_OR( void *dataA, void *dataB,  uint8_t datasize,  void *result, uint8_t ressize)
{   

}


