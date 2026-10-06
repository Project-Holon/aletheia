/*
 * function: func_021A1680
 * address:  0x021A1680
 * packet:   pkt_ov021_021A1680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
u32 func_021A1780(u8 *p);
void func_021A1750(u8 *p);

void func_021A1680(u8 *p)
{
    if (func_021A1780(p + 0x20) != 0)
        func_021A1750(p + 0x20);
}
