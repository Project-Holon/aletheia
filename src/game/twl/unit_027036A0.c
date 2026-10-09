/*
 * file:     unit_027036A0.c
 * unit:     yes
 * function: func_027036A0, func_02703764
 * address:  0x027036A0
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
 *   func_02087988  0x02087988  code twl
 *   func_0208799C  0x0208799C  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02703A74  0x02703A74  code twl
 *   func_02082D44  0x02082D44  code twl a2
 */
typedef unsigned int u32;

typedef unsigned char  u8;

extern u32 func_027026DC(void);
extern u32 func_027028E4(u32, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020862D4(u32, u32);
extern u32 func_02703A74(u32, u32, u32, u32, u32);
extern void func_02082D44(u32, u32, u32);
asm void func_027036A0(u32 a0, u32 a1, u32 a2, u32 a3);
void func_02703764(u32 a0, u32 a1, u8 *a2, u32 a3);


asm void func_027036A0(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    mov r5, r3
    bl func_027026DC
    mov sb, r0
    mov r0, #1
    mov r1, #4
    bl func_027028E4
    cmp r0, #0
    beq @lbl_027036D8
    cmp r0, #2
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027036D8:
    bl func_02087988
    ldr r1, =0x5f2
    mov r4, r0
    cmp r5, r1
    bls @lbl_027036F8
    bl func_0208799C
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027036F8:
    mov r0, r6
    mov r1, r5
    bl func_020862D4
    add r0, sb, #0x2000
    ldr r1, [r0, #0x278]
    mov r0, r7
    mov r2, r6
    mov r3, r5
    add r1, r1, #0x40
    bl func_02703764
    mov r0, r6
    mov r1, #0xe
    bl func_020862D4
    mov r2, r8
    mov r3, r6
    mov r0, #0xb
    mov r1, #3
    str r5, [sp]
    bl func_02703A74
    movs r5, r0
    moveq r0, #2
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    mov r0, r4
    bl func_0208799C
    mov r0, r5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}


void func_02703764(u32 a0, u32 a1, u8 *a2, u32 a3) {
    if (a3 < 0xE) {
        return;
    }
    func_02082D44(a0, (u32)a2, 6);
    func_02082D44(a1, (u32)(a2 + 6), 6);
}
