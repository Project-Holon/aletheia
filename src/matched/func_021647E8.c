/*
 * function: func_021647E8
 * address:  0x021647E8
 * packet:   pkt_021647E8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216481C  0x0216481C  thumb
 *
 * Tail call to func_0216481C through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the
 * listing: no prologue, and its only caller is func_0202C794 in arm9.
 */

extern void func_0216481C(void *arg);

void func_021647E8(void *arg)
{
    func_0216481C(arg);
}
