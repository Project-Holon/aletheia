/*
 * function: OS_GetLockID
 * address:  0x02084EB8
 * packet:   pkt_02084EB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_GetLockID (os_spinlock.o)
 * asm:      hand-written in the object: needs clz, the subprogram has no
 *           DW_TAG_variable, and .debug_line gives each instruction its own
 *           strictly increasing line (836..898), the asm-function pattern.
 */

typedef long s32;

asm s32 OS_GetLockID(void)
{
    ldr     r3, =0x02FFFFB0
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    movne   r0, #0x40
    bne     _1
    add     r3, r3, #4
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    ldr     r0, =0xFFFFFFFD
    bxeq    lr
    mov     r0, #0x60
_1:
    add     r0, r0, r2
    mov     r1, #0x80000000
    mov     r1, r1, lsr r2
    ldr     r2, [r3, #0]
    bic     r2, r2, r1
    str     r2, [r3, #0]
    bx      lr
}
