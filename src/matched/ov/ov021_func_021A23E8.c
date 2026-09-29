/*
 * function: func_021A23E8
 * address:  0x021A23E8
 * packet:   pkt_ov021_021A23E8
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
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A0380  0x021A0380  thumb  ov021
 */

int func_021A0380(int a);

int func_021A23E8(int *p)
{
    return func_021A0380(p[4]);
}
