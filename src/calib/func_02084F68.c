/*
 * function: OS_VSPrintf
 * address:  0x02084F68
 * packet:   pkt_02084F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084FA8   0x02084FA8  arm
 *
 * A sixteen-byte argument-shuffling tail call: the incoming (r0, r1, r2)
 * become (r0, 0x7FFFFFFF, r1, r2) for func_02084FA8, which is reached
 * through a pool word and `bx ip` -- this front end's ARM tail call shape
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), the same eight bytes
 * its sibling at 0x02086D98 has.  The 0x7FFFFFFF is materialised as
 * `mvn r1, #0x80000000`, which is how Thumb's counterpart spells it too.
 *
 * It is the only callee of the variadic func_02084F44 at 0x02084F40, so
 * matching it is what makes that one promotable: the `label` class refuses
 * a call site whose only witness is inside the compared range, and the
 * `matched` class is then the only witness left.
 */

extern void func_02084FA8(void *a0, int a1, int a2, int a3);

void OS_VSPrintf(void *a0, int a1, int a2)
{
    func_02084FA8(a0, 0x7fffffff, a1, a2);
}
