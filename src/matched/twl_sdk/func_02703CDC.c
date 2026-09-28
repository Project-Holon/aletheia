/*
 * function: func_02703CDC
 * address:  0x02703CDC
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208B7B0  0x0208B7B0  arm twl
 *   func_02087988  0x02087988  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   func_02703F7C  0x02703F7C  arm twl
 */

typedef unsigned int u32;

extern u32 func_0208B7B0(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 func_02703F7C(u32, u32, u32, u32);

asm void func_02703CDC(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    bl func_0208B7B0
    ldr r1, [r8, #8]
    mov r4, r0
    cmp r1, #0
    moveq r0, #2
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    ldr r0, [r8, #4]
    tst r0, #0x1f
    bne @lbl_02703D18
    tst r1, #0x1f
    beq @lbl_02703D20
@lbl_02703D18:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703D20:
    ldr r0, [r8]
    cmp r0, #5
    addls pc, pc, r0, lsl #2
    b @lbl_02703D78
    b @lbl_02703D48
    b @lbl_02703D50
    b @lbl_02703D58
    b @lbl_02703D60
    b @lbl_02703D68
    b @lbl_02703D70
@lbl_02703D48:
    mov r2, #0
    b @lbl_02703D80
@lbl_02703D50:
    mov r2, #1
    b @lbl_02703D80
@lbl_02703D58:
    mov r2, #2
    b @lbl_02703D80
@lbl_02703D60:
    mov r2, #3
    b @lbl_02703D80
@lbl_02703D68:
    mov r2, #5
    b @lbl_02703D80
@lbl_02703D70:
    mov r2, #7
    b @lbl_02703D80
@lbl_02703D78:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703D80:
    ldr r1, [r8, #0xc]
    cmp r1, #0x800
    bhi @lbl_02703DC0
    bhs @lbl_02703E04
    ldr r0, =0x3ff
    cmp r1, r0
    bhi @lbl_02703DB0
    bhs @lbl_02703E04
    sub r0, r0, #0x140
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DB0:
    add r0, r0, #0x180
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DC0:
    cmp r1, #0xb00
    bhi @lbl_02703DDC
    bhs @lbl_02703E04
    ldr r0, =0x83f
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DDC:
    ldr r0, =0xbff
    cmp r1, r0
    bhi @lbl_02703DF0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DF0:
    rsb r0, r0, #0x1c00
    cmp r1, r0
    beq @lbl_02703E04
@lbl_02703DFC:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703E04:
    ldr r0, [r8, #0x10]
    cmp r0, #0
    orrne r0, r2, #0x10
    biceq r0, r2, #0x10
    and r0, r0, #0xff
    bic r0, r0, #0x20
    and r5, r0, #0xff
    bl func_02087988
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02703E3C
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703E3C:
    mov r1, #1
    str r1, [r4]
    bl func_0208799C
    str r7, [r4, #4]
    str r6, [r4, #8]
    ldr r0, [r8, #0x14]
    ldr r6, [r8, #0x18]
    str r0, [r4, #0x10]
    ldr r2, [r8, #0xc]
    mov r3, r5
    ldmib r8, {r0, r1}
    str r6, [r4, #0x14]
    bl func_02703F7C
    cmp r0, #0
    mov r0, #0
    streq r0, [r4]
    moveq r0, #3
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
