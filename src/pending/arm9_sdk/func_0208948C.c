/*
 * function: func_0208948C
 * address:  0x0208948C
 * packet:   pkt_0208948C
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
 * snd_interface.o SND_SetTrackAllocatableChannel.
 */

extern void PushCommand_impl(void);

asm void func_0208948C(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    mov r3, r2
    mov ip, #0
    mov r1, r0
    mov r2, lr
    mov r0, #9
    str ip, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
