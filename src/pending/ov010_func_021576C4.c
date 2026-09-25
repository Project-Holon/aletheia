/*
 * function: func_021576C4
 * address:  0x021576C4
 * packet:   pkt_021576C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_021576B8  0x021576B8  thumb
 *
 * blocker: target 0x021576B8 is labelled in both ov009 and ov010, ambiguous,
 *          no outside witness. Extent reads 12 (unlabelled bx lr follower at
 *          0x021576CC), compiled 8.
 */

void func_021576B8(void);

void func_021576C4(void)
{
    func_021576B8();
}
