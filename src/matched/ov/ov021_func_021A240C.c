/*
 * function: func_021A240C
 * address:  0x021A240C
 * packet:   pkt_ov021_021A240C
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
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 */

int func_021A03B8(int a);

int func_021A240C(int *p)
{
    return func_021A03B8(p[4]);
}
