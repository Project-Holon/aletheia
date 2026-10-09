/*
 * file:     unit_0217F2BC.c
 * function: func_0217F2BC
 * address:  0x0217F2BC
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
 *   func_02085A38  0xfunc_02085A38  arm
 */

extern void func_02085A38(unsigned int msec);

void func_0217F2BC(unsigned int msec)
{
    func_02085A38(msec);
}
