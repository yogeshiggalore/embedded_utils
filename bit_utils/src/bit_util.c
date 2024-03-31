#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdbool.h>

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

uint8_t bit_util_decimal_to_binary( void* data, uint8_t dataSize, char** binStr )
{
    uint8_t strSize=0;
    uint8_t index=0;
    uint64_t val;
    
    if( dataSize > 8 )
    {
        strSize = sizeof(char) * 65;
        *binStr = (char *)malloc( strSize );
    }
    else
    {
        strSize = (dataSize * 8) + 1;
        *binStr = (char *)malloc( strSize );
    }

    if( *binStr == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return 0;
    }

    (*binStr)[ strSize - 1 ] = '\0';
    strSize--;
    index = strSize - 1;

    val = bit_util_get_val(data, dataSize);

    for( uint8_t loopcntr=0; loopcntr < strSize; loopcntr++ )
    {
        if( (val & 1) == 1)
        {
            (*binStr)[ index ] = '1';
        }
        else
        {
            (*binStr)[ index ] = '0';
        }

        val >>= 1;
        index--;
    }

    return 1;
} 

BIT_PRNT_LVL bit_util_get_dbg_lvl( void )
{
    return print_lvl;
}

uint64_t bit_util_get_val( void *data, uint8_t dataSize )
{
    uint64_t val;

    switch (dataSize)
    {
    case 1:
        val = *(uint8_t*)data;
        break;

    case 2:
        val = *(uint16_t*)data;
        break;
    
    case 4:
        val = *(uint32_t*)data;
        break;

    case 8:
        val = *(uint64_t*)data;
        break;

    default:
        val = *(uint64_t*)data;
        break;
    }

    return val;
}

bool bit_util_OR( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes)
{   
    uint64_t val1;
    uint64_t val2;

    val1 = bit_util_get_val(dataA, dataSize);
    val2 = bit_util_get_val(dataB, dataSize);

    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = (val1 | val2);
    }

    return true;    
}   

bool bit_util_AND( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes)
{   
    uint64_t val1;
    uint64_t val2;

    val1 = bit_util_get_val(dataA, dataSize);
    val2 = bit_util_get_val(dataB, dataSize);

    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = (val1 & val2);
    }

    return true;    
}

bool bit_util_XOR( void *dataA, void *dataB,  uint8_t dataSize,  void **dataRes)
{   
    uint64_t val1;
    uint64_t val2;

    val1 = bit_util_get_val(dataA, dataSize);
    val2 = bit_util_get_val(dataB, dataSize);

    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = (val1 ^ val2);
    }

    return true;    
}

bool bit_util_NOT( void *dataA, uint8_t dataSize,  void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = ~val;
    }

    return true;
}

bool bit_util_LEFT_SHIFT( void *dataA, uint8_t dataSize, uint8_t shift, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = val << shift;
    }

    return true;
}

bool bit_util_RIGHT_SHIFT( void *dataA, uint8_t dataSize, uint8_t shift, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = val >> shift;
    }

    return true;
}

bool bit_util_ROTATE_BITS_LEFT(void *dataA, uint8_t dataSize, uint8_t rotate, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = ( val << rotate ) | ( val >> (( dataSize * 8 ) - rotate)) ;
    }

    return true;
}


bool bit_util_ROTATE_BITS_RIGHT(void *dataA, uint8_t dataSize, uint8_t rotate, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = ( val >> rotate ) | ( val << (( dataSize * 8 ) - rotate)) ;
    }

    return true;
}


bool bit_util_BITWISE_OR( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes =  (val | (1 << pos) );
    }

    return true;
}

bool bit_util_BITWISE_AND( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes =  (val & ~(1 << pos) );
    }

    return true;
}

bool bit_util_BITWISE_XOR( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes =  (val ^ (1 << pos) );
    }

    return true;
}

bool bit_util_CHECK_BIT( void *dataA, uint8_t dataSize, uint8_t pos, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        if( (val & (1 << pos) ) != 0)
        {
            *(uint64_t *)*dataRes = true;
        }
        else
        {
            *(uint64_t *)*dataRes = false;
        }
        
    }

    return true;
}

bool bit_util_ISOLATE_RIGHTMOST_1( void *dataA, uint8_t dataSize, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes =  (val & (-val) );
    }

    return true;    
}

bool bit_util_FLIP_ALL_BITS( void *dataA, uint8_t dataSize, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = ~val;
    }

    return true;
}

bool bit_util_COMPUTE_2S( void *dataA, uint8_t dataSize, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = 1 << val;
    }

    return true;
}

bool bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( void *dataA, uint8_t dataSize, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = (val & (-val));
    }

    return true;
}

bool bit_util_TURN_ON_ALL_EXP_RIGHTMOST( void *dataA, uint8_t dataSize, void **dataRes)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    *dataRes = (void *) malloc( dataSize );
    if( *dataRes == NULL )
    {
        bit_util_print(BIT_PRNT_LVL_ERR, "%s\n", "failed to allocate memory");
        return false;
    }
    else
    {
        *(uint64_t *)*dataRes = (val | (val - 1));
    }

    return true;
}


bool bit_util_CLEAR_RIGHTMOST_1( void *dataA, uint8_t dataSize)
{
    uint64_t val;

    val = bit_util_get_val(dataA, dataSize);
    
    val = val & (val - 1);

    *(uint64_t *)dataA = val;
    
    return true;    
}
