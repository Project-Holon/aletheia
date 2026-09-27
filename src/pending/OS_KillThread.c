/*
 * function: OS_KillThread
 * address:  0x0200AD9C
 * packet:   pkt_0200AD9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   OS_GetThreadPriority        0x020173EC  thumb
 *   OS_KillThreadWithPriority   0x02082D44  arm
 */

extern int OS_GetThreadPriority(void *);
extern void OS_KillThreadWithPriority(void *, void *, unsigned int);

asm void OS_KillThread(void)
{
    push {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl OS_GetThreadPriority
    mov r2, r0
    mov r0, r5
    mov r1, r4
    blx OS_KillThreadWithPriority
    pop {r3, r4, r5, pc}
}
