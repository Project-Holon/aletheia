/*
 * function: CRYPTOi__bn_sqr_words
 * address:  0x021CDAC0
 * packet:   pkt_ov114_021CDAC0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  r[2i..2i+1] = a[i] squared over n words.
 * crypto_bobj2.o is hand-written ARM (adcs/umlal carry chains no C reaches),
 * so this is an asm body.
 */

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
