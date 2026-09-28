/*
 * function: CRYPTOi__bn_add_words
 * address:  0x021CDB08
 * packet:   pkt_ov114_021CDB08
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  r = a + b over n words, returns the final carry.
 * crypto_bobj2.o is hand-written ARM (adcs/umlal carry chains no C reaches),
 * so this is an asm body.
 */

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
