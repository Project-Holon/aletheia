/*
 * function: func_02704CC4
 * address:  0x02704CC4
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02087988  0x02087988  code twl
 *   DAT_02734450   0x02734450  data twl
 *   func_02704D48  0x02704D48  code twl
 *   func_0208799C  0x0208799C  code twl
 */

typedef unsigned int u32;

extern u32 func_02087988(void);
extern u32 DAT_02734450[];
extern void func_02704D48(u32, u32, u32, u32);
extern void func_0208799C(u32);

asm void func_02704CC4(u32 a0) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r0
    bl func_02087988
    ldr r1, =DAT_02734450
    mov r4, r0
    ldrb r8, [r1, #0x58]
    ldr r5, [r1, #0x4c]
    ldr r6, [r1, #0x50]
    cmp r8, #0xc7
    moveq r0, #0
    streq r0, [r1, #0x18]
    streq r0, [r1, #4]
    mov r0, #0
    mov r1, r0
    mov r2, r0
    mov r3, r0
    bl func_02704D48
    cmp r8, #0xfb
    ldreq r0, =DAT_02734450
    moveq r1, #4
    streq r1, [r0, #0xc]
    ldrne r0, =DAT_02734450
    movne r1, #2
    strne r1, [r0, #0xc]
    mov r0, r4
    bl func_0208799C
    cmp r5, #0
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r7
    mov r1, r6
    blx r5
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
