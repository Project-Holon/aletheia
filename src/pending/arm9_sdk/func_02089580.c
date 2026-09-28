/*
 * function: func_02089580
 * address:  0x02089580
 * packet:   pkt_02089580
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
 * snd_interface.o SND_SetTrackMute.
 */

extern void PushCommand_impl(void);

asm void func_02089580(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    cmp r2, #0
    mov r3, #3
    mov ip, #0
    mov r1, r0
    moveq r3, #0
    mov r2, lr
    mov r0, #8
    str ip, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
