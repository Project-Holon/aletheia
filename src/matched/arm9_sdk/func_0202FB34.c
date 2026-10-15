/*
 * function: CRYPTO_RC4Encrypt
 * address:  0x0202FB34
 * packet:   pkt_0202FB34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTO_RC4Encrypt (libcrypto.TWL.HYB.a rc4s-arm4cw.o)
 * asm:      rc4s-arm4cw.o is an asm-only object: its STT_FILE symbol names rc4s-arm4cw.s, it has no .comment and no DWARF, and CRYPTO_RC4Encrypt is its only symbol (120 bytes, identical to the image).
 * notes:    no DWARF; from the register use the arguments are (context, in, length, out). The state indices i and j are kept in the top byte of r7 and r6, so the +1 on i wraps at 256 by overflow.
 *
 * symbols:
 *   (none)
 */

asm void CRYPTO_RC4Encrypt(void)
{
    stmfd sp!, {r4-r9, lr}
    ldrb r7, [r0]
    ldrb r6, [r0, #1]
    add r0, r0, #4
    mov lr, #0x1000000
    add r7, lr, r7, lsl #24
    mov r6, r6, lsl #24
    ldrb r9, [r0, r7, lsr #24]
    subs r2, r2, #1
    bmi @_202FB94
@_202FB5C:
    add r6, r6, r9, lsl #24
    subs r2, r2, #1
    ldrb r8, [r0, r6, lsr #24]
    ldrb r5, [r1], #1
    strb r8, [r0, r7, lsr #24]
    strb r9, [r0, r6, lsr #24]
    add r4, r9, r8
    and r4, r4, #0xff
    add r7, r7, lr
    ldrb r4, [r0, r4]
    ldrb r9, [r0, r7, lsr #24]
    eor r5, r5, r4
    strb r5, [r3], #1
    bge @_202FB5C
@_202FB94:
    sub r7, r7, lr
    mov r7, r7, lsr #24
    mov r6, r6, lsr #24
    strb r7, [r0, #-4]
    strb r6, [r0, #-3]
    ldmfd sp!, {r4-r9, pc}
}
