/*
 * function: func_021D5EFC
 * address:  0x021D5EFC
 * packet:   pkt_021D5EFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021D53DC  0x021D53DC  thumb  ov093
 *
 * blocker: target 0x021D53DC is unlabelled in ov093 and in all 11 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */

void func_021D53DC(char *);

void func_021D5EFC(char *p)
{
    func_021D53DC(p + 0xfc);
}
