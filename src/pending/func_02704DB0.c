/*
 * function: func_02704DB0
 * address:  0x02704DB0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_02734450   0x02734450  data twl
 *   func_02704DB0  0x02704DB0  code twl
 *   func_027044C0  0x027044C0  code twl
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];
extern void func_02704DB0(u32);
extern u32 func_027044C0(u32, u32, u32);

asm void func_02704DB0(u32 a0) {
    stmdb sp!, {r4, lr}
    cmp r0, #0
    beq @lbl_02704DEC
    ldr r4, =DAT_02734450
    ldr r0, [r4, #0x10]
    cmp r0, #5
    bhs @lbl_02704DEC
    ldrb r0, [r4]
    ldr r1, =func_02704DB0
    mov r2, #0
    bl func_027044C0
    ldr r0, [r4, #0x10]
    add r0, r0, #1
    str r0, [r4, #0x10]
    ldmfd sp!, {r4, pc}
@lbl_02704DEC:
    ldr r0, =DAT_02734450
    mov r1, #0
    str r1, [r0, #0x14]
    ldmfd sp!, {r4, pc}
}
