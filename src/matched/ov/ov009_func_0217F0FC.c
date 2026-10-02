/*
 * function: func_0217F0FC
 * address:  0x0217F0FC
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
 *   func_02086004  0xfunc_02086004  arm
 */

extern void func_02086004(void *mutex);

void func_0217F0FC(void *mutex)
{
    func_02086004(mutex);
}
