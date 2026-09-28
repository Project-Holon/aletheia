/*
 * function: func_020897DC
 * address:  0x020897DC
 * packet:   pkt_020897DC
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
 * snd_interface.o SNDi_SetTrackParam.
 */

extern void PushCommand_impl(void);

asm void func_020897DC(void)
{
    stmfd sp!, {r3, lr}
    ldr ip, [sp, #8]
    mov lr, r2
    str r3, [sp]
    mov r2, r1
    orr r1, r0, ip, lsl #24
    mov r3, lr
    mov r0, #7
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
