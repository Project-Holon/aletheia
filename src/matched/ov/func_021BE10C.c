/*
 * function: func_021BE10C
 * address:  0x021BE10C
 * packet:   pkt_021BE10C
 * region:   ov204
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

int func_021BE10C(char *p, int b, int *c)
{
    *(int *)(p + 0x1C) = *c;
    *(int *)(p + 0xA0) = 0;
    return 1;
}
