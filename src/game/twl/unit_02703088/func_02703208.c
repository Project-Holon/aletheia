/*
 * function: func_02703208
 * address:  0x02703208
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;

asm u8 *func_02703208(u8 *a0, u8 a1) {
    stmdb sp!, {r3, lr}
    ldrh r2, [r0], #0x40
    add r2, r0, r2
    sub r3, r2, #0x40
    b @lbl_02703224
@lbl_0270321C:
    add r2, ip, #2
    add r0, r0, r2
@lbl_02703224:
    ldrb lr, [r0]
    cmp lr, r1
    beq @lbl_02703244
    ldrb ip, [r0, #1]
    add r2, r0, ip
    add r2, r2, #2
    cmp r2, r3
    bls @lbl_0270321C
@lbl_02703244:
    cmp lr, r1
    movne r0, #0
    ldmfd sp!, {r3, pc}
}
