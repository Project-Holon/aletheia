/*
 * function: func_02193FE8
 * address:  0x02193FE8
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
 *   func_0217EF50  0xfunc_0217EF50  arm
 */

extern void func_0217EF50(void);

void func_02193FE8(void)
{
    func_0217EF50();
}
