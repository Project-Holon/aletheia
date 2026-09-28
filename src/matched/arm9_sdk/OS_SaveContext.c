/*
 * function: OS_SaveContext
 * address:  0x02085C08
 * packet:   pkt_02085C08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_context.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source.  BOOL OS_SaveContext(OSContext *context):
 * saves the CP (divider/sqrt) context at +0x48 first, then CPSR and r0-r14.
 *
 * symbols:
 *   CP_SaveContext  0x020775B8  arm
 */

extern void CP_SaveContext(void);

asm void OS_SaveContext(void)
{
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =CP_SaveContext
    blx r1
    ldmfd sp!, {r0, lr}
    add r1, r0, #0
    mrs r2, cpsr
    str r2, [r1], #4
    mov r0, #0xd3
    msr cpsr_c, r0
    str sp, [r1, #0x40]
    msr cpsr_c, r2
    mov r0, #1
    stmia r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr}
    add r0, pc, #8
    str r0, [r1, #0x3c]
    mov r0, #0
    bx lr
}
