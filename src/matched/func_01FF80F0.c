/*
 * function: func_01FF80F0
 * address:  0x01FF80F0
 * packet:   pkt_01FF80F0
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   d_02FE0020     0x02FE0020  data
 *   func_01FF8148  0x01FF8148  arm
 */

extern void *d_02FE0020[32];
extern void func_01FF8148(void);

asm void func_01FF80F0(void)
{
    stmdb   sp!, {lr}
    mov     ip, #0x4000000
    add     ip, ip, #0x210
    ldr     r1, [ip, #-8]
    cmp     r1, #0
    ldmeqfd sp!, {pc}
    ldmia   ip, {r1, r2}
    ands    r1, r1, r2
    ldmeqfd sp!, {pc}
    mov     r3, #0x80000000
@loop:
    clz     r0, r1
    bics    r1, r1, r3, lsr r0
    bne     @loop
    mov     r1, r3, lsr r0
    str     r1, [ip, #4]
    rsbs    r0, r0, #0x1f
    ldr     r1, =d_02FE0020
    ldr     r0, [r1, r0, lsl #2]
    ldr     lr, =func_01FF8148
    bx      r0
}
