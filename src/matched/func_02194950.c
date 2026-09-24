/*
 * function: func_02194950
 * address:  0x02194950
 * packet:   pkt_02194B78
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
 *   func_02194B78  0x02194B78  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194B78(u8 *e, int i);

void func_02194950(u8 *p, int i)
{
    func_02194B78(p + 0x18 + i * 100, i);
}
