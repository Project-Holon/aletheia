/*
 * function: CRYPTOi__bn_mul_words
 * address:  0x021CDA38
 * packet:   pkt_ov114_021CDA38
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  rp = ap * w over num words, returns the carry word.
 * crypto_bobj2.o is hand-written ARM (adcs/umlal carry chains no C reaches),
 * so this is an asm body.
 */

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
