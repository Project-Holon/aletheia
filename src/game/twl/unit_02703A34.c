/*
 * file:     unit_02703A34.c
 * unit:     yes
 * function: func_02703A34, func_02703A54, func_02703A74, func_02703B24, func_02703B98
 * address:  0x02703A34
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
 *   func_027026DC  0x027026DC  code twl a2
 *   func_020862D4  0x020862D4  code twl
 *   func_02088610  0x02088610  code twl
 *   func_02085DBC  0x02085DBC  code twl
 *   func_02082D44  0x02082D44  code twl
 *   func_02085E50  0x02085E50  code twl
 *   func_020862B8  0x020862B8  code twl
 */
typedef unsigned int u32;

extern u32 func_027026DC(void);
extern void func_020862D4(u32, u32);
extern u32 func_02088610(u32, u32, u32);
extern void func_02085DBC(u32, u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02085E50(u32, u32, u32);
extern void func_020862B8(u32, u32);
void func_02703A34(u32 a0, u32 a1);
void func_02703A54(u32 a0, u32 a1);
asm void func_02703A74(u32 a0, u32 a1, u32 a2, u32 a3);
asm void func_02703B24(u32 a0, u32 a1);
asm void func_02703B98(void);



void func_02703A34(u32 a0, u32 a1) {
    u32 base = func_027026DC();
    *(u32 *)(base + (a0 << 2) + 0x2284) = a1;
}



void func_02703A54(u32 a0, u32 a1) {
    u32 base = func_027026DC();
    *(u32 *)(base + (a0 << 2) + 0x22D4) = a1;
}



asm void func_02703A74(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    bl func_027026DC
    mov r5, r0
    bl func_02703B98
    movs r4, r0
    moveq r0, #6
    ldmeqfd sp!, {r4, r5, r6, lr}
    addeq sp, sp, #0x10
    bxeq lr
    strh r6, [r4]
    ldrh r6, [sp, #0x14]
    add r0, sp, #0x14
    bic r0, r0, #3
    mov r3, #0
    cmp r6, #0
    add r2, r0, #4
    ble @lbl_02703ADC
@lbl_02703AC0:
    add r2, r2, #4
    ldr r1, [r2, #-4]
    add r0, r4, r3, lsl #2
    add r3, r3, #1
    str r1, [r0, #4]
    cmp r3, r6
@lbl_dcd:
    dcd 0xbafffff8
@lbl_02703ADC:
    mov r0, r4
    mov r1, #0x100
    bl func_020862D4
    mov r1, r4
    mov r0, #0x16
    mov r2, #0
    bl func_02088610
    mov r6, r0
    mov r1, r4
    add r0, r5, #0x2000
    mov r2, #1
    bl func_02085DBC
    mov r0, #6
    cmp r6, #0
    movge r0, #2
    ldmfd sp!, {r4, r5, r6, lr}
    add sp, sp, #0x10
    bx lr
}



asm void func_02703B24(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r4, r1
    bl func_027026DC
    mov r6, r0
    bl func_02703B98
    movs r5, r0
    moveq r0, #6
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r7
    mov r1, r5
    mov r2, r4
    bl func_02082D44
    mov r0, r5
    mov r1, r4
    bl func_020862D4
    mov r1, r5
    mov r0, #0x16
    mov r2, #0
    bl func_02088610
    mov r4, r0
    mov r1, r5
    add r0, r6, #0x2000
    mov r2, #1
    bl func_02085DBC
    mov r0, #6
    cmp r4, #0
    movge r0, #2
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}



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
