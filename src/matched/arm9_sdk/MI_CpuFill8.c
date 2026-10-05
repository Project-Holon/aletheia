/*
 * function: MI_CpuFill8
 * address:  0x02082BCC
 * packet:   pkt_02082BCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source, like its neighbours MIi_CpuCopy16 and
 * MIi_CpuClear16.  void MI_CpuFill8(void *dstp, u8 data, u32 size).
 */

asm void MI_CpuFill8(void)
{
    cmp r2, #0
    bxeq lr
    tst r0, #1
    beq @_aligned
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    bxeq lr
@_aligned:
    cmp r2, #2
    blo @_tail
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq @_word
    strh r1, [r0], #2
    subs r2, r2, #2
    bxeq lr
@_word:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq @_half
    sub r2, r2, r3
    add ip, r3, r0
@_loop:
    str r1, [r0], #4
    cmp r0, ip
    blo @_loop
@_half:
    tst r2, #2
    strneh r1, [r0], #2
@_tail:
    tst r2, #1
    bxeq lr
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}
