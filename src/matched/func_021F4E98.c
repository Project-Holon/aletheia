/*
 * function: func_021F4E98
 * address:  0x021F4E98
 * packet:   pkt_021F4E98
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
 * Store two words into the object at +0x28 and +0x2c.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_021F4E98(u8 *p, u32 a, u32 b)
{
    *(u32 *)(p + 0x28) = a;
    *(u32 *)(p + 0x2c) = b;
}
