/*
 * function: func_021A35A0
 * address:  0x021A35A0
 * packet:   pkt_ov021_021A35A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A5768  0x021A5768  thumb  ov021
 */

typedef unsigned int u32;

int func_02188CFC(u32 x);
int func_021A5768(u32 a, u32 b);

void func_021A35A0(u32 *p, int a)
{
    if (func_02188CFC(p[0]) == 0)
        func_021A5768(p[2], a);
}
