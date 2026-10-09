/*
 * file:     unit_02701020.c
 * unit:     yes
 * function: func_02701020, func_02701120
 * address:  0x02701020
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
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_027007C8 0x027007C8 arm twl a2
 *   func_02087988 0x02087988 arm twl a2
 *   func_0208799C 0x0208799C arm twl a2
 *   func_027019B4 0x027019B4 arm twl a2
 *   func_02701A60 0x02701A60 arm twl a2
 */
typedef unsigned int u32;

extern u32 func_027007C8(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 func_027019B4(u32, u32, u32);
extern u32 func_02701A60(u32);
asm void func_02701020(u32 a0, u32 a1, u32 a2, u32 a3);
asm void func_02701120(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32 data_02732FC8[];
extern u32 data_02733FC8[];


asm void func_02701020(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    mov r5, r3
    bl func_027007C8
    mov r4, r0
    cmp r4, #7
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r8, #1
    cmpne r8, #2
    cmpne r8, #3
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r7, #0xb
    addls pc, pc, r7, lsl #2
    b @lbl_02701094
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
    b @lbl_0270109C
@lbl_02701094:
    mov r0, #3
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_0270109C:
    bl func_02087988
    ldr sb, =data_02732FC8
    ldr r1, [sb]
    cmp r1, #0
    beq @lbl_027010C4
    bl func_0208799C
    mov r0, #6
    cmp r4, #6
    movne r0, #2
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027010C4:
    mov r1, #1
    str r1, [sb]
    bl func_0208799C
    str r6, [sb, #4]
    ldr r0, =data_02733FC8
    str r5, [sb, #0xc]
    strb r8, [sp]
    strb r7, [sp, #1]
    str r8, [r0, #0x1a0]
    str r7, [r0, #0x1a8]
    ldrb r2, [sp]
    mov r0, #0x31
    mov r1, #2
    bl func_027019B4
    cmp r0, #0
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    add r0, sp, #1
    bl func_02701A60
    mov r0, #0
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}


asm void func_02701120(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    sub sp, sp, #8
    mov r8, r0
    mov r7, r1
    mov r6, r2
    mov r5, r3
    bl func_027007C8
    mov r4, r0
    cmp r4, #7
    addeq sp, sp, #8
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r8, #1
    cmpne r8, #2
    cmpne r8, #3
    addne sp, sp, #8
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r7, #1
    cmpne r7, #2
    cmpne r7, #3
    addne sp, sp, #8
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r6, #5
    addls pc, pc, r6, lsl #2
    b @lbl_027011A0
    b @lbl_027011AC
    b @lbl_027011AC
    b @lbl_027011AC
    b @lbl_027011AC
    b @lbl_027011AC
    b @lbl_027011AC
@lbl_027011A0:
    add sp, sp, #8
    mov r0, #3
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027011AC:
    bl func_02087988
    ldr sb, =data_02732FC8
    ldr r1, [sb]
    cmp r1, #0
    beq @lbl_027011D8
    bl func_0208799C
    mov r0, #6
    cmp r4, #6
    add sp, sp, #8
    movne r0, #2
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_027011D8:
    mov r1, #1
    str r1, [sb]
    bl func_0208799C
    ldr r1, [sp, #0x28]
    str r5, [sb, #4]
    str r1, [sb, #0xc]
    ldr r0, =data_02733FC8
    strb r8, [sp]
    strb r7, [sp, #1]
    strb r6, [sp, #2]
    str r8, [r0, #0x1a0]
    str r7, [r0, #0x1a4]
    str r6, [r0, #0x1a8]
    ldrb r2, [sp]
    mov r0, #0x32
    mov r1, #3
    bl func_027019B4
    cmp r0, #0
    addeq sp, sp, #8
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    add r0, sp, #1
    bl func_02701A60
    mov r0, #0
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}
