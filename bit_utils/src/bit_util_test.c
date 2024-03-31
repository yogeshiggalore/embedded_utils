#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "bit_util_test.h"
#include "bit_util.h"

int main()
{
	printf("testing bit utils lib\n");
	bit_util_set_dbg_lvl(BIT_PRNT_LVL_ERR);
	
	bit_util_test_decimal_to_binary();
	bit_util_test_OR();
	bit_util_test_AND();
	bit_util_test_XOR();
	bit_util_test_LEFT_SHIFT();
	bit_util_test_RIGHT_SHIFT();
	bit_util_test_ROTATE_BITS_LEFT();
	bit_util_test_ROTATE_BITS_RIGHT();
	bit_util_test_BITWISE_OR();
	bit_util_test_BITWISE_AND();
	bit_util_test_BITWISE_XOR();
	bit_util_test_CHECK_BIT();
	bit_util_test_ISOLATE_RIGHTMOST_1();
	bit_util_test_FLIP_ALL_BITS();
	bit_util_test_COMPUTE_2S();
	bit_util_test_TURN_OFF_ALL_EXP_RIGHTMOST();
	bit_util_test_TURN_ON_ALL_EXP_RIGHTMOST();

	return 0;
}


void bit_util_test_decimal_to_binary(void)
{
	uint8_t val8 = 0x81;
	uint16_t val16 = 0x81;
	uint32_t val32 = 0x80000001;
	uint64_t val64 = 0x8000000000000001;
	
	char *buf=NULL;

	printf("testing function %s\n", __func__);

	bit_util_decimal_to_binary(&val8, sizeof(val8), &buf);
	printf("val of 0x%X in binary %s\n", val8, buf);
	free(buf);
	buf = NULL;

	bit_util_decimal_to_binary(&val16, sizeof(val16), &buf);
	printf("val of 0x%X in binary %s\n", val16, buf);
	free(buf);
	buf = NULL;

	bit_util_decimal_to_binary(&val32, sizeof(val32),&buf);
	printf("val of 0x%X in binary %s\n", val32, buf);
	free(buf);
	buf = NULL;

	bit_util_decimal_to_binary(&val64, sizeof(val64),&buf);
	printf("val of 0x%" PRIx64 "in binary %s\n", val64, buf);
	free(buf);
	buf = NULL;

	printf("testing completed\n\n\n");
}

