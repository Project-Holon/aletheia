/*
 * function: func_02089618
 * address:  0x02089618
 * packet:   pkt_02089618
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
 * snd_interface.o SND_SetChannelTimer.
 */

extern void PushCommand_impl(void);

asm void func_02089618(void)
{
    stmfd sp!, {r3, lr}
    mov r2, r1
    mov r3, #0
    mov r1, r0
    mov r0, #19
    str r3, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
