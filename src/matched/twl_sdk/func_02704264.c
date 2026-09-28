/*
 * function: func_02704264
 * address:  0x02704264
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   DAT_02734428   0x02734428  data twl
 *   DAT_02734420   0x02734420  data twl
 *   func_02087988  0x02087988  code twl
 *   func_020879EC  0x020879EC  code twl
 *   func_02088688  0x02088688  code twl
 *   func_02004490  0x02004490  code twl
 *   func_020857B0  0x020857B0  code twl
 *   func_0208799C  0x0208799C  code twl
 *   DAT_0273444c   0x0273444c  data twl
 */

typedef unsigned int u32;

extern u32 DAT_02734428[];
extern u32 DAT_02734420[];
extern u32 func_02087988(void);
extern u32 func_020879EC(void);
extern void func_02088688(void);
extern void func_02004490(u32);
extern void func_020857B0(u32);
extern void func_0208799C(u32);
extern u32 DAT_0273444c[];

asm void func_02704264(u32 a0) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r8, r0
    mov r6, #1
    ldr r5, =DAT_02734428
    mov r4, #0
    ldr r9, =DAT_02734420
    ldr r10, =0x2710
    b @lbl_02704300
@lbl_02704284:
    bl func_02087988
    mov r7, r0
    mov r1, r5
    b @lbl_027042C0
@lbl_02704294:
    ldr r0, [r1]
    cmp r0, r8
    bne @lbl_027042B8
    ldr r0, [r1]
    mov r6, r4
    ldr r0, [r0, #0xc]
    str r0, [r1]
    str r4, [r8, #0xc]
    b @lbl_027042CC
@lbl_027042B8:
    ldr r0, [r1]
    add r1, r0, #0xc
@lbl_027042C0:
    ldr r0, [r1]
    cmp r0, #0
    bne @lbl_02704294
@lbl_027042CC:
    cmp r6, #0
    beq @lbl_027042F8
    bl func_020879EC
    cmp r0, #0x12
    bne @lbl_027042F0
    bl func_02088688
    mov r0, r10
    dcd 0xfae40068
    b @lbl_027042F8
@lbl_027042F0:
    mov r0, r9
    bl func_020857B0
@lbl_027042F8:
    mov r0, r7
    bl func_0208799C
@lbl_02704300:
    cmp r6, #0
    bne @lbl_02704284
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
