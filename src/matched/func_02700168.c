/*
 * function: func_02700168
 * address:  0x02700168
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_02700168(void) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_027001B0
    b @lbl_02700188
    b @lbl_02700190
    b @lbl_02700198
    b @lbl_027001A0
    b @lbl_027001A8
@lbl_02700188:
    mov r0, #0
    bx lr
@lbl_02700190:
    mvn r0, #1
    bx lr
@lbl_02700198:
    mov r0, #1
    bx lr
@lbl_027001A0:
    mvn r0, #0
    bx lr
@lbl_027001A8:
    mov r0, #2
    bx lr
@lbl_027001B0:
    mov r0, #0
    bx lr
}
