/*
 * function: func_02194940
 * address:  0x02194940
 * packet:   pkt_02194B70
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
 *   func_02194B70  0x02194B70  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194B70(u16 *p, int i);

void func_02194940(u8 *p, int i)
{
    func_02194B70((u16 *)(p + 0x18 + i * 100), i);
}
