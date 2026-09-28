/*
 * function: func_021D62E4
 * address:  0x021D62E4
 * packet:   pkt_021D62E4
 * region:   ov131
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

int func_021D62E4(char *p)
{
    char *q = *(char **)(p + 8);

    return *(int *)(q + 0x20) == 1;
}
