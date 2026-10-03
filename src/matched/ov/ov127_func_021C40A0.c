/*
 * function: func_021C40A0
 * address:  0x021C40A0
 * packet:   pkt_021C40A0
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4494  0x021C4494  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C4494(u8 *p, u32 a, u32 heap);

void func_021C40A0(u8 *p, int a, int b, int c)
{
    func_021C4494(p, a, c);
    *(u32 *)(p + 0x2f0) = b;
}
