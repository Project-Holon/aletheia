/*
 * function: func_02194974
 * address:  0x02194974
 * packet:   pkt_02194A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a strided element address and the index.
 *
 * symbols:
 *   func_02194A84  0x02194A84  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194A84(u8 *e, int i);

void func_02194974(u8 *p, int i)
{
    func_02194A84(p + 0x18 + i * 100, i);
}
