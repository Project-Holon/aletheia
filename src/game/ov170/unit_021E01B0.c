/*
 * file:     unit_021E01B0.c
 * function: func_021E01B0
 * address:  0x021E01B0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EF400  0x021EF400  thumb  ov170
 *
 * Boolean of the state test.
 */



extern int func_021EF400(unsigned char *p);
int func_021E01B0(unsigned char *p)
{
    return func_021EF400(p) != 0;
}
