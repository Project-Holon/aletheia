/*
 * function: func_02195B20
 * address:  0x02195B20
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
 *   func_02198020  0xfunc_02198020  arm
 */

extern void func_02198020(void);

void func_02195B20(void)
{
    func_02198020();
}
