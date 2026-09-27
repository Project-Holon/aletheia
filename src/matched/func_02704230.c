/*
 * function: func_02704230
 * address:  0x02704230
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_027343e0   0x027343e0  data twl
 *   DAT_0273442c   0x0273442c  data twl
 *   func_02086078  0x02086078  code twl
 */

typedef unsigned int u32;

extern u32 DAT_027343e0[];
extern u32 DAT_0273442c[];
extern void func_02086078(u32);

asm void func_02704230(u32 a0) {
    stmdb sp!, {r3, lr}
    ldr r1, =DAT_027343e0
    ldr r1, [r1, #0x64]
    cmp r0, r1
    ldmnefd sp!, {r3, pc}
    ldr r0, =DAT_0273442c
    bl func_02086078
    ldmfd sp!, {r3, pc}
}
