/*
 * function: func_0217F124
 * address:  0x0217F124
 * packet:   pkt_0217F124
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x020964F4 now has an
 * EXACT arm9 shard entry (pkt_020964F4) reproducing the defaulting thunk, so
 * the ABS32 site resolves via `matched`.  Verified EXACT.
 *
 * symbols:
 *   func_020964F4  0x020964F4  arm
 */

extern void func_020964F4(void);

void func_0217F124(void)
{
    func_020964F4();
}
