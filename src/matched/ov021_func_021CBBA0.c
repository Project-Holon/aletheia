/*
 * function: func_021CBBA0
 * address:  0x021CBBA0
 * packet:   pkt_ov021_021CBBA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * symbols:
 *   func_0216D63C  0x0216D63C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0216D63C(u32 a, int b);

void func_021CBBA0(u32 a)
{
    func_0216D63C(a, 1);
}
