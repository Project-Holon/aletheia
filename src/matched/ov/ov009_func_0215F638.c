/*
 * function: SOC_Shutdown
 * address:  0x0215F638
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
 * This is SOC_Shutdown(s, how): SOCL_Shutdown reads only s, but every
 * caller sets how (mov r1, #2 in ov114 and ov125), so it stays.
 *
 * symbols:
 *   func_0215E6B8  0xfunc_0215E6B8  arm
 */

extern int func_0215E6B8(int s);

int SOC_Shutdown(int s, int how)
{
    return func_0215E6B8(s);
}
