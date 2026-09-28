/*
 * function: func_0215F644
 * address:  0x0215F644
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
 *   func_0215E84C  0xfunc_0215E84C  arm
 */

extern void func_0215E84C(void);

void func_0215F644(void)
{
    func_0215E84C();
}
