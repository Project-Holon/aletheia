/*
 * file:     crypto_bobj2.c
 * unit:     yes
 * function: CRYPTOi__bn_mul_add_words, CRYPTOi__bn_mul_words, CRYPTOi__bn_sqr_words, CRYPTOi__bn_div_words, CRYPTOi__bn_add_words, CRYPTOi__bn_sub_words
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
#include "crypto_types.h"

extern void _ll_udiv(void);
asm BN_ULONG CRYPTOi__bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
asm BN_ULONG CRYPTOi__bn_mul_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
asm void CRYPTOi__bn_sqr_words(BN_ULONG *r, const BN_ULONG *a, int n);
asm unsigned long long CRYPTOi__bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d);
asm BN_ULONG CRYPTOi__bn_add_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n);
asm BN_ULONG CRYPTOi__bn_sub_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n);

/* hand-written in the original: unrolled umlal multiply-accumulate loop with conditional loads (OpenSSL bn_asm style routine) */
asm BN_ULONG CRYPTOi__bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w)
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

/* hand-written in the original: unrolled umull/umlal carry chains in a prebuilt assembly object */
asm BN_ULONG CRYPTOi__bn_mul_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w)
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

/* hand-written in the original: unrolled umull carry chains in a prebuilt assembly object */
asm void CRYPTOi__bn_sqr_words(BN_ULONG *r, const BN_ULONG *a, int n)
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


/*
 * hand-written in the original: the vendor object libcrypto.TWL.HYB.a
 * (crypto_bobj2.o) names its source file crypto_bobj2.s, an assembly file
 * that holds all six bn_*_words routines. The OpenSSL BN_LLONG C
 * (((BN_ULLONG)h << BN_BITS2 | l) / d, with a 64-bit return) gives the same
 * 32 bytes with orr rX, r0, #0 and r3 in place of mov and r4 (9 bytes differ),
 * on every mwccarm version and -O level here.
 */
asm unsigned long long CRYPTOi__bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d)
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

/* hand-written in the original: unrolled adcs carry chains in a prebuilt assembly object */
asm BN_ULONG CRYPTOi__bn_add_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n)
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

/* hand-written in the original: r = a - b over n words, returns the final borrow */
asm BN_ULONG CRYPTOi__bn_sub_words(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b, int n)
{
    stmfd sp!, {r4, r5, r6, r7, lr}
    mov r7, r0
    subs r3, r3, #1
    mov r0, #0
    ldmltfd sp!, {r4, r5, r6, r7, pc}
    mov lr, #0
_loop:
    ldr r5, [r2], #4
    ldr r6, [r1], #4
    adds r5, r5, r0
    adc r0, lr, #0
    subs r6, r6, r5
    movlo r0, #1
    subs r3, r3, #1
    str r6, [r7], #4
    bge _loop
    ldmfd sp!, {r4, r5, r6, r7, pc}
}
