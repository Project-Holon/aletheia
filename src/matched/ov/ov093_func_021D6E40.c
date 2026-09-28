/*
 * function: func_021D6E40
 * address:  0x021D6E40
 * packet:   pkt_ov093_021D6E40
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

void func_021D6E40(u8 *p, u8 a, u16 b)
{
    p[0x1F6] = a;
    *(u16 *)(p + 0x1F4) = b;
}
