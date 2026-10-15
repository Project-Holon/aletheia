/*
 * function: gsiInitializeCriticalSection
 * address:  0x0217F0FC
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
 *   OS_InitMutex  0x02086004  arm  arm9
 *   OS_InitMutex  0xfunc_02086004  arm
 */

extern void OS_InitMutex(void *mutex);

void gsiInitializeCriticalSection(void *mutex)
{
    OS_InitMutex(mutex);
}
