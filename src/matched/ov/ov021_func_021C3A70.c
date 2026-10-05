/*
 * function: func_021C3A70
 * address:  0x021C3A70
 * packet:   pkt_021C3A70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

void func_021C3A70(u32 *p)
{
    u32 t = p[0];

    p[0] = p[1];
    p[1] = t;
}
