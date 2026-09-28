/*
 * function: func_020894B4
 * address:  0x020894B4
 * packet:   pkt_020894B4
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
 * snd_interface.o SND_StartTimer.
 */

extern void PushCommand_impl(void);

asm void func_020894B4(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    mov ip, r2
    str r3, [sp]
    mov r1, r0
    mov r2, lr
    mov r3, ip
    mov r0, #12
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
