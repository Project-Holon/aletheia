/*
 * file:     unit_02704364_p01.c
 * unit:     yes
 * function: func_02704364, func_02704448, func_027044C0, func_027044F8, func_027047C0, func_02704858
 * address:  0x02704364
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DAT_02734450   0x02734450  data twl
 *   func_02087988  0x02087988  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   func_02704D48  0x02704D48  arm twl
 *   func_02088498  0x02088498  arm twl
 *   func_020885EC  0x020885EC  arm twl
 *   func_02004490  0x02004490  arm twl
 *   func_020885A0  0x020885A0  arm twl
 *   func_027049B0  0x027049B0  arm twl
 *   func_02704D64  0x02704D64  arm twl
 *   DAT_0273446c   0x0273446c  data twl
 *   func_0273156C  0x0273156C  arm twl
 *   DAT_0273448c   0x0273448c  data twl
 *   func_0208C848  0x0208C848  arm twl
 *   func_02704C5C  0x02704C5C  arm twl
 *   func_02704B74  0x02704B74  arm twl
 *   func_02085D3C  0x02085D3C  arm twl
 *   func_02087B20  0x02087B20  arm twl
 *   func_02704BE0  0x02704BE0  arm twl
 *   func_02087A04  0x02087A04  arm twl
 *   DAT_02150fec   0x02150fec  data twl
 *   func_02085D94  0x02085D94  arm twl
 *   func_02704B58  0x02704B58  arm twl
 *   func_02085E50  0x02085E50  arm twl
 */
typedef unsigned int u32;

extern u32 func_02087988(void);
extern void func_0208799C(void);
extern void func_02704D48(u32, u32, u32, u32);
extern void func_02088498(void);
extern u32 func_020885EC(u32, u32);
extern void func_02004490(u32);
extern void func_020885A0(u32, u32);
extern u32 func_027049B0(void);
extern u32 func_02704D64(void);
extern void func_0273156C(u32, u32);
extern void func_0208C848(u32, u32);
extern u32 func_02704C5C(void);
extern u32 func_02704B74(u32, u32);
extern u32 func_02085D3C(void);
extern u32 func_02087B20(void);
extern u32 func_02704BE0(u32, u32);
extern void func_02087A04(u32);
extern void func_02085D94(u32, u32, u32);
extern u32 func_02704B58(void);
extern void func_02085E50(u32, u32, u32);
asm void func_02704364(void);
asm void func_02704448(u32 a0, u32 a1, u32 a2, u32 a3);
asm void func_027044C0(u32 a0, u32 a1, u32 a2);
asm void func_027044F8(u32 a0, u32 a1, u32 a2, u32 a3);
asm void func_027047C0(u32 a0, u32 a1);
asm void func_02704858(void);
extern u32 DAT_02734450[];
extern u32 DAT_0273446c[];
extern u32 DAT_0273448c[];
extern u32 DAT_02150fec[];


