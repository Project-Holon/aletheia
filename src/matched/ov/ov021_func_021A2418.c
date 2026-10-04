/*
 * function: func_021A2418
 * address:  0x021A2418
 * packet:   pkt_ov021_021A2418
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
 *   func_021A2418  0x021A2418  thumb  ov021
 *   func_021A03CC  0x021A03CC  thumb  ov021
 */

int func_021A03CC(int *p);

int func_021A2418(int *p)
{
    return func_021A03CC((int *)p[4]);
}
