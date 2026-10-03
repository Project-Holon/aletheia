/*
 * function: func_021FC638
 * address:  0x021FC638
 * packet:   pkt_021FC638
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4BF8  0x021F4BF8  thumb  ov135
 *   func_021F5060  0x021F5060  thumb  ov135
 *   func_021F5034  0x021F5034  thumb  ov135

 * Build, kick the two fixed helpers and latch state 6.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);
extern void func_021F5060(void);
extern void func_021F5034(u32 v);

int func_021FC638(u8 *p)
{
    func_021F4BF8(p, 0x14, 0x16a, 8, 2, 1);
    func_021F5060();
    func_021F5034(1);
    *(u32 *)(p + 0x28) = 6;
    return 2;
}
