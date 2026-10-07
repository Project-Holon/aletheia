/*
 * file:     unit_02704364_p02.c
 * unit:     yes
 * function: func_02704BE0, func_02704C5C, func_02704CC4, func_02704D48
 * address:  0x02704BE0
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
 *   func_02087988  0x02087988  arm twl
 *   func_02088610  0x02088610  arm twl
 *   DAT_02734450   0x02734450  data twl
 *   func_0208799C  0x0208799C  arm twl
 */
typedef unsigned int u32;

extern u32 func_02087988(void);
extern u32 func_02088610(u32, u32, u32);
extern void func_0208799C(u32);
asm void func_02704BE0(u32 a0, u32 a1);
asm void func_02704C5C(void);
asm void func_02704CC4(u32 a0);
asm void func_02704D48(u32 a0, u32 a1, u32 a2, u32 a3);
extern u32 DAT_02734450[];


asm void func_02704BE0(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r6, r1
    bl func_02087988
    mov r1, r7, lsl #16
    mov r5, #0
    mov r4, r0
    and r1, r1, #0xff0000
    mov r0, r6, lsl #16
    mov r2, r5
    orr r1, r1, r0, lsr #16
    mov r0, #0x18
    bl func_02088610
    cmp r0, #0
    bge @lbl_02704C38
    ldr r1, =DAT_02734450
    mov r2, #2
    mov r0, r4
    str r2, [r1, #0xc]
    bl func_0208799C
    mov r0, r5
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
@lbl_02704C38:
    cmp r7, #0xc7
    ldreq r0, =DAT_02734450
    moveq r1, #1
    streq r1, [r0, #0x18]
    mov r0, r4
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}


asm void func_02704C5C(void) {
    stmdb sp!, {r3, lr}
    bl func_02087988
    ldr r1, =DAT_02734450
    ldr r1, [r1, #0xc]
    cmp r1, #5
    addls pc, pc, r1, lsl #2
    b @lbl_02704CA8
    b @lbl_02704C90
    b @lbl_02704C90
    b @lbl_02704CA8
    b @lbl_02704C9C
    b @lbl_02704C9C
    b @lbl_02704C9C
@lbl_02704C90:
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r3, pc}
@lbl_02704C9C:
    bl func_0208799C
    mov r0, #3
    ldmfd sp!, {r3, pc}
@lbl_02704CA8:
    ldr r1, =DAT_02734450
    mov r2, #3
    str r2, [r1, #0xc]
    bl func_0208799C
    mov r0, #0
    ldmfd sp!, {r3, pc}
}


asm void func_02704CC4(u32 a0) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r0
    bl func_02087988
    ldr r1, =DAT_02734450
    mov r4, r0
    ldrb r8, [r1, #0x58]
    ldr r5, [r1, #0x4c]
    ldr r6, [r1, #0x50]
    cmp r8, #0xc7
    moveq r0, #0
    streq r0, [r1, #0x18]
    streq r0, [r1, #4]
    mov r0, #0
    mov r1, r0
    mov r2, r0
    mov r3, r0
    bl func_02704D48
    cmp r8, #0xfb
    ldreq r0, =DAT_02734450
    moveq r1, #4
    streq r1, [r0, #0xc]
    ldrne r0, =DAT_02734450
    movne r1, #2
    strne r1, [r0, #0xc]
    mov r0, r4
    bl func_0208799C
    cmp r5, #0
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r7
    mov r1, r6
    blx r5
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}


asm void func_02704D48(u32 a0, u32 a1, u32 a2, u32 a3) {
    ldr ip, =DAT_02734450
    str r0, [ip, #0x4c]
    str r1, [ip, #0x50]
    str r2, [ip, #0x54]
    strb r3, [ip, #0x58]
    bx lr
}
