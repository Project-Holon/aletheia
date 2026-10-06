/*
 * function: MI_CpuCopy
 * address:  0x02082EA4
 * packet:   pkt_02082EA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor object.  void MI_CpuCopy(const void *srcp,
 * void *destp, u32 size): a forward copy of any alignment.  Up to 8 bytes
 * go through a computed jump into a byte ladder; longer copies align the
 * destination and move 32-byte ldm/stm blocks, shifting the source words
 * into place when the two alignments differ.
 */

asm void MI_CpuCopy(void)
{
    cmp r2, #8
    bgt @_2082EFC
    rsb r3, r2, #8
    add pc, pc, r3, lsl #3
    mov r0, r0
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    bx lr
@_2082EFC:
    tst r0, #1
    subne r2, r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r0, #2
    subne r2, r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    and r3, r1, #3
    bic r1, r1, #3
    cmp r3, #0
    beq @_2082F48
    cmp r3, #1
    beq @_2082F84
    cmp r3, #2
    beq @_208301C
    b @_20830B4
@_2082F48:
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2082F50:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2082F50
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2082F6C:
    ldrge r3, [r0], #4
    strge r3, [r1], #4
    subges r2, r2, #4
    bge @_2082F6C
    add r2, r2, #4
    b @_208314C
@_2082F84:
    ldr ip, [r1]
    mov ip, ip, lsl #0x18
    mov ip, ip, lsr #0x18
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2082F98:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x18
    orrge r4, ip, r4, lsl #8
    movge ip, r5, lsr #0x18
    orrge r5, r3, r5, lsl #8
    movge r3, r6, lsr #0x18
    orrge r6, ip, r6, lsl #8
    movge ip, r7, lsr #0x18
    orrge r7, r3, r7, lsl #8
    movge r3, r8, lsr #0x18
    orrge r8, ip, r8, lsl #8
    movge ip, r9, lsr #0x18
    orrge r9, r3, r9, lsl #8
    movge r3, r10, lsr #0x18
    orrge r10, ip, r10, lsl #8
    movge ip, lr, lsr #0x18
    orrge lr, r3, lr, lsl #8
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2082F98
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2082FF4:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #8
    strge ip, [r1], #4
    movge ip, r3, lsr #0x18
    subges r2, r2, #4
    bge @_2082FF4
    add r2, r2, #4
    sub r0, r0, #1
    add r2, r2, #1
    b @_208314C
@_208301C:
    ldr ip, [r1]
    mov ip, ip, lsl #0x10
    mov ip, ip, lsr #0x10
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2083030:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x10
    orrge r4, ip, r4, lsl #16
    movge ip, r5, lsr #0x10
    orrge r5, r3, r5, lsl #16
    movge r3, r6, lsr #0x10
    orrge r6, ip, r6, lsl #16
    movge ip, r7, lsr #0x10
    orrge r7, r3, r7, lsl #16
    movge r3, r8, lsr #0x10
    orrge r8, ip, r8, lsl #16
    movge ip, r9, lsr #0x10
    orrge r9, r3, r9, lsl #16
    movge r3, r10, lsr #0x10
    orrge r10, ip, r10, lsl #16
    movge ip, lr, lsr #0x10
    orrge lr, r3, lr, lsl #16
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2083030
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_208308C:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #16
    strge ip, [r1], #4
    movge ip, r3, lsr #0x10
    subges r2, r2, #4
    bge @_208308C
    add r2, r2, #4
    sub r0, r0, #2
    add r2, r2, #2
    b @_208314C
@_20830B4:
    ldr ip, [r1]
    mov ip, ip, lsl #8
    mov ip, ip, lsr #8
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20830C8:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #8
    orrge r4, ip, r4, lsl #24
    movge ip, r5, lsr #8
    orrge r5, r3, r5, lsl #24
    movge r3, r6, lsr #8
    orrge r6, ip, r6, lsl #24
    movge ip, r7, lsr #8
    orrge r7, r3, r7, lsl #24
    movge r3, r8, lsr #8
    orrge r8, ip, r8, lsl #24
    movge ip, r9, lsr #8
    orrge r9, r3, r9, lsl #24
    movge r3, r10, lsr #8
    orrge r10, ip, r10, lsl #24
    movge ip, lr, lsr #8
    orrge lr, r3, lr, lsl #24
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20830C8
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083124:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #24
    strge ip, [r1], #4
    movge ip, r3, lsr #8
    subges r2, r2, #4
    bge @_2083124
    add r2, r2, #4
    sub r0, r0, #3
    add r2, r2, #3
    b @_208314C
@_208314C:
    tst r2, #4
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    bx lr
}
