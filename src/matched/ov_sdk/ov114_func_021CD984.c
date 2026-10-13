/*
 * function: CRYPTOi__bn_mul_add_words
 * address:  0x021CD984
 * packet:   pkt_ov114_021CD984
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  rp += ap * w over num words, returns the carry word.
 * crypto_bobj2.o is hand-written ARM (adcs/umlal carry chains no C reaches),
 * so this is an asm body.
 */

/* hand-written in the original: unrolled umlal loop with conditional loads, an OpenSSL bn_asm style routine */
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
