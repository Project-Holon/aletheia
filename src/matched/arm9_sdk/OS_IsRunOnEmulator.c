/*
 * function: OS_IsRunOnEmulator
 * address:  0x02085D24
 * packet:   pkt_02085D24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085CBC 0x02085CBC arm
 */

extern void func_02085CBC(void);

asm void OS_IsRunOnEmulator(void)
{
    stmfd sp!, {r3, lr}
    bl func_02085CBC
    tst	r0, #0x10000000
    movne	r0, #1
    moveq	r0, #0
    ldmfd sp!, {r3, pc}
}
