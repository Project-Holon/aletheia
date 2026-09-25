/*
 * function: func_021D77E8
 * address:  0x021D77E8
 * packet:   pkt_021D77E8
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

void func_021D77E8(u8 *p, u8 a, u8 b)
{
    p[0] = 0;
    *(u32 *)(p + 4) = 0;
    p[1] = 0;
    p[2] = a;
    p[3] = b;
}
