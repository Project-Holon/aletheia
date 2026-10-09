/*
 * file:     unit_027032E0.c
 * function: func_027032E0
 * address:  0x027032E0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027028E4  0x027028E4  arm twl
 *   func_027026DC  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   func_02703A34  0x02703A34  arm twl
 *   func_02082D44  0x02082D44  arm twl
 *   func_02703B24  0x02703B24  arm twl
 *   DAT_027341cc   0x027341cc  data twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02703B24(u32, u32);
extern u32 DAT_027341cc[];

asm void func_027032E0(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #8
    mov r7, r0
    mov r6, r1
    mov r0, #1
    mov r1, #3
    mov r5, r2
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02703314
    cmp r0, #2
    addne sp, sp, #8
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703314:
    bl func_027026DC
    movs r8, r0
    beq @lbl_02703350
    add r0, r8, #0x2000
    ldr r0, [r0, #0x278]
    mov r4, #1
    mov r1, r4
    add r0, r0, #8
    bl func_020862B8
    add r0, r8, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #8]
    cmp r0, #1
    movne r4, #0
    b @lbl_02703354
@lbl_02703350:
    mov r4, #0
@lbl_02703354:
    cmp r4, #1
    addeq sp, sp, #8
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp r5, #0
    addeq sp, sp, #8
    moveq r0, #5
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    ldrh r1, [r5]
    cmp r1, #0x200
    addhi sp, sp, #8
    movhi r0, #5
    ldmhifd sp!, {r4, r5, r6, r7, r8, pc}
    cmp r6, #3
    addhs sp, sp, #8
    movhs r0, #5
    ldmhsfd sp!, {r4, r5, r6, r7, r8, pc}
    ldrh r0, [r5, #0xa]
    cmp r0, #0
    addeq sp, sp, #8
    moveq r0, #5
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r5
    mov r1, r1, lsl #1
    bl func_020862D4
    mov r8, #8
    mov r0, r8
    mov r1, r7
    bl func_02703A34
    ldr r1, =DAT_027341cc
    ldrh r2, [r5]
    mov r0, r5
    str r1, [sp, #4]
    strh r8, [sp]
    strb r6, [sp, #2]
    bl func_02082D44
    ldr r0, [sp, #4]
    mov r1, #0x200
    bl func_020862D4
    add r4, sp, #0
    mov r1, r8
    mov r0, r4
    bl func_020862D4
    mov r0, r4
    mov r1, r8
    bl func_02703B24
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #8
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
