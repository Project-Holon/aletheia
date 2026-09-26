/*
 * function: func_02703B24
 * address:  0x02703B24
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
 *   func_02703B98  0x02703B98  code twl
 *   func_02082D44  0x02082D44  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02088610  0x02088610  code twl
 *   func_02085DBC  0x02085DBC  code twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(u32, u32);
extern u32 func_02703B98(void);
extern void func_02082D44(u32, u32, u32);
extern void func_020862D4(u32, u32);
extern u32 func_02088610(u32, u32, u32);
extern void func_02085DBC(u32, u32, u32);

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
