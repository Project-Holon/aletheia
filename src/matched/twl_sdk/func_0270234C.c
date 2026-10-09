/*
 * function: func_0270234C
 * address:  0x0270234C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027022E0  0x027022E0  arm twl
 */

typedef unsigned int u32;

typedef signed int     s32;
extern s32 func_027022E0(void);

asm void func_0270234C(u32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    bl func_027022E0
    mov r1, r4, lsl #1
    mul r0, r1, r0
    ldmfd sp!, {r4, pc}
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b @lbl_027023C4
    b @lbl_0270238C
    b @lbl_02702394
    b @lbl_0270239C
    b @lbl_027023A4
    b @lbl_027023AC
    b @lbl_027023B4
    b @lbl_027023BC
@lbl_0270238C:
    mov r0, #0x280
    bx lr
@lbl_02702394:
    mov r0, #0x140
    bx lr
@lbl_0270239C:
    mov r0, #0xa0
    bx lr
@lbl_027023A4:
    mov r0, #0x160
    bx lr
@lbl_027023AC:
    mov r0, #0xb0
    bx lr
@lbl_027023B4:
    mov r0, #0x100
    bx lr
@lbl_027023BC:
    mov r0, #0x200
    bx lr
@lbl_027023C4:
    mov r0, #0
    bx lr
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b @lbl_0270242C
    b @lbl_027023F4
    b @lbl_027023FC
    b @lbl_02702404
    b @lbl_0270240C
    b @lbl_02702414
    b @lbl_0270241C
    b @lbl_02702424
@lbl_027023F4:
    mov r0, #0x1e0
    bx lr
@lbl_027023FC:
    mov r0, #0xf0
    bx lr
@lbl_02702404:
    mov r0, #0x78
    bx lr
@lbl_0270240C:
    mov r0, #0x120
    bx lr
@lbl_02702414:
    mov r0, #0x90
    bx lr
@lbl_0270241C:
    mov r0, #0xc0
    bx lr
@lbl_02702424:
    mov r0, #0x180
    bx lr
@lbl_0270242C:
    mov r0, #0
    bx lr
}
