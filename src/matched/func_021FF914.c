/*
 * function: func_021FF914
 * address:  0x021FF914
 * packet:   pkt_021FF914
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Tail call into func_0204B878 with the object at +0xd0c and a u16 value.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u32 func_0204B878(u32 obj, u16 v);

void func_021FF914(u32 *p, u32 v)
{
    func_0204B878(*(u32 *)(p[2] + 0xd0c), (u16)v);
}
