/*
 * file:     unit_02004DF4.c
 * function: MIi_UncompressBLZ
 * address:  0x02004DF4
 * packet:   pkt_02004DF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     same body as TwlSDK crt0.FLX.c MIi_UncompressBackward; the
 *           libmatch signature recovery catalogues 0x02004DF4 as
 *           MIi_UncompressBLZ in TwlSDK/libmi.TWL.HYB.a(mi_secureuncompr).
 */

asm void MIi_UncompressBLZ(void)
{
    cmp r0, #0
    beq _exit
    stmfd sp!, {r4-r8}
    ldmdb r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #24
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2

_loop:
    cmp r3, r1
    ble _end_loop
    ldrb r5, [r3, #-1]!
    mov r6, #8

_loop8:
    subs r6, r6, #1
    blt _loop
    tst r5, #0x80
    bne _blockcopy
    ldrb r0, [r3, #-1]!
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    b _joinhere

_blockcopy:
    ldrb r12, [r3, #-1]!
    ldrb r7, [r3, #-1]!
    orr r7, r7, r12, lsl #8
    bic r7, r7, #0xf000
    add r7, r7, #2
    add r12, r12, #0x20

_patterncopy:
    ldrb r0, [r2, r7]
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    subs r12, r12, #0x10
    bge _patterncopy

_joinhere:
    cmp r3, r1
    mov r5, r5, lsl #1
    bgt _loop8

_end_loop:
    mov r0, #0
    bic r3, r1, #0x1f

_cacheflush:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt _cacheflush
    ldmfd sp!, {r4-r8}

_exit:
    bx lr
}
