/*
 * file:     unit_027035F4.c
 * function: func_027035F4
 * address:  0x027035F4
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027028E4 0x027028E4 arm twl
 *   func_027026DC 0x027026DC arm twl
 *   func_020862B8 0x020862B8 arm twl
 *   func_02703A34 0x02703A34 arm twl
 *   func_02703A74 0x02703A74 arm twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02703A34(u32, u32);
extern u32 func_02703A74(u32, u32, u32);

asm void func_027035F4(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    mov r5, r1
    mov r0, #2
    mov r1, #3
    mov r2, #4
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02703620
    cmp r0, #2
    ldmnefd sp!, {r3, r4, r5, r6, r7, pc}
@lbl_02703620:
    bl func_027026DC
    movs r7, r0
    beq @lbl_0270365C
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    mov r4, #1
    mov r1, r4
    add r0, r0, #0xe
    bl func_020862B8
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #0xe]
    cmp r0, #1
    movne r4, #0
    b @lbl_02703660
@lbl_0270365C:
    mov r4, #0
@lbl_02703660:
    cmp r4, #1
    moveq r0, #3
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    mov r4, #0xe
    mov r0, r4
    mov r1, r6
    bl func_02703A34
    bl func_027026DC
    mov r0, r4
    mov r2, r5
    mov r1, #1
    bl func_02703A74
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}
