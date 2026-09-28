/*
 * function: func_02195B20
 * address:  0x02195B20
 * packet:   pkt_ov009_02195B20
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
 * Unblocked by matching the 8-byte ARM leaf at 0x02198020 in ov009 (its
 * listing emits it as a .word run, unlabelled); the ABS32 site now resolves
 * via `matched`.  Packet renamed from pkt_02155168 so this promotion does
 * not rewrite that packet's shard.
 *
 * symbols:
 *   func_02198020  0x02198020  arm
 */

extern void func_02198020(void);

void func_02195B20(void)
{
    func_02198020();
}
