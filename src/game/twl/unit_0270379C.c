/*
 * file:     unit_0270379C.c
 * unit:     yes
 * function: func_0270379C, func_02703854, func_027038BC
 * address:  0x0270379C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl
 *   func_027028E4  0x027028E4  code twl
 *   func_020821C0  0x020821C0  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02703A34  0x02703A34  code twl
 *   func_02703A54  0x02703A54  code twl
 *   func_02703A74  0x02703A74  code twl
 */
typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_027028E4(u32, u32, u32);
extern void func_020821C0(u32, u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02703A54(u32, u32);
extern u32 func_02703A74(u32, u32, u32);
asm void func_0270379C(u32 a0, u32 a1, u32 a2, u32 a3);
u32 func_02703854(u32 a0, u32 a1);
asm void func_027038BC(u32 a0);


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



u32 func_02703854(u32 a0, u32 a1) {
    u32 st;
    u32 res;

    func_027026DC();
    st = func_027028E4(2, 3, 4);
    if (st != 0 && st != 2) {
        return st;
    }
    func_02703A34(0xC, a0);
    func_02703A54(a1, 0);
    res = func_02703A74(0xC, 1, a1);
    if (res == 0) {
        return 2;
    }
    return res;
}



asm void func_027038BC(u32 a0) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #4
    mov r6, r0
    bl func_027026DC
    ldrh r1, [r6, #2]
    mov r4, r0
    cmp r1, #0
    beq @lbl_027038F0
    cmp r1, #0xb
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, pc}
    mov r5, #0
    b @lbl_027038F4
@lbl_027038F0:
    mov r5, #1
@lbl_027038F4:
    ldrh r0, [r6, #4]
    add r0, r4, r0, lsl #2
    add r0, r0, #0x2000
    ldr r0, [r0, #0x2d4]
    cmp r0, #0
    beq @lbl_02703930
    mov r0, r6
    mov r1, #0x10
    bl func_020862D4
    ldrh r1, [r6, #4]
    mov r0, r6
    add r1, r4, r1, lsl #2
    add r1, r1, #0x2000
    ldr r1, [r1, #0x2d4]
    blx r1
@lbl_02703930:
    cmp r5, #0
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, pc}
    ldrh r2, [r6, #4]
    mov r0, #0xa
    mov r1, #3
    str r2, [sp]
    ldr r2, [r6, #0xc]
    mov r3, #0
    bl func_02703A74
    add sp, sp, #4
    ldmfd sp!, {r3, r4, r5, r6, pc}
}
