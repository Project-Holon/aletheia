/*
 * function: func_027001B8
 * address:  0x027001B8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_027001B8(void) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_027001E8
    b @lbl_027001D8
    b @lbl_027001D8
    b @lbl_027001D8
    b @lbl_027001E0
    b @lbl_027001E0
@lbl_027001D8:
    mov r0, #0
    bx lr
@lbl_027001E0:
    mov r0, #2
    bx lr
@lbl_027001E8:
    mov r0, #0
    bx lr
}
