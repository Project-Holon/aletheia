/*
 * function: func_021F3708
 * address:  0x021F3708
 * packet:   pkt_021F3708
 * region:   ov049
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     archived here under this lane's recursive MATCH-unblock pass;
 *           the annotated header contract for this file has no `packet:`
 *           field (four callers under src/pending resurrected it), so it is
 *           not spliced and no shard is emitted for it.  The 02188D2C
 *           call site resolves via the ov021 `matched` witness.
 *
 * Two-call wrapper.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
*/

void func_021F3708(void)
{
    void func_02188D2C(void);
    void func_021BE580(void);
    func_02188D2C();
    func_021BE580();
}
