/*
 * function: func_02089660
 * address:  0x02089660
 * packet:   pkt_02089660
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
 * snd_interface.o SND_SetupChannelPcm.
 */

extern void PushCommand_impl(void);

asm void func_02089660(void)
{
    stmfd sp!, {r3, r4, r5, lr}
    ldr ip, [sp, #28]
    lsl r1, r1, #24
    orr r4, r1, r3, lsl #26
    ldr r5, [sp, #36]
    lsl r1, ip, #22
    ldr r3, [sp, #24]
    ldr ip, [sp, #16]
    orr r4, r4, r5, lsl #16
    orr r4, ip, r4
    ldr lr, [sp, #32]
    orr r3, r1, r3, lsl #24
    ldr ip, [sp, #20]
    orr r1, r0, lr, lsl #16
    orr r3, ip, r3
    mov r0, #14
    str r4, [sp]
    bl PushCommand_impl
    ldmfd sp!, {r3, r4, r5, pc}
}