asm void func_02704364(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    bl func_02087988
    ldr r1, =DAT_02734450
    ldr r2, [r1, #0xc]
    cmp r2, #0
    beq @lbl_02704384
    bl func_0208799C
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
@lbl_02704384:
    mov r4, #1
    str r4, [r1, #0xc]
    bl func_0208799C
    mov r0, #0
    mov r1, r0
    mov r2, r0
    mov r3, r0
    bl func_02704D48
    bl func_02088498
    mov r1, r4
    mov r0, #0x18
    bl func_020885EC
    cmp r0, #0
    bne @lbl_027043E0
    mov r6, #0xa
    mov r5, #0x18
@lbl_027043C4:
    mov r0, r6
    dcd 0xfae40030
    mov r0, r5
    mov r1, r4
    bl func_020885EC
    cmp r0, #0
    beq @lbl_027043C4
@lbl_027043E0:
    ldr r1, =func_027049B0
    mov r0, #0x18
    bl func_020885A0
    ldr r5, =0x0000fffd
    ldr r7, =func_02704D64
    ldr r4, =DAT_02734450
    ldr r0, =DAT_0273446c
    mov r1, r5
    str r7, [r4, #0x1c]
    mov r6, #0
    str r6, [r4, #0x20]
    bl func_0273156C
    str r7, [r4, #0x3c]
    ldr r0, =DAT_0273448c
    mov r1, r5
    str r6, [r4, #0x40]
    bl func_0208C848
    mov r0, #2
    str r0, [r4, #0xc]
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}


asm void func_02704448(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    movs r5, r3
    mov r8, r0
    movne r0, #7
    moveq r0, #0x1f
    cmp r8, r0
    mov r7, r1
    mov r6, r2
    movgt r0, #2
    ldmgtfd sp!, {r4, r5, r6, r7, r8, pc}
    bl func_02704C5C
    cmp r0, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov r4, #0
    mov r0, r7
    mov r1, r6
    mov r2, r4
    mov r3, #0x84
    bl func_02704D48
    ldr r0, =DAT_02734450
    and r1, r8, #0x1f
    orr r1, r1, r5, lsl #6
    ldrb r0, [r0, #0x58]
    and r1, r1, #0xff
    bl func_02704B74
    cmp r0, #0
    moveq r4, #5
    mov r0, r4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}


asm void func_027044C0(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r1
    mov r4, r2
    bl func_02085D3C
    cmp r0, #0
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r0, r6
    mov r1, r5
    mov r2, r4
    mov r3, #0
    bl func_02704448
    ldmfd sp!, {r4, r5, r6, pc}
}


asm void func_027044F8(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r8, =DAT_02734450
    mov r4, r0
    ldr r0, [r8, #4]
    mov r7, r1
    cmp r0, #0
    mov r6, r2
    mov r5, r3
    mov r9, #0
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r0, #1
    str r0, [r8, #4]
    bl func_02087B20
    cmp r0, #0
    streq r9, [r8, #4]
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    bl func_02704C5C
    cmp r0, #0
    strne r9, [r8, #4]
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r0, r9
    mov r1, r9
    mov r2, r9
    mov r3, #0xc1
    bl func_02704D48
    mov r1, r4, lsl #16
    ldrb r0, [r8, #0x58]
    mov r1, r1, lsr #16
    bl func_02704BE0
    cmp r0, #0
    streq r9, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    ldr r8, =DAT_02734450
    mov r0, r9
    mov r4, #0
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_027045B8
@lbl_027045A4:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_027045A4
@lbl_027045B8:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc2
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704614
@lbl_02704600:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704600
@lbl_02704614:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc3
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #2]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704670
@lbl_0270465C:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_0270465C
@lbl_02704670:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc4
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #4]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_027046CC
@lbl_027046B8:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_027046B8
@lbl_027046CC:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc5
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #6]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704728
@lbl_02704714:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704714
@lbl_02704728:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc6
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #8]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r7, =0x82dc
    mov r0, r7
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704784
@lbl_02704770:
    mov r0, r7
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704770
@lbl_02704784:
    mov r0, r6
    mov r1, r5
    mov r2, r4
    mov r3, #0xc7
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    mov r1, r4
    bl func_02704BE0
    cmp r0, #0
    moveq r0, #5
    streq r4, [r8, #4]
    movne r0, r4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}


asm void func_027047C0(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x28
    ldr r2, =DAT_02150fec
    mov r7, r0
    ldr r0, [r2, #4]
    mov r6, r1
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    add r5, sp, #8
    mov r4, #1
    add r1, sp, #0
    mov r0, r5
    mov r2, r4
    bl func_02085D94
    ldr r2, =func_02704B58
    mov r0, r7
    mov r1, r6
    mov r3, r5
    bl func_027044F8
    str r0, [sp, #4]
    cmp r0, #0
    bne @lbl_02704830
    add r1, sp, #4
    mov r0, r5
    mov r2, r4
    bl func_02085E50
@lbl_02704830:
    ldr r0, =DAT_02734450
    mov r1, #0
    str r1, [r0, #0x18]
    str r1, [r0, #4]
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}


asm void func_02704858(void) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x28
    bl func_02087B20
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r0, =DAT_02150fec
    ldr r0, [r0, #4]
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r0, =DAT_02734450
    ldr r1, [r0, #0xc]
    cmp r1, #4
    beq @lbl_027048B4
    bl func_02704C5C
    str r0, [sp, #4]
    cmp r0, #0
    beq @lbl_027048C8
    add sp, sp, #0x28
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_027048B4:
    ldr r0, [r0, #0xc]
    cmp r0, #5
    addeq sp, sp, #0x28
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, pc}
@lbl_027048C8:
    add r6, sp, #8
    mov r5, #1
    add r1, sp, #0
    mov r0, r6
    mov r2, r5
    bl func_02085D94
    mov r4, #0
    ldr r0, =func_02704B58
    mov r1, r6
    mov r2, r4
    mov r3, #0xfb
    bl func_02704D48
    ldr r0, =DAT_02734450
    mov r1, r4
    ldrb r0, [r0, #0x58]
    bl func_02704B74
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #5
    ldmeqfd sp!, {r4, r5, r6, pc}
    add r1, sp, #4
    mov r0, r6
    mov r2, r5
    bl func_02085E50
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r4, r5, r6, pc}
}
