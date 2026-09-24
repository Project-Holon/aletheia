/*
 * function: func_022013E4
 * address:  0x022013E4
 * packet:   pkt_022013E4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220251C  0x0220251C  thumb  ov135

 * Move 0x80 bytes between the +0xe4 and +0x10ec sub-objects, latch state 7 and publish the 8/0xa pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C86B8(u8 *dst, u8 *src, u32 n);
extern void func_0220251C(u8 *p, u32 a, u32 b);

int func_022013E4(u8 *p)
{
    func_021C86B8(p + 0xe4, p + 0x10ec, 0x80);
    *(u32 *)(p + 0x28) = 7;
    *(u32 *)(p + 0xf8c) = 0;
    func_0220251C(p, 8, 0xa);
    return 2;
}
