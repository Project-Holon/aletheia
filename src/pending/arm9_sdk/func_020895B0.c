/*
 * function: func_020895B0
 * address:  0x020895B0
 * packet:   pkt_020895B0
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
 * snd_interface.o SND_SetTrackMuteEx.
 */

extern void PushCommand_impl(void);

asm void func_020895B0(void)
{
    stmfd sp!, {r3, lr}
    mov lr, r1
    mov r3, r2
    mov ip, #0
    mov r1, r0
    mov r2, lr
    mov r0, #8
    str ip, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
