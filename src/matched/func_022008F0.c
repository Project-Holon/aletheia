/*
 * function: func_022008F0
 * address:  0x022008F0
 * packet:   pkt_022008F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135
 *
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02202840(u8 *p);

int func_022008F0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        *(u32 *)(p + 0x28) = *(u32 *)(p + 0x2c);
    }
    return 2;
}
