/*
 * function: OS_LoadContext
 * address:  0x02085C54
 * packet:   pkt_02085C54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_context.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source.  void OS_LoadContext(OSContext *context):
 * restores the CP context, then CPSR (through SPSR) and r0-r14, and on TWL
 * waits for the divider (REG_DIVCNT 0x04000280 busy bit) before returning.
 *
 * symbols:
 *   CPi_RestoreContext  0x020775F8  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 */

extern void CPi_RestoreContext(void);
extern int OS_IsRunOnTwl(void);

asm void OS_LoadContext(void)
{
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =CPi_RestoreContext
    blx r1
    ldmfd sp!, {r0, lr}
    mrs r1, cpsr
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr cpsr_c, r1
    ldr r1, [r0], #4
    msr spsr_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr}^
    mov r0, r0
    stmfd sp!, {r0, r1, r2, r3, r12, lr}
    bl OS_IsRunOnTwl
    beq @_done
    ldr r0, =0x04000280
@_wait:
    ldr r1, [r0]
    ands r1, r1, #0x8000
    bne @_wait
@_done:
    ldmfd sp!, {r0, r1, r2, r3, r12, lr}
    subs pc, lr, #4
}
