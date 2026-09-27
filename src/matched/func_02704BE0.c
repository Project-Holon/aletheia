/*
 * function: func_02704BE0
 * address:  0x02704BE0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
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
extern u32 DAT_02734450[];
extern void func_0208799C(u32);

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
