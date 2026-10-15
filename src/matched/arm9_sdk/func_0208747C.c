/*
 * function: OSi_AlarmHandler
 * address:  0x0208747C
 * packet:   pkt_0208747C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OSi_ArrangeTimer    0x0208748C  arm
*/

extern void OSi_ArrangeTimer(void);

/* hand-written in the original: OSi_AlarmHandler (os_alarm.o). C was tried: mwccarm always makes the call a tail call (ldr ip,=f; bx ip) at -O2/-O4, and with -O0 or a non-tail call it pads the stack with r3 (push {r3,lr}) and returns with pop {r3,pc}. It never pads with r0 or returns with ldmia + bx lr. The only other code with the {r0,lr} pad is SDK asm (OS_SaveContext, OS_LoadContext, OSi_GetAndDisplayContext). */
asm void OSi_AlarmHandler(void)
{
    stmdb	sp!, {r0, lr}
    bl	OSi_ArrangeTimer
    ldmia	sp!, {r0, lr}
    bx	lr
}
