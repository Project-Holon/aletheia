/*
 * file:     unit_02090ED8.c
 * function: NWM_CheckInitialized
 * address:  0x02090ED8
 * packet:   pkt_02090ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_02702698 0x02702698 arm twl
 */

extern void OS_IsRunOnTwl(void);
typedef unsigned int   u32;
extern u32 func_02702698(void);

asm void NWM_CheckInitialized(void)
{
    stmfd sp!, {r3, lr}
    bl OS_IsRunOnTwl
    cmp r0, #0
    moveq r0, #3
    ldmeqfd sp!, {r3, pc}
    bl func_02702698
    ldmfd sp!, {r3, pc}
}
