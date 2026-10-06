/*
 * function: func_020834C0
 * address:  0x020834C0
 * packet:   pkt_020834C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_UncompressLZ8 (libmi.TWL.HYB.a mi_uncompress.o)
 * asm:      swpb (byte swap store) has no C spelling; DWARF subprogram has no variables.
 *
 * void MI_UncompressLZ8(const void *srcp, void *destp).
 */

asm void func_020834C0(void)
{
    stmfd sp!, {r4, r5, r6, r7, lr}
    ldr r5, [r0], #4
    mov r2, r5, lsr #8
    mov r7, #0
    tst r5, #0xf
    movne r7, #1
@_loop:
    cmp r2, #0
    ble @_exit
    ldrb lr, [r0], #1
    mov r4, #8
@_flagloop:
    subs r4, r4, #1
    blt @_loop
    tst lr, #0x80
    bne @_ref
    ldrb r6, [r0], #1
    swpb r6, r6, [r1]
    add r1, r1, #1
    sub r2, r2, #1
    b @_next
@_ref:
    ldrb r5, [r0]
    cmp r7, #0
    moveq r6, #3
    beq @_short
    tst r5, #0xe0
    movne r6, #1
    bne @_short
    add r0, r0, #1
    and r6, r5, #0xf
    mov r6, r6, lsl #4
    tst r5, #0x10
    beq @_mid
    mov r6, r6, lsl #8
    ldrb r5, [r0], #1
    add r6, r6, r5, lsl #4
    add r6, r6, #0x100
@_mid:
    add r6, r6, #0x11
    ldrb r5, [r0]
@_short:
    add r3, r6, r5, asr #4
    add r0, r0, #1
    and r5, r5, #0xf
    mov r12, r5, lsl #8
    ldrb r6, [r0], #1
    orr r5, r6, r12
    add r12, r5, #1
    sub r2, r2, r3
@_copy:
    ldrb r5, [r1, -r12]
    swpb r5, r5, [r1]
    add r1, r1, #1
    subs r3, r3, #1
    bgt @_copy
@_next:
    cmp r2, #0
    movgt lr, lr, lsl #1
    bgt @_flagloop
    b @_loop
@_exit:
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}
