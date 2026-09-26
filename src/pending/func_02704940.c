/*
 * function: func_02704940
 * address:  0x02704940
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02087B20  0x02087B20  code twl
 *   DAT_02734450   0x02734450  data twl
 *   func_02704D48  0x02704D48  code twl
 *   func_02704B74  0x02704B74  code twl
 */

typedef unsigned int u32;

extern u32 func_02087B20(void);
extern u32 DAT_02734450[];
extern void func_02704D48(u32, u32, u32, u32);
extern u32 func_02704B74(u32, u32);

asm void func_02704940(u32 a0, u32 a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    bl func_02087B20
    cmp r0, #0
    beq @lbl_02704968
    ldr r4, =DAT_02734450
    ldr r0, [r4, #0xc]
    cmp r0, #4
    beq @lbl_02704970
@lbl_02704968:
    mov r0, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704970:
    mov r6, #5
    mov r5, #0
    mov r0, r8
    mov r1, r7
    mov r2, r5
    str r6, [r4, #0xc]
    mov r3, #0xfc
    bl func_02704D48
    ldrb r0, [r4, #0x58]
    mov r1, r5
    bl func_02704B74
    cmp r0, #0
    movne r6, r5
    mov r0, r6
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
