/*
 * function: func_02210F84
 * address:  0x02210F84
 * packet:   pkt_02210F84
 * region:   ov198
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

int func_02210F84(char **p, unsigned int v)
{
    return v < *(u8 *)(*p + 0x22);
}
