/*
 * file:     mi_memory_2.c
 * function: MI_CpuMove
 * address:  0x02083194
 * packet:   pkt_02083194
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor object.  void MI_CpuMove(const void *srcp,
 * void *destp, u32 size): an overlapping-safe copy.  A forward move is
 * handed to MI_CpuCopy; a backward one copies from the end, by a computed
 * jump into a byte ladder for up to 8 bytes, otherwise by 32-byte ldm/stm
 * blocks with the source realigned to the destination's byte offset.
 *
 * symbols:
 *   MI_CpuCopy  0x02082EA4  arm
 */

extern void MI_CpuCopy(const void *srcp, void *destp, unsigned long size);

asm void MI_CpuMove(void)
{
    cmp r2, #0
    subnes r3, r0, r1
    bxeq lr
    bgt MI_CpuCopy
    add r1, r1, r2
    add r0, r0, r2
    cmp r2, #8
    bgt @_2083204
    rsb r3, r2, #8
    add pc, pc, r3, lsl #3
    mov r0, r0
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    bx lr
@_2083204:
    tst r0, #2
    subne r2, r2, #2
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r0, #1
    subne r2, r2, #1
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    and r3, r1, #3
    bic r1, r1, #3
    cmp r3, #0
    beq @_2083250
    cmp r3, #1
    beq @_208328C
    cmp r3, #2
    beq @_2083328
    b @_20833C4
@_2083250:
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2083258:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    stmgedb r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2083258
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083274:
    ldrge r3, [r0, #-4]!
    strge r3, [r1, #-4]!
    subges r2, r2, #4
    bge @_2083274
    add r2, r2, #4
    b @_2083460
@_208328C:
    ldr ip, [r1]
    mov ip, ip, lsr #8
    mov ip, ip, lsl #8
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20832A0:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #8
    orrge lr, ip, lr, lsr #24
    movge ip, r10, lsl #8
    orrge r10, r3, r10, lsr #24
    movge r3, r9, lsl #8
    orrge r9, ip, r9, lsr #24
    movge ip, r8, lsl #8
    orrge r8, r3, r8, lsr #24
    movge r3, r7, lsl #8
    orrge r7, ip, r7, lsr #24
    movge ip, r6, lsl #8
    orrge r6, r3, r6, lsr #24
    movge r3, r5, lsl #8
    orrge r5, ip, r5, lsr #24
    movge ip, r4, lsl #8
    orrge r4, r3, r4, lsr #24
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20832A0
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_20832FC:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #24
    strge ip, [r1], #-4
    movge ip, r3, lsl #8
    subges r2, r2, #4
    bge @_20832FC
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #3
    add r2, r2, #3
    b @_2083460
@_2083328:
    ldr ip, [r1]
    mov ip, ip, lsr #0x10
    mov ip, ip, lsl #0x10
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_208333C:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #0x10
    orrge lr, ip, lr, lsr #16
    movge ip, r10, lsl #0x10
    orrge r10, r3, r10, lsr #16
    movge r3, r9, lsl #0x10
    orrge r9, ip, r9, lsr #16
    movge ip, r8, lsl #0x10
    orrge r8, r3, r8, lsr #16
    movge r3, r7, lsl #0x10
    orrge r7, ip, r7, lsr #16
    movge ip, r6, lsl #0x10
    orrge r6, r3, r6, lsr #16
    movge r3, r5, lsl #0x10
    orrge r5, ip, r5, lsr #16
    movge ip, r4, lsl #0x10
    orrge r4, r3, r4, lsr #16
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_208333C
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083398:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #16
    strge ip, [r1], #-4
    movge ip, r3, lsl #0x10
    subges r2, r2, #4
    bge @_2083398
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #2
    add r2, r2, #2
    b @_2083460
@_20833C4:
    ldr ip, [r1]
    mov ip, ip, lsr #0x18
    mov ip, ip, lsl #0x18
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20833D8:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #0x18
    orrge lr, ip, lr, lsr #8
    movge ip, r10, lsl #0x18
    orrge r10, r3, r10, lsr #8
    movge r3, r9, lsl #0x18
    orrge r9, ip, r9, lsr #8
    movge ip, r8, lsl #0x18
    orrge r8, r3, r8, lsr #8
    movge r3, r7, lsl #0x18
    orrge r7, ip, r7, lsr #8
    movge ip, r6, lsl #0x18
    orrge r6, r3, r6, lsr #8
    movge r3, r5, lsl #0x18
    orrge r5, ip, r5, lsr #8
    movge ip, r4, lsl #0x18
    orrge r4, r3, r4, lsr #8
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20833D8
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083434:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #8
    strge ip, [r1], #-4
    movge ip, r3, lsl #0x18
    subges r2, r2, #4
    bge @_2083434
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #1
    add r2, r2, #1
    b @_2083460
@_2083460:
    tst r2, #4
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r2, #2
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r2, #1
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    bx lr
}
