/*
 * function: func_02704E90
 * address:  0x02704E90
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_04004006   0x04004006  data twl
 *   func_02087A04  0x02087A04  arm twl
 *   func_02704F1C  0x02704F1C  arm twl
 */

typedef unsigned int u32;

extern u32 DAT_04004006[];
extern void func_02087A04(u32);
extern void func_02704F1C(void);

asm void func_02704E90(void) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r4, =DAT_04004006
    ldr r5, =0xfffe
    ldrh r0, [r4]
    sub r3, r4, #2
    sub r1, r5, #1
    and r0, r0, r5
    strh r0, [r4]
    ldrh r2, [r3]
    mov r0, #2
    and r1, r2, r1
    orr r1, r1, #2
    strh r1, [r3]
    bl func_02087A04
    ldrh r0, [r4]
    and r0, r0, r5
    orr r0, r0, #1
    strh r0, [r4]
    bl func_02704F1C
    ldmfd sp!, {r3, r4, r5, pc}
}
