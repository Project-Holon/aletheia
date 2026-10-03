/*
 * function: func_02200118
 * address:  0x02200118
 * packet:   pkt_02200118
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_020403F4  0x020403F4  arm

 *
 * Poke channels 2, 1 and 0 in that order.
 */

typedef unsigned int   u32;
extern void sub_020403F4(u32 i);

void func_02200118(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}
