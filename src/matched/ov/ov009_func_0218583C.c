/*
 * function: func_0218583C
 * address:  0x0218583C
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
 *   func_02092344  0xfunc_02092344  arm
 */

extern void *func_02092344(void *dest, const void *src, unsigned int n);

void *func_0218583C(void *dest, const void *src, unsigned int n)
{
    return func_02092344(dest, src, n);
}
