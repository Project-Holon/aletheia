/*
 * function: func_0217F124
 * address:  0x0217F124
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
 *   func_020964F4  0xfunc_020964F4  arm
 */

extern void func_020964F4(void);

void func_0217F124(void)
{
    func_020964F4();
}
