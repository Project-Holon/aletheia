/*
 * function: func_021BCF00
 * address:  0x021BCF00
 * packet:   pkt_ov210_021BCF00
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Meeting-room / map index helper: halfword lookup into the table at
 * 0x021C072E by the second argument.  Blocker target of func_021BEA54.
 *
 * symbols:
 *   d_021C072E  0x021C072E  data  ov210  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern u16 d_021C072E[];

u16 func_021BCF00(int a0, int a1)
{
    (void)a0;
    return d_021C072E[a1];
}
