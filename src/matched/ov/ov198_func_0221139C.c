/*
 * function: func_0221139C
 * address:  0x0221139C
 * packet:   pkt_0221139C
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0221139C(u8 *a, u8 *b, unsigned int c)
{
    int lo = c & 1;

    *a = (u8)(lo << 4);
    *b = (u8)(lo + (c >> 1) * 6);
}
