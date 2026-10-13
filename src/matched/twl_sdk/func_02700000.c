/*
 * function: RTCEXi_CommonCallback
 * address:  0x02700000
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 0x02FFFDEC is a fixed DSi hardware/ROM buffer address, so the original
 *   source read it through a cast constant (`ldr r3, =0x02FFFDEC`), the same
 *   shape as src/matched/func_01FF8460.c.  It is therefore a literal pool
 *   word, not a relocation, and needs no witness.
 *
 * symbols:
 *   func_020889F8  0x020889F8  arm twl a2
 */

typedef unsigned int u32;

extern void *func_020889F8(void);

asm void RTCEXi_CommonCallback(void) {
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
    ldr r3, =0x02FFFDEC
    ldr r0, [r0, #8]
    ldrb r2, [r3]
    ldrb r1, [r3, #1]
    ldrb r3, [r3, #2]
    orr r1, r2, r1, lsl #8
    orr r1, r1, r3, lsl #16
    str r1, [r0]
    b @lbl_0270006C
@lbl_02700050:
    ldr r1, =0x02FFFDEC
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
