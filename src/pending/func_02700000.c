/*
 * function: func_02700000
 * address:  0x02700000
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   data_02FFFDEC  0x02FFFDEC  data twl a2
 *   func_020889F8  0x020889F8  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02FFFDEC[];
extern void *func_020889F8(void);

asm void func_02700000(void) {
    stmdb sp!, {r3, lr}
    bl func_020889F8
    ldr r1, [r0, #0x14]
    mov ip, #0
    cmp r1, #0x10
    beq @lbl_0270002C
    cmp r1, #0x11
    beq @lbl_02700050
    cmp r1, #0x12
    beq @lbl_0270006C
    b @lbl_02700064
@lbl_0270002C:
    ldr r3, =data_02FFFDEC
    ldr r0, [r0, #8]
    ldrb r2, [r3]
    ldrb r1, [r3, #1]
    ldrb r3, [r3, #2]
    orr r1, r2, r1, lsl #8
    orr r1, r1, r3, lsl #16
    str r1, [r0]
    b @lbl_0270006C
@lbl_02700050:
    ldr r1, =data_02FFFDEC
    ldr r0, [r0, #8]
    ldrh r1, [r1]
    strh r1, [r0]
    b @lbl_0270006C
@lbl_02700064:
    str ip, [r0, #0x18]
    mov ip, #4
@lbl_0270006C:
    mov r0, ip
    ldmfd sp!, {r3, pc}
}
