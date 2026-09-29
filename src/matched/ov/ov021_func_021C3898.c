/*
 * function: func_021C3898
 * address:  0x021C3898
 * packet:   pkt_ov021_021C3898
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C38F4  0x021C38F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012944(u32);
extern u32 func_0200BC2C(u32, int);
extern void func_021C38F4(u16, u32, u32, u32, u32, u32);

void func_021C3898(u32 *p, u32 c)
{
    u32 a = func_02012944(func_020120F4(func_02188C80(p[1])));
    u32 b = func_0200BC2C(p[2], 0);
    u32 d = func_0200BC2C(p[2], 1);

    func_021C38F4(*(u16 *)p, a, 0xEA62, b, d, c);
}
