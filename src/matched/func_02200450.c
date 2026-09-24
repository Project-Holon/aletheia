/*
 * function: func_02200450
 * address:  0x02200450
 * packet:   pkt_02200450
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_020434DC(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_02200450(u8 *p)
{
    if (*(u16 *)(p + 0xe18) != 0) {
        func_020434DC(1, 0);
        func_020434DC(2, 0);
        func_020434DC(4, 0);
        func_021F4EC0(p, 7, 0xb);
        *(u32 *)(p + 0x18) = 1;
        *(u32 *)(p + 0x28) = 9;
    }
    return 2;
}
