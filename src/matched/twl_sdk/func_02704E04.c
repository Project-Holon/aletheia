/*
 * function: func_02704E04
 * address:  0x02704E04
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
 *   func_02704DB0  0x02704DB0  arm twl
 *   func_027044C0  0x027044C0  arm twl
 *   func_02087A04  0x02087A04  arm twl
 *   func_02088688  0x02088688  arm twl
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];
extern void func_02704DB0(u32);
extern u32 func_027044C0(u32, u32, u32);
extern void func_02087A04(u32);
extern void func_02088688(void);

asm void func_02704E04(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r4, =DAT_02734450
    ldr r0, [r4, #0x14]
    cmp r0, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r6, =func_02704DB0
    mov r5, #0
    b @lbl_02704E30
@lbl_02704E24:
    ldr r0, [r4, #8]
    add r0, r0, #1
    str r0, [r4, #8]
@lbl_02704E30:
    ldrb r0, [r4]
    mov r1, r6
    mov r2, r5
    bl func_027044C0
    cmp r0, #0
    beq @lbl_02704E54
    ldr r0, [r4, #8]
    cmp r0, #5
    dcd 0xbafffff3
@lbl_02704E54:
    ldr r4, =DAT_02734450
    ldr r0, [r4, #0x14]
    cmp r0, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldr r5, =0x82dc
@lbl_02704E68:
    mov r0, r5
    bl func_02087A04
    bl func_02088688
    ldr r0, [r4, #0x14]
    cmp r0, #0
    bne @lbl_02704E68
    ldmfd sp!, {r4, r5, r6, pc}
}
