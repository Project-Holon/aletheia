/*
 * function: func_021576C4
 * address:  0x021576C4
 * packet:   pkt_021576C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021576B8  0x021576B8  thumb  ov010
 *
 * Unblocked by matching func_021576B8 (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`. EXACT*: the listing extent is 12 bytes because of the
 * unlabelled bx lr follower at 0x021576CC (invisible to disasm.py, which only
 * auto-labels a prologue that saves lr); compiled 8, every compared byte equal.
 */

void func_021576B8(void);

void func_021576C4(void)
{
    func_021576B8();
}
