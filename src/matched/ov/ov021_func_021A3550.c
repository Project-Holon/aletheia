/*
 * function: func_021A3550
 * address:  0x021A3550
 * packet:   pkt_ov021_021A3550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A5738  0x021A5738  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 func_02188CFC(u8 *p);
void func_021A5738(u32 x, int a);

void func_021A3550(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5738(p[2], a);
}
