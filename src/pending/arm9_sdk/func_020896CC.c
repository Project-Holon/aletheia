/*
 * function: func_020896CC
 * address:  0x020896CC
 * packet:   pkt_020896CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PushCommand_impl 0x02089804 arm
 *
 * snd_interface.o SND_InvalidateBankData.
 */

extern void PushCommand_impl(void);

asm void func_020896CC(void)
{
    stmfd sp!, {r3, lr}
    mov r2, r1
    mov r3, #0
    mov r1, r0
    mov r0, #31
    str r3, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
