/*
 * function: func_02704858
 * address:  0x02704858
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
 *   DAT_02150fec   0x02150fec  data twl
 *   DAT_02734450   0x02734450  data twl
 *   func_02704C5C  0x02704C5C  code twl
 *   func_02085D94  0x02085D94  code twl
 *   func_02704B58  0x02704B58  code twl
 *   func_02704D48  0x02704D48  code twl
 *   func_02704B74  0x02704B74  code twl
 *   func_02085E50  0x02085E50  code twl
 */

typedef unsigned int u32;

extern u32 func_02087B20(void);
extern u32 DAT_02150fec[];
extern u32 DAT_02734450[];
extern u32 func_02704C5C(void);
extern void func_02085D94(u32, u32, u32);
extern u32 func_02704B58(void);
extern void func_02704D48(u32, u32, u32, u32);
extern u32 func_02704B74(u32, u32);
extern void func_02085E50(u32, u32, u32);

asm void func_02704858(void) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x28
    bl func_02087B20
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r0, =DAT_02150fec
    ldr r0, [r0, #4]
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r0, =DAT_02734450
    ldr r1, [r0, #0xc]
    cmp r1, #4
    beq @lbl_027048B4
    bl func_02704C5C
    str r0, [sp, #4]
    cmp r0, #0
    beq @lbl_027048C8
    add sp, sp, #0x28
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_027048B4:
    ldr r0, [r0, #0xc]
    cmp r0, #5
    addeq sp, sp, #0x28
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, pc}
@lbl_027048C8:
    add r6, sp, #8
    mov r5, #1
    add r1, sp, #0
    mov r0, r6
    mov r2, r5
    bl func_02085D94
    mov r4, #0
    ldr r0, =func_02704B58
    mov r1, r6
    mov r2, r4
    mov r3, #0xfb
    bl func_02704D48
    ldr r0, =DAT_02734450
    mov r1, r4
    ldrb r0, [r0, #0x58]
    bl func_02704B74
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #5
    ldmeqfd sp!, {r4, r5, r6, pc}
    add r1, sp, #4
    mov r0, r6
    mov r2, r5
    bl func_02085E50
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r4, r5, r6, pc}
}