void bit_util_test_OR(void)
{
	uint8_t val8_1;
	uint8_t val8_2;
	uint8_t *res8;

	uint16_t val16_1;
	uint16_t val16_2;
	uint16_t *res16;

	uint32_t val32_1;
	uint32_t val32_2;
	uint32_t *res32;

	uint64_t val64_1;
	uint64_t val64_2;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8_1 = 0x01;
	val8_2 = 0x10;
    if(bit_util_OR( &val8_1, &val8_2, sizeof(val8_1),(void**)&res8 ))
	{
		printf("bit_util_OR of 0x%x and 0x%x is 0x%x\n", val8_1, val8_2, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16_1 = 0x0101;
	val16_2 = 0x1010;
    if(bit_util_OR( &val16_1, &val16_2, sizeof(val16_1),(void**)&res16 ))
	{
		printf("bit_util_OR of 0x%x and 0x%x is 0x%x\n", val16_1, val16_2, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32_1 = 0x01010101;
	val32_2 = 0x10101010;
    if(bit_util_OR( &val32_1, &val32_2, sizeof(val32_1),(void**)&res32 ))
	{
		printf("bit_util_OR of 0x%x and 0x%x is 0x%x\n", val32_1, val32_2, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64_1 = 0x0101010101010101;
	val64_2 = 0x1010101010101010;
	if(bit_util_OR( &val64_1, &val64_2, sizeof(val64_1),(void**)&res64 ))
	{
		printf("bit_util_OR of 0x%" PRIx64 " and 0x%"PRIx64 " is 0x%"PRIx64 "\n", val64_1, val64_2, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;


	printf("testing completed\n\n\n\n");
}

void bit_util_test_AND(void)
{
	uint8_t val8_1;
	uint8_t val8_2;
	uint8_t *res8;

	uint16_t val16_1;
	uint16_t val16_2;
	uint16_t *res16;

	uint32_t val32_1;
	uint32_t val32_2;
	uint32_t *res32;

	uint64_t val64_1;
	uint64_t val64_2;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8_1 = 0x01;
	val8_2 = 0x10;
    if(bit_util_AND( &val8_1, &val8_2, sizeof(val8_1),(void**)&res8 ))
	{
		printf("bit_util_AND of 0x%x and 0x%x is 0x%x\n", val8_1, val8_2, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16_1 = 0x0101;
	val16_2 = 0x1010;
    if(bit_util_AND( &val16_1, &val16_2, sizeof(val16_1),(void**)&res16 ))
	{
		printf("bit_util_AND of 0x%x and 0x%x is 0x%x\n", val16_1, val16_2, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32_1 = 0x01010101;
	val32_2 = 0x10101010;
    if(bit_util_AND( &val32_1, &val32_2, sizeof(val32_1),(void**)&res32 ))
	{
		printf("bit_util_AND of 0x%x and 0x%x is 0x%x\n", val32_1, val32_2, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64_1 = 0x0101010101010101;
	val64_2 = 0x1010101010101010;
	if(bit_util_AND( &val64_1, &val64_2, sizeof(val64_1),(void**)&res64 ))
	{
		printf("bit_util_AND of 0x%" PRIx64 " and 0x%"PRIx64 " is 0x%"PRIx64 "\n", val64_1, val64_2, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_XOR(void)
{
	uint8_t val8_1;
	uint8_t val8_2;
	uint8_t *res8;

	uint16_t val16_1;
	uint16_t val16_2;
	uint16_t *res16;

	uint32_t val32_1;
	uint32_t val32_2;
	uint32_t *res32;

	uint64_t val64_1;
	uint64_t val64_2;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8_1 = 0x01;
	val8_2 = 0x10;
    if(bit_util_XOR( &val8_1, &val8_2, sizeof(val8_1),(void**)&res8 ))
	{
		printf("bit_util_XOR of 0x%x and 0x%x is 0x%x\n", val8_1, val8_2, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16_1 = 0x0101;
	val16_2 = 0x1010;
    if(bit_util_XOR( &val16_1, &val16_2, sizeof(val16_1),(void**)&res16 ))
	{
		printf("bit_util_XOR of 0x%x and 0x%x is 0x%x\n", val16_1, val16_2, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32_1 = 0x01010101;
	val32_2 = 0x10101010;
    if(bit_util_XOR( &val32_1, &val32_2, sizeof(val32_1),(void**)&res32 ))
	{
		printf("bit_util_XOR of 0x%x and 0x%x is 0x%x\n", val32_1, val32_2, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64_1 = 0x0101010101010101;
	val64_2 = 0x1010101010101010;
	if(bit_util_XOR( &val64_1, &val64_2, sizeof(val64_1),(void**)&res64 ))
	{
		printf("bit_util_XOR of 0x%" PRIx64 " and 0x%"PRIx64 " is 0x%"PRIx64 "\n", val64_1, val64_2, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_LEFT_SHIFT(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_LEFT_SHIFT( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_LEFT_SHIFT of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_LEFT_SHIFT( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_LEFT_SHIFT of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_LEFT_SHIFT( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_LEFT_SHIFT of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_LEFT_SHIFT( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_LEFT_SHIFT of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_RIGHT_SHIFT(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_RIGHT_SHIFT( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_RIGHT_SHIFT of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_RIGHT_SHIFT( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_RIGHT_SHIFT of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_RIGHT_SHIFT( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_RIGHT_SHIFT of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_RIGHT_SHIFT( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_RIGHT_SHIFT of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_ROTATE_BITS_LEFT(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_ROTATE_BITS_LEFT( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_ROTATE_BITS_LEFT of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_ROTATE_BITS_LEFT( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_ROTATE_BITS_LEFT of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_ROTATE_BITS_LEFT( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_ROTATE_BITS_LEFT of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_ROTATE_BITS_LEFT( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_ROTATE_BITS_LEFT of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_ROTATE_BITS_RIGHT(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_ROTATE_BITS_RIGHT( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_ROTATE_BITS_RIGHT of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_ROTATE_BITS_RIGHT( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_ROTATE_BITS_RIGHT of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_ROTATE_BITS_RIGHT( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_ROTATE_BITS_RIGHT of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_ROTATE_BITS_RIGHT( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_ROTATE_BITS_RIGHT of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_BITWISE_OR(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_BITWISE_OR( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_BITWISE_OR of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_BITWISE_OR( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_BITWISE_OR of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_BITWISE_OR( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_BITWISE_OR of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_BITWISE_OR( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_BITWISE_OR of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");	
}

void bit_util_test_BITWISE_AND(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_BITWISE_AND( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_BITWISE_AND of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_BITWISE_AND( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_BITWISE_AND of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_BITWISE_AND( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_BITWISE_AND of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_BITWISE_AND( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_BITWISE_AND of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");	
}

void bit_util_test_BITWISE_XOR(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_BITWISE_XOR( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_BITWISE_XOR of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_BITWISE_XOR( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_BITWISE_XOR of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_BITWISE_XOR( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_BITWISE_XOR of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_BITWISE_XOR( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_BITWISE_XOR of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");	
}

void bit_util_test_CHECK_BIT(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_CHECK_BIT( &val8, sizeof(val8), 1, (void**)&res8 ))
	{
		printf("bit_util_CHECK_BIT of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_CHECK_BIT( &val16, sizeof(val16), 1,(void**)&res16 ))
	{
		printf("bit_util_CHECK_BIT of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_CHECK_BIT( &val32, sizeof(val32), 1, (void**)&res32 ))
	{
		printf("bit_util_CHECK_BIT of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_CHECK_BIT( &val64, sizeof(val64), 1,(void**)&res64 ))
	{
		printf("bit_util_CHECK_BIT of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");	
}

void bit_util_test_ISOLATE_RIGHTMOST_1(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_ISOLATE_RIGHTMOST_1( &val8, sizeof(val8), (void**)&res8 ))
	{
		printf("bit_util_ISOLATE_RIGHTMOST_1 of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_ISOLATE_RIGHTMOST_1( &val16, sizeof(val16), (void**)&res16 ))
	{
		printf("bit_util_ISOLATE_RIGHTMOST_1 of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_ISOLATE_RIGHTMOST_1( &val32, sizeof(val32), (void**)&res32 ))
	{
		printf("bit_util_ISOLATE_RIGHTMOST_1 of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_ISOLATE_RIGHTMOST_1( &val64, sizeof(val64),(void**)&res64 ))
	{
		printf("bit_util_ISOLATE_RIGHTMOST_1 of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");		
}

void bit_util_test_TURN_OFF_ALL_EXP_RIGHTMOST(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( &val8, sizeof(val8), (void**)&res8 ))
	{
		printf("bit_util_TURN_OFF_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( &val16, sizeof(val16), (void**)&res16 ))
	{
		printf("bit_util_TURN_OFF_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( &val32, sizeof(val32), (void**)&res32 ))
	{
		printf("bit_util_TURN_OFF_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_TURN_OFF_ALL_EXP_RIGHTMOST( &val64, sizeof(val64),(void**)&res64 ))
	{
		printf("bit_util_TURN_OFF_ALL_EXP_RIGHTMOST of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_TURN_ON_ALL_EXP_RIGHTMOST(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_TURN_ON_ALL_EXP_RIGHTMOST( &val8, sizeof(val8), (void**)&res8 ))
	{
		printf("bit_util_TURN_ON_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_TURN_ON_ALL_EXP_RIGHTMOST( &val16, sizeof(val16), (void**)&res16 ))
	{
		printf("bit_util_TURN_ON_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_TURN_ON_ALL_EXP_RIGHTMOST( &val32, sizeof(val32), (void**)&res32 ))
	{
		printf("bit_util_TURN_ON_ALL_EXP_RIGHTMOST of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_TURN_ON_ALL_EXP_RIGHTMOST( &val64, sizeof(val64),(void**)&res64 ))
	{
		printf("bit_util_TURN_ON_ALL_EXP_RIGHTMOST of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_FLIP_ALL_BITS(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_FLIP_ALL_BITS( &val8, sizeof(val8), (void**)&res8 ))
	{
		printf("bit_util_FLIP_ALL_BITS of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_FLIP_ALL_BITS( &val16, sizeof(val16), (void**)&res16 ))
	{
		printf("bit_util_FLIP_ALL_BITS of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_FLIP_ALL_BITS( &val32, sizeof(val32), (void**)&res32 ))
	{
		printf("bit_util_FLIP_ALL_BITS of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_FLIP_ALL_BITS( &val64, sizeof(val64),(void**)&res64 ))
	{
		printf("bit_util_FLIP_ALL_BITS of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_COMPUTE_2S(void)
{
	uint8_t val8;
	uint8_t *res8;

	uint16_t val16;
	uint16_t *res16;

	uint32_t val32;
	uint32_t *res32;

	uint64_t val64;
	uint64_t *res64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
    if(bit_util_COMPUTE_2S( &val8, sizeof(val8), (void**)&res8 ))
	{
		printf("bit_util_COMPUTE_2S of 0x%x is 0x%x\n", val8, *res8);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res8);
	res8 = NULL;

	val16 = 0x0101;
    if(bit_util_COMPUTE_2S( &val16, sizeof(val16), (void**)&res16 ))
	{
		printf("bit_util_COMPUTE_2S of 0x%x is 0x%x\n", val16, *res16);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res16);
	res16 = NULL;

	val32 = 0x01010101;
    if(bit_util_COMPUTE_2S( &val32, sizeof(val32), (void**)&res32 ))
	{
		printf("bit_util_COMPUTE_2S of 0x%x is 0x%x\n", val32, *res32);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res32);
	res32 = NULL;

	val64 = 0x0101010101010101;
	if(bit_util_COMPUTE_2S( &val64, sizeof(val64),(void**)&res64 ))
	{
		printf("bit_util_COMPUTE_2S of 0x%" PRIx64 " is 0x%"PRIx64 "\n", val64, *res64);
	}
	else
	{
		printf("failed to allocate memory\n");
	}
	free(res64);
	res64 = NULL;

	printf("testing completed\n\n\n\n");
}

void bit_util_test_CLEAR_RIGHTMOST_1(void)
{
	uint8_t val8;
	uint8_t ref8;

	uint16_t val16;
	uint16_t ref16;

	uint32_t val32;
	uint32_t ref32;

	uint64_t val64;
	uint64_t ref64;

	printf("testing function %s\n", __func__);

	val8 = 0x01;
	ref8 = 0x01;
    if(bit_util_CLEAR_RIGHTMOST_1( &val8, sizeof(val8)))
	{
		printf("bit_util_CLEAR_RIGHTMOST_1 of 0x%x is 0x%x\n", ref8, val8);
	}
	
	val16 = 0x0101;
	ref16 = 0x0101;
    if(bit_util_CLEAR_RIGHTMOST_1( &val16, sizeof(val16)))
	{
		printf("bit_util_CLEAR_RIGHTMOST_1 of 0x%x is 0x%x\n", ref16, val16);
	}

	val32 = 0x01010101;
	ref32 = 0x01010101;
    if(bit_util_CLEAR_RIGHTMOST_1( &val32, sizeof(val32)))
	{
		printf("bit_util_CLEAR_RIGHTMOST_1 of 0x%x is 0x%x\n", ref32, val32);
	}

	val64 = 0x0101010101010101;
	ref64 = 0x0101010101010101;
    if(bit_util_CLEAR_RIGHTMOST_1( &val64, sizeof(val64)))
	{
		printf("bit_util_CLEAR_RIGHTMOST_1 of 0x%" PRIx64 " is 0x%"PRIx64 "\n", ref64, val64);
	}

	printf("testing completed\n");		
}
