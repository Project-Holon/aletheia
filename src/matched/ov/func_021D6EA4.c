/*
 * function: func_021D6EA4
 * address:  0x021D6EA4
 * packet:   pkt_021D6EA4
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021D6EA4(char *p)
{
    char *q = *(char **)(p + 0x20);

    return *(int *)(q + 0x50) != 0 && *(u16 *)(q + 0xC) == 0;
}
