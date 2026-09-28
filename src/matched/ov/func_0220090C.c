/*
 * function: func_0220090C
 * address:  0x0220090C
 * packet:   pkt_0220090C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135

 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_02202840(u8 *p);

int func_0220090C(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++*(s32 *)(p + 0xdfc) > 0x2d) {
            *(s32 *)(p + 0xdfc) = 0;
            *(u32 *)(p + 0x28) = *(u32 *)(p + 0x2c);
        }
    }
    return 2;
}
