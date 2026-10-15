/*
 * function: OSi_ExceptionHandler
 * address:  0x02086E40
 * packet:   pkt_02086E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_ExceptionHandler (os_exception.o)
 * asm:      exception-vector entry with no prologue: uses r12 and a private
 *           stack outside the ABI and needs mrs on CPSR; the object agrees:
 *           .debug_line gives each instruction its own increasing line (285..332).
 *
 * symbols:
 *   OSi_GetAndDisplayContext  0x02086EB4  arm
 *   g_02151290                0x02151290  data
 */

extern unsigned long g_02151290[3];
extern void OSi_GetAndDisplayContext(void);

asm void OSi_ExceptionHandler(void)
{
    ldr     r12, =g_02151290
    ldr     r12, [r12, #0]
    cmp     r12, #0
    movne   lr, pc
    bxne    r12
    ldr     r12, =0x02000000
    stmdb   r12!, {r0-r3, sp, lr}
    and     r0, sp, #1
    mov     sp, r12
    mrs     r1, cpsr
    and     r1, r1, #0x1f
    teq     r1, #0x17
    bne     _1
    bl      OSi_GetAndDisplayContext
    b       _2
_1:
    teq     r1, #0x1b
    bne     _2
    bl      OSi_GetAndDisplayContext
_2:
    ldr     r12, =g_02151290
    ldr     r12, [r12, #0]
    cmp     r12, #0
_3:
    beq     _3
_4:
    mov     r0, r0
    b       _4
    ldmia   sp!, {r0-r3, r12, lr}
    mov     sp, r12
    bx      lr
}
