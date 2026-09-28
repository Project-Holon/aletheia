/*
 * function: OS_IsForceDisableWireless
 * address:  0x02087E84
 * packet:   pkt_02087E84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_027312F8 0x027312F8 arm twl
 */

extern void OS_IsRunOnTwl(void);
extern void func_027312F8(void);

asm void OS_IsForceDisableWireless(void)
{
    stmfd sp!, {r3, lr}
    bl OS_IsRunOnTwl
    cmp r0, #0
    moveq r0, #0
    ldmeqfd sp!, {r3, pc}
    bl func_027312F8
    ldmfd sp!, {r3, pc}
}
