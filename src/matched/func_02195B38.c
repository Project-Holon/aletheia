/*
 * function: func_02195B38
 * address:  0x02195B38
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
 *   func_021956F8  0xfunc_021956F8  arm
 */

extern void func_021956F8(void);

void func_02195B38(void)
{
    func_021956F8();
}
