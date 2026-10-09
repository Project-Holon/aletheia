/*
 * file:     unit_02176978.c
 * function: func_02176978
 * address:  0x02176978
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
 *   func_0217603C 0x0217603C arm
 */

extern int func_0217603C(void);

int func_02176978(void)
{
    return func_0217603C();
}
