/*
 * function: CRYPTOi__bn_div_words
 * address:  0x021CDAE8
 * packet:   pkt_ov114_021CDAE8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(crypto_bobj2.o).  ((h:l) / d) through the
 * runtime's 64-bit unsigned divide (_ll_divmod_entry_flag0), returned as a
 * u64 with a zero high word.  Asm body like the rest of crypto_bobj2.o: the
 * nearest C, (u32)((((u64)h << 32) | l) / d) as a u64 return, is 9 bytes
 * off: orr #0 for the moves and push {r3, lr} where the image saves r4.
 */
extern void _ll_udiv(void);

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
