/*
 * file:     unit_021CD984.c
 * unit:     yes
 * function: func_021CD984, func_021CDA38, func_021CDAC0, func_021CDAE8, func_021CDB08
 * address:  0x021CD984
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 */
extern void _ll_udiv(void);
asm unsigned long CRYPTOi__bn_mul_add_words(unsigned long *rp, const unsigned long *ap, int num, unsigned long w);
asm unsigned long CRYPTOi__bn_mul_words(unsigned long *rp, const unsigned long *ap, int num, unsigned long w);
asm void CRYPTOi__bn_sqr_words(unsigned long *r, const unsigned long *a, int n);
asm unsigned long long CRYPTOi__bn_div_words(unsigned long h, unsigned long l, unsigned long d);
asm unsigned long CRYPTOi__bn_add_words(unsigned long *r, const unsigned long *a, const unsigned long *b, int n);

asm unsigned long CRYPTOi__bn_mul_add_words(unsigned long *rp, const unsigned long *ap, int num, unsigned long w)
{
    stmfd sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov lr, #0
    mov r0, #0
    subs r2, r2, #4
    blt _L21CDA0C
    ldr r7, [r8]
    ldr r6, [r1], #4
_L21CD9A4:
    adds r7, r7, r0
    adc r0, lr, #0
    umlal r7, r0, r3, r6
    ldr r5, [r8, #4]
    ldr r4, [r1], #4
    str r7, [r8], #4
    adds r5, r5, r0
    adc r0, lr, #0
    umlal r5, r0, r3, r4
    ldr r7, [r8, #4]
    ldr r6, [r1], #4
    str r5, [r8], #4
    adds r7, r7, r0
    adc r0, lr, #0
    umlal r7, r0, r3, r6
    ldr r5, [r8, #4]
    ldr r4, [r1], #4
    str r7, [r8], #4
    adds r5, r5, r0
    adc r0, lr, #0
    umlal r5, r0, r3, r4
    subs r2, r2, #4
    ldrge r7, [r8, #4]
    ldrge r6, [r1], #4
    str r5, [r8], #4
    bge _L21CD9A4
_L21CDA0C:
    adds r2, r2, #4
    ldmlefd sp!, {r4, r5, r6, r7, r8, pc}
_L21CDA14:
    ldr r7, [r8], #0
    ldr r6, [r1], #4
    adds r7, r7, r0
    adc r0, lr, #0
    umlal r7, r0, r3, r6
    subs r2, r2, #1
    str r7, [r8], #4
    bgt _L21CDA14
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}

asm unsigned long CRYPTOi__bn_mul_words(unsigned long *rp, const unsigned long *ap, int num, unsigned long w)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, r0
    mov r0, #0
    subs r2, r2, #4
    blt _L21CDA98
_L21CDA4C:
    ldr r9, [r1], #4
    umull r9, r10, r3, r9
    ldr r7, [r1], #4
    ldr r5, [r1], #4
    umull r7, r8, r3, r7
    ldr lr, [r1], #4
    adds r9, r9, r0
    umull r5, r6, r3, r5
    adcs r7, r7, r10
    str r9, [r11], #4
    umull lr, r4, r3, lr
    str r7, [r11], #4
    adcs r5, r5, r8
    str r5, [r11], #4
    adcs lr, lr, r6
    adc r0, r4, #0
    str lr, [r11], #4
    subs r2, r2, #4
    bge _L21CDA4C
_L21CDA98:
    adds r2, r2, #4
    ldmlefd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
_L21CDAA0:
    ldr r9, [r1], #4
    mov r10, #0
    umlal r0, r10, r9, r3
    subs r2, r2, #1
    str r0, [r11], #4
    mov r0, r10
    bgt _L21CDAA0
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}

asm void CRYPTOi__bn_sqr_words(unsigned long *r, const unsigned long *a, int n)
{
    stmfd sp!, {r4, r5, lr}
    subs r2, r2, #1
    ldmltfd sp!, {r4, r5, pc}
_L21CDACC:
    ldr lr, [r1], #4
    umull r4, r5, lr, lr
    subs r2, r2, #1
    str r4, [r0], #4
    str r5, [r0], #4
    bge _L21CDACC
    ldmfd sp!, {r4, r5, pc}
}


asm unsigned long long CRYPTOi__bn_div_words(unsigned long h, unsigned long l, unsigned long d)
{
    stmfd sp!, {r4, lr}
    mov r4, r0
    mov r0, r1
    mov r1, r4
    mov r3, #0
    bl _ll_udiv
    mov r1, #0
    ldmfd sp!, {r4, pc}
}

asm unsigned long CRYPTOi__bn_add_words(unsigned long *r, const unsigned long *a, const unsigned long *b, int n)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    subs r3, r3, #4
    mov r0, #0
    mov lr, #0
    blt _L21CDB70
_L21CDB20:
    ldr r8, [r1], #4
    ldr r6, [r2], #4
    subs r0, r0, #1
    ldr r7, [r1], #4
    ldr r5, [r2], #4
    adcs r8, r8, r6
    adcs r7, r7, r5
    str r8, [r9], #4
    str r7, [r9], #4
    ldr r8, [r1], #4
    ldr r6, [r2], #4
    ldr r7, [r1], #4
    ldr r5, [r2], #4
    adcs r8, r8, r6
    adcs r7, r7, r5
    adc r0, lr, #0
    str r8, [r9], #4
    subs r3, r3, #4
    str r7, [r9], #4
    bge _L21CDB20
_L21CDB70:
    adds r3, r3, #4
    ldmlefd sp!, {r4, r5, r6, r7, r8, r9, pc}
_L21CDB78:
    ldr r8, [r1], #4
    ldr r6, [r2], #4
    subs r0, r0, #1
    adcs r8, r8, r6
    adc r0, lr, #0
    str r8, [r9], #4
    subs r3, r3, #1
    bgt _L21CDB78
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, pc}
}
