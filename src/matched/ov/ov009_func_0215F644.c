/*
 * function: SOC_Close
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
 *   SOCL_Close  0x0215E84C  arm
 *   SOCL_Close  0xfunc_0215E84C  arm
 */

extern int SOCL_Close(int s);

int SOC_Close(int s)
{
    return SOCL_Close(s);
}
