/*
 * function: func_02704D74
 * address:  0x02704D74
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
 *   func_02087A04  0x02087A04  code twl
 *   func_02088688  0x02088688  code twl
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];
extern void func_02087A04(u32);
extern void func_02088688(void);

asm void func_02704D74(void) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r4, =DAT_02734450
    ldr r0, [r4, #0x18]
    cmp r0, #0
    ldmeqfd sp!, {r3, r4, r5, pc}
    ldr r5, =0x82dc
@lbl_02704D8C:
    mov r0, r5
    bl func_02087A04
    bl func_02088688
    ldr r0, [r4, #0x18]
    cmp r0, #0
    bne @lbl_02704D8C
    ldmfd sp!, {r3, r4, r5, pc}
}
