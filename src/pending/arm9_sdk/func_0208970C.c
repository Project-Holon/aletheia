/*
 * function: func_0208970C
 * address:  0x0208970C
 * packet:   pkt_0208970C
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
 * snd_interface.o SND_SetMasterVolume.
 */

extern void PushCommand_impl(void);

asm void func_0208970C(void)
{
    stmfd sp!, {r3, lr}
    mov r2, #0
    mov r1, r0
    mov r3, r2
    mov r0, #23
    str r2, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
