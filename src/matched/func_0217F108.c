/*
 * function: func_0217F108
 * address:  0x0217F108
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
 *   func_02086028  0xfunc_02086028  arm
 */

extern void func_02086028(void);

void func_0217F108(void)
{
    func_02086028();
}
