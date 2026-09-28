/*
 * function: func_02703B98
 * address:  0x02703B98
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl
 *   func_02085E50  0x02085E50  code twl
 *   func_020862B8  0x020862B8  code twl
 *   func_02085DBC  0x02085DBC  code twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_02085E50(u32, u32, u32);
extern void func_020862B8(u32, u32);
extern void func_02085DBC(u32, u32, u32);

asm void func_02703B98(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    mov r0, #0
    str r0, [sp]
    bl func_027026DC
    mov sb, r0
    mov r4, #1
    mov r6, #0x2000
    mov r5, #2
    add r8, sp, #0
    mov r7, #0
@lbl_02703BC0:
    mov r1, r8
    mov r2, r7
    add r0, sb, #0x2000
    bl func_02085E50
    cmp r0, #0
    moveq r0, r7
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    mov r0, sb
    mov r1, r6
    bl func_020862B8
    ldr r0, [sp]
    mov r1, r5
    bl func_020862B8
    ldr r1, [sp]
    ldrh r0, [r1]
    tst r0, #0x8000
    bne @lbl_02703C18
    mov r2, r4
    add r0, sb, #0x2000
    bl func_02085DBC
    mov r1, r7
    str r7, [sp]
@lbl_02703C18:
    cmp r1, #0
    beq @lbl_02703BC0
    mov r0, r1
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}
