/*
 * function: func_027034C0
 * address:  0x027034C0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_027028E4  0x027028E4  code twl
 *   func_027026DC  0x027026DC  code twl
 *   func_020862B8  0x020862B8  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02703A34  0x02703A34  code twl
 *   func_02082D44  0x02082D44  code twl
 *   func_02703B24  0x02703B24  code twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02703B24(u32, u32);

asm void func_027034C0(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    sub sp, sp, #0x58
    mov sb, r0
    mov r8, r1
    mov r0, #1
    mov r1, #3
    mov r7, r2
    mov r6, r3
    bl func_027028E4
    cmp r0, #0
    beq @lbl_027034F8
    cmp r0, #2
    addne sp, sp, #0x58
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027034F8:
    bl func_027026DC
    movs r4, r0
    beq @lbl_02703534
    add r0, r4, #0x2000
    ldr r0, [r0, #0x278]
    mov r5, #1
    mov r1, r5
    add r0, r0, #0xd
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #0xd]
    cmp r0, #1
    movne r5, #0
    b @lbl_02703538
@lbl_02703534:
    mov r5, #0
@lbl_02703538:
    cmp r5, #1
    addeq sp, sp, #0x58
    moveq r0, #3
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r8, #3
    addls pc, pc, r8, lsl #2
    b @lbl_02703584
    b @lbl_02703564
    b @lbl_0270356C
    b @lbl_02703574
    b @lbl_0270357C
@lbl_02703564:
    mov r8, #0
    b @lbl_02703590
@lbl_0270356C:
    mov r8, #5
    b @lbl_02703590
@lbl_02703574:
    mov r8, #0xd
    b @lbl_02703590
@lbl_0270357C:
    mov r8, #0x10
    b @lbl_02703590
@lbl_02703584:
    add sp, sp, #0x58
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_02703590:
    mov r5, #0x50
    mov r0, r6
    mov r1, r5
    bl func_020862D4
    mov r4, #0xd
    mov r0, r4
    mov r1, sb
    bl func_02703A34
    ldrh r3, [sp, #0x78]
    add r1, sp, #8
    mov r0, r6
    mov r2, r5
    strh r4, [sp]
    strh r7, [sp, #4]
    strh r8, [sp, #6]
    strh r3, [sp, #2]
    bl func_02082D44
    add r0, sp, #0
    mov r1, #0x58
    bl func_02703B24
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #0x58
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}
