/*
 * function: func_021FF174
 * address:  0x021FF174
 * packet:   pkt_021FF174
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_020221A4(u32 v);

int func_021FF174(u8 *p)
{
    u32 v = *(u32 *)(p + 0xd3c) - 1;

    *(u32 *)(p + 0xd3c) = v;
    if (func_020221A4(v) != 0) {
        *(u32 *)(p + 0xd3c) = 0;
        *(u32 *)(p + 0x28) = 1;
    }
    return 2;
}
