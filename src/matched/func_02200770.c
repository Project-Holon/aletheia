/*
 * function: func_02200770
 * address:  0x02200770
 * packet:   pkt_02200770
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FF9E0  0x021FF9E0  thumb  ov135

 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FF9E0(u8 *p);

int func_02200770(u8 *p)
{
    func_021FF9E0(p);
    *(u32 *)(p + 0x28) = 8;
    *(u16 *)(p + 0xe18) = 0;
    return 2;
}
