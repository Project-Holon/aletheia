/*
 * function: func_021FEB50
 * address:  0x021FEB50
 * packet:   pkt_021FEB50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

int func_021FEB50(u8 *p)
{
    if (*(u32 *)(p + 0xd3c) == 0) {
        func_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    *(u32 *)(p + 0x28) = 0;
    return 3;
}
