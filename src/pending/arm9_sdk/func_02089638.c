/*
 * function: func_02089638
 * address:  0x02089638
 * packet:   pkt_02089638
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
 * snd_interface.o SND_SetChannelVolume.
 */

extern void PushCommand_impl(void);

asm void func_02089638(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    mov r3, r2
    mov ip, #0
    mov r1, r0
    mov r2, lr
    mov r0, #20
    str ip, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
