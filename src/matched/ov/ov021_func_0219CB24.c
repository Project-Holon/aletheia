/*
 * function: func_0219CB24
 * address:  0x0219CB24
 * packet:   pkt_ov021_0219CB24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219D3F0  0x0219D3F0  thumb  ov021
 *   func_0219CA40  0x0219CA40  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern void func_0219CA40(u8 *, u32, u32, u32);

void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1)
{
    int r = -1;
    u32 t;
    if (s1 & 2) r = 2;
    t = func_0219D3F0((int *)o, b, c, s0, a, r);
    func_0219CA40(o + 0x14, b, t, (u16)s1);
}
