/*
 * function: MI_CpuCopy8
 * address:  0x02082D44
 * packet:   pkt_02082D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source.  void MI_CpuCopy8(const void *srcp,
 * void *dstp, u32 size).
 */

asm void MI_CpuCopy8(void)
{
    cmp r2, #0
    bxeq lr
    tst r1, #1
    beq @_dst_aligned
    ldrh ip, [r1, #-1]
    and ip, ip, #0xff
    tst r0, #1
    ldrneh r3, [r0, #-1]
    movne r3, r3, lsr #8
    ldreqh r3, [r0]
    orr r3, ip, r3, lsl #8
    strh r3, [r1, #-1]
    add r0, r0, #1
    add r1, r1, #1
    subs r2, r2, #1
    bxeq lr
@_dst_aligned:
    eor ip, r1, r0
    tst ip, #1
    beq @_same_parity
    bic r0, r0, #1
    ldrh ip, [r0], #2
    mov r3, ip, lsr #8
    subs r2, r2, #2
    blo @_odd_tail
@_odd_loop:
    ldrh ip, [r0], #2
    orr ip, r3, ip, lsl #8
    strh ip, [r1], #2
    mov r3, ip, lsr #16
    subs r2, r2, #2
    bhs @_odd_loop
@_odd_tail:
    tst r2, #1
    bxeq lr
    ldrh ip, [r1]
    and ip, ip, #0xff00
    orr ip, ip, r3
    strh ip, [r1]
    bx lr
@_same_parity:
    tst ip, #2
    beq @_word
    bics r3, r2, #1
    beq @_last
    sub r2, r2, r3
    add ip, r3, r1
@_half_loop:
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    cmp r1, ip
    blo @_half_loop
    b @_last
@_word:
    cmp r2, #2
    blo @_last
    tst r1, #2
    beq @_word2
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    subs r2, r2, #2
    bxeq lr
@_word2:
    bics r3, r2, #3
    beq @_half
    sub r2, r2, r3
    add ip, r3, r1
@_word_loop:
    ldr r3, [r0], #4
    str r3, [r1], #4
    cmp r1, ip
    blo @_word_loop
@_half:
    tst r2, #2
    ldrneh r3, [r0], #2
    strneh r3, [r1], #2
@_last:
    tst r2, #1
    bxeq lr
    ldrh r2, [r1]
    ldrh r0, [r0]
    and r2, r2, #0xff00
    and r0, r0, #0xff
    orr r0, r2, r0
    strh r0, [r1]
    bx lr
}
