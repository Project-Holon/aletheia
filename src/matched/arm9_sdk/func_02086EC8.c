/*
 * function: OSi_SetExContext
 * address:  0x02086EC8
 * packet:   pkt_02086EC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_SetExContext (os_exception.o)
 * asm:      needs mrs/msr on CPSR/SPSR and reads the exception frame through
 *           r12 outside the ABI; the object agrees: .debug_line gives each
 *           instruction its own increasing line (376..449).
 *
 * symbols:
 *   OSi_ExContext  0x021512BC  data
 */

extern unsigned long OSi_ExContext[28];

asm void OSi_SetExContext(void)
{
    ldr     r1, =OSi_ExContext
    str     r0, [r1, #0x6c]
    ldr     r0, [r12, #0]
    str     r0, [r1, #4]
    ldr     r0, [r12, #4]
    str     r0, [r1, #8]
    ldr     r0, [r12, #8]
    str     r0, [r1, #0xc]
    ldr     r0, [r12, #0xc]
    str     r0, [r1, #0x10]
    ldr     r2, [r12, #0x10]
    bic     r2, r2, #1
    add     r0, r1, #0x14
    stmia   r0, {r4-r11}
    ldr     r0, [r2, #0]
    str     r0, [r1, #0x64]
    ldr     r3, [r2, #4]
    str     r3, [r1, #0]
    ldr     r0, [r2, #8]
    str     r0, [r1, #0x34]
    ldr     r0, [r2, #0xc]
    str     r0, [r1, #0x40]
    mrs     r0, cpsr
    orr     r3, r3, #0x80
    bic     r3, r3, #0x20
    msr     cpsr_fsxc, r3
    str     sp, [r1, #0x38]
    str     lr, [r1, #0x3c]
    mrs     r2, spsr
    msr     cpsr_fsxc, r0
    bx      lr
}
