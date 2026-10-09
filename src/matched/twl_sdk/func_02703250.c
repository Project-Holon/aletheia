/*
 * function: func_02703250
 * address:  0x02703250
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082E74  0x02082E74  arm twl
 */

typedef unsigned int u32;

extern u32 func_02082E74(u32, u32, u32);

asm void func_02703250(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    ldrh r3, [r0]
    add r5, r0, #0x40
    mov r8, r1
    add r0, r5, r3
    mov r7, r2
    sub r6, r0, #0x40
    cmp r8, #0xdd
    movne r0, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    ldrb r0, [r5, #1]
    add r0, r5, r0
    add r0, r0, #2
    cmp r0, r6
    bhi @lbl_027032D8
    mov r4, #4
@lbl_02703290:
    ldrb r0, [r5]
    cmp r0, r8
    bne @lbl_027032B8
    mov r1, r7
    mov r2, r4
    add r0, r5, #2
    bl func_02082E74
    cmp r0, #0
    moveq r0, r5
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_027032B8:
    ldrb r0, [r5, #1]
    add r0, r0, #2
    add r5, r5, r0
    ldrb r0, [r5, #1]
    add r0, r5, r0
    add r0, r0, #2
    cmp r0, r6
    bls @lbl_02703290
@lbl_027032D8:
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
