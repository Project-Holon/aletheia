/*
 * function: func_02704C5C
 * address:  0x02704C5C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02087988  0x02087988  code twl
 *   DAT_02734450   0x02734450  data twl
 *   func_0208799C  0x0208799C  code twl
 */

typedef unsigned int u32;

extern u32 func_02087988(void);
extern u32 DAT_02734450[];
extern void func_0208799C(u32);

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
