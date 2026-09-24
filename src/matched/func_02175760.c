/*
 * function: func_02175760
 * address:  0x02175760
 * packet:   pkt_02155168
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
 * symbols:
 *   func_0216B804  0xfunc_0216B804  arm
 */

extern void func_0216B804(void);

void func_02175760(void)
{
    func_0216B804();
}
