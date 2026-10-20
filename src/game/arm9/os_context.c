/*
 * file:     os_context.c
 * unit:     yes
 * function: OS_InitContext, OS_SaveContext, OS_LoadContext
 * address:  0x02085B9C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CP_SaveContext  0x020775B8  arm
 *   CPi_RestoreContext  0x020775F8  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "cp_context.h"
#include "os_emulator.h"
asm void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
asm BOOL OS_SaveContext(OSContext *context);
asm void OS_LoadContext(OSContext *context);

/*
 * sdk:      OS_InitContext (os_context.o)
 * asm:      hand-written in the object: the subprogram has no DW_TAG_variable
 *           and .debug_line gives each of the 27 instructions its own strictly
 *           increasing line (43..78), the asm-function pattern; the C spelling
 *           schedules the stores and uses tst, not ands.
 */
/* hand-written in the original: OS_InitContext, one instruction per source line in the object */
asm void OS_InitContext(OSContext *context, u32 newpc, u32 newsp)
{
    add     r1, r1, #4
    str     r1, [r0, #0x40]
    str     r2, [r0, #0x44]
    sub     r2, r2, #0x40
    tst     r2, #4
    subne   r2, r2, #4
    str     r2, [r0, #0x38]
    ands    r1, r1, #1
    movne   r1, #0x3f
    moveq   r1, #0x1f
    str     r1, [r0]
    mov     r1, #0
    str     r1, [r0, #0x4]
    str     r1, [r0, #0x8]
    str     r1, [r0, #0xc]
    str     r1, [r0, #0x10]
    str     r1, [r0, #0x14]
    str     r1, [r0, #0x18]
    str     r1, [r0, #0x1c]
    str     r1, [r0, #0x20]
    str     r1, [r0, #0x24]
    str     r1, [r0, #0x28]
    str     r1, [r0, #0x2c]
    str     r1, [r0, #0x30]
    str     r1, [r0, #0x34]
    str     r1, [r0, #0x3c]
    bx      lr
}

/* hand-written in the original: stm of the register file and mrs, one SDK line-table row per instruction */
asm BOOL OS_SaveContext(OSContext *context)
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

/* hand-written in the original: ldm of the register file and msr, one SDK line-table row per instruction */
asm void OS_LoadContext(OSContext *context)
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
