/*
 * function: func_02704448
 * address:  0x02704448
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02704C5C  0x02704C5C  code twl
 *   func_02704D48  0x02704D48  code twl
 *   DAT_02734450   0x02734450  data twl
 *   func_02704B74  0x02704B74  code twl
 */

typedef unsigned int u32;

extern u32 func_02704C5C(void);
extern void func_02704D48(u32, u32, u32, u32);
extern u32 DAT_02734450[];
extern u32 func_02704B74(u32, u32);

asm void func_02704448(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    movs r5, r3
    mov r8, r0
    movne r0, #7
    moveq r0, #0x1f
    cmp r8, r0
    mov r7, r1
    mov r6, r2
    movgt r0, #2
    ldmgtfd sp!, {r4, r5, r6, r7, r8, pc}
    bl func_02704C5C
    cmp r0, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov r4, #0
    mov r0, r7
    mov r1, r6
    mov r2, r4
    mov r3, #0x84
    bl func_02704D48
    ldr r0, =DAT_02734450
    and r1, r8, #0x1f
    orr r1, r1, r5, lsl #6
    ldrb r0, [r0, #0x58]
    and r1, r1, #0xff
    bl func_02704B74
    cmp r0, #0
    moveq r4, #5
    mov r0, r4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
