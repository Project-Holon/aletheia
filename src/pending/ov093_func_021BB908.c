/*
 * function: func_021BB908
 * address:  0x021BB908
 * packet:   pkt_021BB908
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021B91E4  0x021B91E4  thumb  ov093
 *
 * blocker: target 0x021B91E4 is unlabelled in ov093 and in all 11 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */

void func_021B91E4(int);

void func_021BB908(int *p)
{
    func_021B91E4(p[3]);
}
