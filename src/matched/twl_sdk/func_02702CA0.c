/*
 * function: func_02702CA0
 * address:  0x02702CA0
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
 *   func_02703A34  0x02703A34  arm twl
 *   func_02703A74  0x02703A74  arm twl
 *   DAT_027341c8   0x027341c8  data twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32, u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02703A34(u32, u32);
extern u32 func_02703A74(u32, u32, u32);
extern u32 DAT_027341c8[];

asm void func_02702CA0(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #8
    mov r1, #4
    mov r4, r0
    str r1, [sp]
    mov r0, #5
    mov r1, #1
    mov r2, #2
    mov r3, #3
    str r0, [sp, #4]
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02702CE0
    cmp r0, #2
    addne sp, sp, #8
    ldmnefd sp!, {r4, r5, r6, pc}
@lbl_02702CE0:
    bl func_027026DC
    movs r5, r0
    beq @lbl_02702D1C
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    mov r6, #1
    mov r1, r6
    add r0, r0, #4
    bl func_020862B8
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #4]
    cmp r0, #1
    movne r6, #0
    b @lbl_02702D20
@lbl_02702D1C:
    mov r6, #0
@lbl_02702D20:
    cmp r6, #1
    addeq sp, sp, #8
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r5, #4
    mov r0, r5
    mov r1, r4
    bl func_02703A34
    bl func_027026DC
    mov r1, #1
    mov r0, r5
    mov r2, r1
    bl func_02703A74
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #8
    ldmfd sp!, {r4, r5, r6, pc}
    ldr r0, =DAT_027341c8
    mov r1, #1
    strb r1, [r0]
    bx lr
}
