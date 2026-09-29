/*
 * function: func_021A2400
 * address:  0x021A2400
 * packet:   pkt_ov021_021A2400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 *
 * symbols:
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 */

int func_021A03A4(int a);

int func_021A2400(int *p)
{
    return func_021A03A4(p[4]);
}
