/*
 * function: func_0219492C
 * address:  0x0219492C
 * packet:   pkt_0219492C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object and a strided element address.
 *
 * symbols:
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194B3C(u8 *p, u8 *e);

void func_0219492C(u8 *p, int i)
{
    func_02194B3C(p, p + 0x18 + i * 100);
}
