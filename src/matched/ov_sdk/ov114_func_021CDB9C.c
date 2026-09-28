/*
 * function: CRYPTOi__bn_sub_words
 * address:  0x021CDB9C
 * packet:   pkt_ov114_021CDB9C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  r = a - b over n words,
 * returns the final borrow.  crypto_bobj2.o is hand-written ARM (its
 * bn_add_words neighbour is an adcs chain no C reaches), so this is an asm
 * body.  Last labelled function in ov114: the real extent is 64 bytes, the
 * listing's 7620-byte extent is the string/data tail after it.
 */

asm unsigned long CRYPTOi__bn_sub_words(unsigned long *r, const unsigned long *a, const unsigned long *b, int n)
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
