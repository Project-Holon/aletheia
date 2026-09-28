/*
 * function: func_02201DF0
 * address:  0x02201DF0
 * packet:   pkt_02201DF0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * Set the mode pair and latch state 0x28.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_02201DF0(u8 *p)
{
    func_021F4EC0(p, 0x9, 0x9);
    *(u32 *)(p + 0x28) = 0x28;
    return 2;
}
