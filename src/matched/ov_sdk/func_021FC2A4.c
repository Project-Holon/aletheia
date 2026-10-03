/*
 * function: func_021FC2A4
 * address:  0x021FC2A4
 * packet:   pkt_021FC2A4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020403F4  0x020403F4  arm

 *
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */

typedef unsigned int   u32;
extern void sub_020403F4(u32 i);

void func_021FC2A4(void)
{
    sub_020403F4(0);
    sub_020403F4(1);
    sub_020403F4(2);
    sub_020403F4(3);
}
