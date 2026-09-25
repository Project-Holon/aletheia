/*
 * function: func_021C84E0
 * address:  0x021C84E0
 * packet:   pkt_021C84E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021C84F4  0x021C84F4  thumb  ov093
 *
 * blocker: target 0x021C84F4 is unlabelled in ov093 and in all 8 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */

void func_021C84F4(void);

void func_021C84E0(void)
{
    func_021C84F4();
}
