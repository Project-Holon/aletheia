/*
 * function: func_02704D64
 * address:  0x02704D64
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02704D74  0x02704D74  code twl
 *   func_02704E04  0x02704E04  code twl
 */

typedef unsigned int u32;

extern void func_02704D74(void);
extern void func_02704E04(void);

asm void func_02704D64(void) {
    stmdb sp!, {r3, lr}
    bl func_02704D74
    bl func_02704E04
    ldmfd sp!, {r3, pc}
}
