/*
 * function: func_021A21E0
 * address:  0x021A21E0
 * packet:   pkt_ov021_021A21E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   func_021A27B8  0x021A27B8  thumb  ov021
 */

typedef unsigned int u32;

int func_021A2BC4(u32 a);
void func_021A27B8(u32 x, u32 *p);

void func_021A21E0(u32 *p)
{
    if (func_021A2BC4((u32)p) != 0)
        func_021A27B8(p[0], p);
}
