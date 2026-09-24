/*
 * function: func_021FF65C
 * address:  0x021FF65C
 * packet:   pkt_021FF65C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * Answer 2, or set the 5/mode pair and answer 3 when the +0x12f4 word is clear.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

u32 func_021FF65C(u8 *p)
{
    u32 r = 2;

    if (*(u32 *)(p + 0x12f4) == 0) {
        func_021F4EC0(p, 5, *(u32 *)(p + 0x20));
        r = 3;
    }
    return r;
}
