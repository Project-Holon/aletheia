/*
 * function: func_02089774
 * address:  0x02089774
 * packet:   pkt_02089774
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
 * snd_interface.o SND_ResetMasterPan.
 */

extern void PushCommand_impl(void);

asm void func_02089774(void)
{
    stmfd sp!, {r3, lr}
    mov r2, #0
    mov r0, #24
    mov r3, r2
    sub r1, r0, #25
    str r2, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
