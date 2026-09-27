/*
 * function: func_02704364
 * address:  0x02704364
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
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
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];
extern u32 func_02087988(void);
extern void func_0208799C(void);
extern void func_02704D48(u32, u32, u32, u32);
extern void func_02088498(void);
extern u32 func_020885EC(u32, u32);
extern void func_02004490(u32);
extern void func_020885A0(u32, u32);
extern u32 func_027049B0(void);
extern u32 func_02704D64(void);
extern u32 DAT_0273446c[];
extern void func_0273156C(u32, u32);
extern u32 DAT_0273448c[];
extern void func_0208C848(u32, u32);

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
