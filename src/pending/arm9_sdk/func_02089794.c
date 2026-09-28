/*
 * function: func_02089794
 * address:  0x02089794
 * packet:   pkt_02089794
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
 * snd_interface.o SND_ReadDriverInfo.
 */

extern void PushCommand_impl(void);

asm void func_02089794(void)
{
    stmfd sp!, {r3, lr}
    mov r2, #0
    mov r1, r0
    mov r3, r2
    mov r0, #33
    str r2, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, pc}
}
