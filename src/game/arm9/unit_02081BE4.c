/*
 * file:     unit_02081BE4.c
 * function: MATH_QSort
 * address:  0x02081BE4
 * packet:   pkt_02081BE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libmath qsort.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor object (clz, swp/swpb, a stack that grows by a
 * computed amount).  void MATH_QSort(void *head, u32 num, u32 width,
 * s32 (*comp)(void *, void *), void *stackBuf): a non-recursive quicksort
 * over an explicit stack of (lo, hi) pairs, allocated on the machine stack
 * when stackBuf is NULL (8 bytes per bit of num).  Elements are exchanged
 * with swp words when width is a multiple of 4, else with swpb bytes.
 */

/* hand-written in the original: clz, swp/swpb and a stack grown by a computed amount */
asm void MATH_QSort(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    cmp r1, #1
    ble @_2081E64
    ldr r4, [sp, #0x24]
    mov r11, r3
    mov r8, r2
    cmp r4, #0
    bne @_2081C1C
    clz r2, r1
    rsb r2, r2, #0x20
    mov r2, r2, lsl #3
    sub sp, sp, r2
    mov r4, sp
    str r2, [sp, #-4]!
@_2081C1C:
    sub r1, r1, #1
    mla r1, r1, r8, r0
    mov r5, r4
    str r0, [r4], #4
    str r1, [r4], #4
    clz r2, r8
    rsb r2, r2, #0x20
    str r2, [sp, #-4]!
@_2081C3C:
    cmp r4, r5
    beq @_2081E4C
    ldr r7, [r4, #-4]
    ldr r6, [r4, #-8]!
    sub r2, r7, r6
    cmp r2, r8
    bne @_2081CB0
    mov r0, r6
    mov r1, r7
    blx r11
    cmp r0, #0
    ble @_2081C3C
    mov r0, r8
    tst r0, #3
    beq @_2081C94
@_2081C78:
    ldrb r1, [r6]
    subs r0, r0, #1
    swpb r1, r1, [r7]
    add r7, r7, #1
    strb r1, [r6], #1
    bne @_2081C78
    b @_2081C3C
@_2081C94:
    ldr r1, [r6]
    subs r0, r0, #4
    swp r1, r1, [r7]
    add r7, r7, #4
    str r1, [r6], #4
    bne @_2081C94
    b @_2081C3C
@_2081CB0:
    ldr r3, [sp]
    sub r2, r7, r6
    mov r2, r2, lsr r3
    mla r2, r2, r8, r6
    mov r3, r6
    mov r0, r8
    mov r2, r2
    tst r0, #3
    beq @_2081CF0
@_2081CD4:
    ldrb r1, [r2]
    subs r0, r0, #1
    swpb r1, r1, [r3]
    add r3, r3, #1
    strb r1, [r2], #1
    bne @_2081CD4
    b @_2081D08
@_2081CF0:
    ldr r1, [r2]
    subs r0, r0, #4
    swp r1, r1, [r3]
    add r3, r3, #4
    str r1, [r2], #4
    bne @_2081CF0
@_2081D08:
    mov r9, r6
    mov r10, r7
    add r9, r9, r8
@_2081D14:
    cmp r9, r7
    bge @_2081D34
    mov r1, r6
    mov r0, r9
    blx r11
    cmp r0, #0
    addlt r9, r9, r8
    blt @_2081D14
@_2081D34:
    mov r1, r6
    mov r0, r10
    blx r11
    cmp r0, #0
    subgt r10, r10, r8
    bgt @_2081D34
    cmp r9, r10
    bge @_2081DAC
    mov r2, r9
    mov r3, r10
    mov r0, r8
    tst r0, #3
    beq @_2081D84
@_2081D68:
    ldrb r1, [r2]
    subs r0, r0, #1
    swpb r1, r1, [r3]
    add r3, r3, #1
    strb r1, [r2], #1
    bne @_2081D68
    b @_2081D9C
@_2081D84:
    ldr r1, [r2]
    subs r0, r0, #4
    swp r1, r1, [r3]
    add r3, r3, #4
    str r1, [r2], #4
    bne @_2081D84
@_2081D9C:
    add r9, r9, r8
    sub r10, r10, r8
    cmp r9, r10
    ble @_2081D14
@_2081DAC:
    mov r2, r6
    mov r3, r10
    mov r0, r8
    tst r0, #3
    beq @_2081DDC
@_2081DC0:
    ldrb r1, [r2]
    subs r0, r0, #1
    swpb r1, r1, [r3]
    add r3, r3, #1
    strb r1, [r2], #1
    bne @_2081DC0
    b @_2081DF4
@_2081DDC:
    ldr r1, [r2]
    subs r0, r0, #4
    swp r1, r1, [r3]
    add r3, r3, #4
    str r1, [r2], #4
    bne @_2081DDC
@_2081DF4:
    sub r2, r10, r6
    sub r3, r7, r10
    cmp r2, r3
    ble @_2081E28
    sub r2, r10, r8
    cmp r6, r2
    strlt r6, [r4], #4
    strlt r2, [r4], #4
    add r2, r10, r8
    cmp r2, r7
    strlt r2, [r4], #4
    strlt r7, [r4], #4
    b @_2081C3C
@_2081E28:
    add r2, r10, r8
    cmp r2, r7
    strlt r2, [r4], #4
    strlt r7, [r4], #4
    sub r2, r10, r8
    cmp r6, r2
    strlt r6, [r4], #4
    strlt r2, [r4], #4
    b @_2081C3C
@_2081E4C:
    add sp, sp, #4
    sub r4, r4, #4
    cmp r4, sp
    ldreq r0, [sp]
    addeq r0, r0, #4
    addeq sp, sp, r0
@_2081E64:
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}
