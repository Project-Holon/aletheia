/*
 * function: func_021E3744
 * address:  0x021E3744
 * packet:   pkt_ov119_021E3744
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E8168 0x021E8168 data a4
 */

typedef unsigned int u32;

extern u32 d_021E8168[];

void func_021E3744(int n)
{
    *(u32 *)0x04000488 = d_021E8168[n];
}
