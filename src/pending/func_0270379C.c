/*
 * function: func_0270379C
 * address:  0x0270379C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl
 *   func_027028E4  0x027028E4  code twl
 *   func_020821C0  0x020821C0  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02703A34  0x02703A34  code twl
 *   func_02703A54  0x02703A54  code twl
 *   func_02703A74  0x02703A74  code twl
 *   func_027038BC  0x027038BC  code twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_027028E4(u32, u32, u32);
extern void func_020821C0(u32, u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02703A54(u32, u32);
extern u32 func_02703A74(u32, u32, u32, u32, u32);
extern u32 func_027038BC[];

asm void func_0270379C(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #4
    mov r7, r0
    mov r6, r1
    mov r5, r2
    mov r4, r3
    bl func_027026DC
    mov r8, r0
    mov r0, #2
    mov r1, #3
    mov r2, #4
    bl func_027028E4
    cmp r0, #0
    beq @lbl_027037E0
    cmp r0, #2
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, pc}
@lbl_027037E0:
    mov r0, #1
    str r0, [sp]
    add r0, r8, #0x2200
    ldrh r0, [r0, #0x80]
    mov r1, r6
    mov r3, r5
    mov r2, #0
    bl func_020821C0
    mov r0, r6
    mov r1, r5
    bl func_020862D4
    mov r8, #0xa
    ldr r1, =func_027038BC
    mov r0, r8
    bl func_02703A34
    mov r1, r7
    mov r0, r4
    bl func_02703A54
    mov r0, r8
    mov r2, r6
    mov r3, r5
    mov r1, #3
    str r4, [sp]
    bl func_02703A74
    cmp r0, #0
    moveq r0, #2
    add sp, sp, #4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, pc}
}
