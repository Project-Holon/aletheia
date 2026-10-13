/*
 * function: msleep
 * address:  0x0217F2BC
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
 *   OS_Sleep  0x02085A38  arm  arm9
 *   OS_Sleep  0xfunc_02085A38  arm
 */

extern void OS_Sleep(unsigned int msec);

void msleep(unsigned int msec)
{
    OS_Sleep(msec);
}
