/*
 * function: func_02703F04
 * address:  0x02703F04
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
 *   func_02704088  0x02704088  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 */

typedef unsigned int u32;

extern u32 func_0208B7B0(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 func_02704088(void);
extern u32 func_02085DBC(u32, u32, u32);

asm void func_02703F04(u32 a0, u32 a1) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r1
    bl func_0208B7B0
    mov r4, r0
    bl func_02087988
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02703F34
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_02703F34:
    mov r1, #1
    str r1, [r4]
    bl func_0208799C
    str r6, [r4, #4]
    str r5, [r4, #8]
    bl func_02704088
    cmp r0, #0
    mov r0, #0
    streq r0, [r4]
    moveq r0, #3
    ldmfd sp!, {r4, r5, r6, pc}
    mov r2, r0
    mov r0, r1
    mov r1, r2
    ldr ip, [pc, #4]
    mov r2, #0
    bx ip
    dcd func_02085DBC
}
