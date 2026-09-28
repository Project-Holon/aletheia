/*
 * function: func_021C4078
 * address:  0x021C4078
 * packet:   pkt_021C4078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with minus one.
 *
 * symbols:
 *   func_02005728  0x02005728  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005728(int v);

void func_021C4078(void)
{
    func_02005728(-1);
}
