/*
 * function: func_021BE89C
 * address:  0x021BE89C
 * packet:   pkt_ov021_021BE89C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013FD8  0x02013FD8  thumb
 *   func_021BEA9C  0x021BEA9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern u8 func_02013FD8(u32 id);
extern u32 func_021BEA9C(int row, int col);
int func_021BE89C(int a, u32 b)
{
    return func_021BEA9C(func_02013FD8(a), func_02013FD8(b));
}
