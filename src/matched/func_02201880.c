/*
 * function: func_02201880
 * address:  0x02201880
 * packet:   pkt_02201880
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C887C(u8 *p);

int func_02201880(u8 *p)
{
    func_021C887C(p + 0xe4);
    *(u32 *)(p + 0x28) = 0x1d;
    *(u32 *)(p + 0xf8c) = 0x0;
    return 0x2;
}
