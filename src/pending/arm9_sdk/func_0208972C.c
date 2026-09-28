/*
 * function: func_0208972C
 * address:  0x0208972C
 * packet:   pkt_0208972C
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
 * snd_interface.o SND_SetOutputSelector.
 */

extern void PushCommand_impl(void);

asm void func_0208972C(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    mov ip, r2
    str r3, [sp]
    mov r1, r0
    mov r2, lr
    mov r3, ip
    mov r0, #25
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
