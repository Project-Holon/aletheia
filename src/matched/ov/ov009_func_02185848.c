/*
 * function: func_02185848
 * address:  0x02185848
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
 *   func_020923B0  0xfunc_020923B0  arm
 */

typedef unsigned int u32;

extern void *func_020923B0(void *p, int c, u32 n);

void *func_02185848(void *p, int c, u32 n)
{
    return func_020923B0(p, c, n);
}
