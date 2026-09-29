/*
 * function: func_021B785C
 * address:  0x021B785C
 * packet:   pkt_ov021_021B785C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub after func_021B7834; called by func_021B6BDC.
 *
 * symbols:
 *   func_0200A13C  0x0200A13C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_0200A13C(u8 *p, u32 i);

void func_021B785C(u8 *p, u32 i)
{
    func_0200A13C(p, i);
}
