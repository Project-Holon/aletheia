/*
 * function: func_021FC224
 * address:  0x021FC224
 * packet:   pkt_021FC224
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Extent runs long: 0x021FC230 is an unlabelled follower leaf (a plain
 * `p[0x3e] = v` setter), so this is EXACT*.
 *
 * symbols:
 *   func_021FC394  0x021FC394  thumb  ov186
 */

extern int func_021FC394(int);

int func_021FC224(char *p)
{
    return func_021FC394(*(int *)(p + 0xf8));
}
