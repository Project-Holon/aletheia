/*
 * function: func_021FD0F4
 * address:  0x021FD0F4
 * packet:   pkt_021FD0F4
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
 * Tail call into func_0204B3B4 with the pointer held at +0xd08.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B3B4(u32 v);

void func_021FD0F4(u8 *p)
{
    func_0204B3B4(*(u32 *)(p + 0xd08));
}
