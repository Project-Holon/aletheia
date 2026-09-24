/*
 * function: func_02201B18
 * address:  0x02201B18
 * packet:   pkt_02201B18
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * Switch on the mode word at +0x18; both arms latch state 0x28.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

void func_02201B18(u8 *p)
{
    switch (*(u32 *)(p + 0x18)) {
    case 1:
        func_021F4EC0(p, 1, 0);
        *(u32 *)(p + 0x28) = 0x28;
        break;
    case 2:
        func_021F4EC0(p, 2, 3);
        *(u32 *)(p + 0x28) = 0x28;
        break;
    }
}
