/*
 * function: func_021C0E3C
 * address:  0x021C0E3C
 * packet:   pkt_021C0E3C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0E98  0x021C0E98  thumb  ov217
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021C0E98(u8 *a0);
extern void func_020307B0(void *);

void func_021C0E3C(void *p)
{
    func_021C0E98(p);
    func_020307B0(p);
}
