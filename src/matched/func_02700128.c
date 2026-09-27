/*
 * function: func_02700128
 * address:  0x02700128
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_02700128(void) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_02700160
    b @lbl_02700148
    b @lbl_02700148
    b @lbl_02700150
    b @lbl_02700158
    b @lbl_02700158
@lbl_02700148:
    mov r0, #0
    bx lr
@lbl_02700150:
    mov r0, #3
    bx lr
@lbl_02700158:
    mov r0, #0
    bx lr
@lbl_02700160:
    mov r0, #0
    bx lr
}
