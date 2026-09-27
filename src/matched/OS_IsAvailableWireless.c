/*
 * function: OS_IsAvailableWireless
 * address:  0x02087DC4
 * packet:   pkt_02087DC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_027312D0 0x027312D0 arm twl
 */

extern void OS_IsRunOnTwl(void);
extern void func_027312D0(void);

asm void OS_IsAvailableWireless(void)
{
    stmfd sp!, {r3, lr}
    bl OS_IsRunOnTwl
    cmp r0, #0
    moveq r0, #1
    ldmeqfd sp!, {r3, pc}
    bl func_027312D0
    ldmfd sp!, {r3, pc}
}
