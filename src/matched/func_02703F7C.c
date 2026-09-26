/*
 * function: func_02703F7C
 * address:  0x02703F7C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02088610  0x02088610  code twl
 */

typedef unsigned int u32;

extern u32 func_02088610(u32, u32, u32);

asm void func_02703F7C(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r1
    orr r1, r3, #0x4400
    mov r4, #9
    mov r8, r0
    mov r5, #0
    mov r6, r2
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x2000000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r8, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x10000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r8, lsl #0x10
    mov r1, r0, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x20000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r7, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x30000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r7, lsl #0x10
    mov r1, r0, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x40000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r6, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x50000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    ldr r3, =0x01060000
    mov r1, r6, lsl #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r3, r1, lsr #16
    bl func_02088610
    cmp r0, #0
    movge r5, #1
    mov r0, r5
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
