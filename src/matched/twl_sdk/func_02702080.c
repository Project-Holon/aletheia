/*
 * function: func_02702080
 * address:  0x02702080
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087A04  0x02087A04  arm twl a2
 */

typedef unsigned int u32;

extern void func_02087A04(u32);

asm void func_02702080(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r4, [pc, #0x58]
    mov r5, #0x1e
    ldrh r0, [r4]
    add r6, r4, #0x1fc
    mov r1, #0
    orr r0, r0, #4
    strh r0, [r4]
    mov r0, r5
    strh r1, [r6]
    bl func_02087A04
    ldrh r1, [r4]
    mov r0, r5
    orr r1, r1, #0x100
    strh r1, [r4]
    bl func_02087A04
    mov r1, #0x22
    ldr r0, [pc, #0x1c]
    strh r1, [r6]
    bl func_02087A04
    ldrh r1, [r4]
    ldr r0, [pc, #0x10]
    and r0, r1, r0
    strh r0, [r4]
    ldmfd sp!, {r4, r5, r6, pc}
    streq r4, [r0], #-4
    dcd 0x00002008
    dcd 0x0000FEFF
}
