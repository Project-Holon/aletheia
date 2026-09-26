/*
 * function: func_02702A40
 * address:  0x02702A40
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   data_02702A8C  0x02702A8C  data twl a2
 *   data_027341A4  0x027341A4  data twl a2
 *   data_027341B8  0x027341B8  data twl a2
 *   func_0208C848  0x0208C848  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02702A8C[];
extern u32 data_027341A4[];
extern u32 data_027341B8[];
extern void func_0208C848(u32 *, u32, u32);

asm void func_02702A40(void) {
    ldr r3, =data_02702A8C
    ldr r2, =data_027341A4
    ldr r0, =data_027341B8
    str r3, [r2, #0x14]
    mov r3, #0
    ldr r1, =0x0000ffff
    ldr ip, =func_0208C848
    str r3, [r2, #0x18]
    bx ip
}
