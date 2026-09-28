/*
 * function: func_02702D7C
 * address:  0x02702D7C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0273153C  0x0273153C  arm twl
 *   func_027026DC  0x027026DC  arm twl
 *   func_02087A04  0x02087A04  arm twl
 *   func_02088688  0x02088688  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_027028B0  0x027028B0  arm twl
 *   func_027028E4  0x027028E4  arm twl
 *   DAT_027341c8   0x027341c8  data twl
 *   func_02702CA0  0x02702CA0  arm twl
 *   DAT_02702d68   0x02702D68  arm twl
 */

typedef unsigned int u32;

extern u32 func_0273153C(void);
extern u32 func_027026DC(void);
extern void func_02087A04(u32);
extern void func_02088688(void);
extern void func_020862B8(u32, u32);
extern u32 func_027028B0(void);
extern u32 func_027028E4(u32, u32, u32, u32, u32);
extern u32 DAT_027341c8[];
extern void func_02702CA0(void);
extern u32 DAT_02702d68[];

asm void func_02702D7C(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #4
    mov r4, #0
    bl func_0273153C
    cmp r0, #0
    addeq sp, sp, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    bl func_027026DC
    cmp r0, #0
    ldr r7, =0x3fec420
    addeq sp, sp, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r0, =0x61a80
    bl func_02087A04
    mov r8, #1
    mov r10, r8
    mov r5, r8
    ldr r6, =0x2710
    b @lbl_02702DD4
@lbl_02702DC8:
    mov r0, r6
    bl func_02087A04
    bl func_02088688
@lbl_02702DD4:
    bl func_027026DC
    movs r9, r0
    beq @lbl_02702E10
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, r5
    add r0, r0, #3
    bl func_020862B8
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #3]
    cmp r0, #1
    moveq r0, r5
    movne r0, r4
    b @lbl_02702E14
@lbl_02702E10:
    mov r0, r4
@lbl_02702E14:
    cmp r0, #1
    bne @lbl_02702E28
    bl func_027028B0
    cmp r0, #1
    beq @lbl_02702DC8
@lbl_02702E28:
    bl func_027026DC
    movs r9, r0
    beq @lbl_02702E64
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, r10
    add r0, r0, #1
    bl func_020862B8
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #1]
    cmp r0, #1
    moveq r0, r10
    movne r0, r4
    b @lbl_02702E68
@lbl_02702E64:
    mov r0, r4
@lbl_02702E68:
    cmp r0, #1
    beq @lbl_02702DC8
    bl func_027026DC
    movs r9, r0
    beq @lbl_02702EAC
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, r8
    add r0, r0, #0x13
    bl func_020862B8
    add r0, r9, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #0x13]
    cmp r0, #1
    moveq r0, r8
    movne r0, r4
    b @lbl_02702EB0
@lbl_02702EAC:
    mov r0, r4
@lbl_02702EB0:
    cmp r0, #1
    beq @lbl_02702DC8
    mov r0, #4
    mov r4, #5
    mov r3, r0
    mov r1, #2
    mov r2, #3
    str r4, [sp]
    mov r5, #0
    bl func_027028E4
    cmp r0, #0
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r4, =0x27341c8
    ldr r0, =0x2702d68
    strb r5, [r4]
    bl func_02702CA0
    ldr r5, =0x2710
@lbl_02702EF8:
    mov r0, r5
    bl func_02087A04
    bl func_02088688
    subs r7, r7, r5
    addmi sp, sp, #4
    ldmmifd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldrb r0, [r4]
    cmp r0, #0
    beq @lbl_02702EF8
    add sp, sp, #4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
}

