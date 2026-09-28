/*
 * function: func_021F89A8
 * address:  0x021F89A8
 * packet:   pkt_021F89A8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_021F89A8(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    *(u16 *)(q + 4) = a;
    *(u16 *)(q + 0x18) = b;
}
