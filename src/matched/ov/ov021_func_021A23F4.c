/*
 * function: func_021A23F4
 * address:  0x021A23F4
 * packet:   pkt_ov021_021A23F4
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
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A0390  0x021A0390  thumb  ov021
 */

int func_021A0390(int a);

int func_021A23F4(int *p)
{
    return func_021A0390(p[4]);
}
