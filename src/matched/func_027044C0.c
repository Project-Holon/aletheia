/*
 * function: func_027044C0
 * address:  0x027044C0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085D3C  0x02085D3C  arm twl
 *   func_02704448  0x02704448  arm twl
 */

typedef unsigned int u32;

extern u32 func_02085D3C(void);
extern u32 func_02704448(u32, u32, u32, u32);

asm void func_027044C0(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r1
    mov r4, r2
    bl func_02085D3C
    cmp r0, #0
    moveq r0, #4
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r0, r6
    mov r1, r5
    mov r2, r4
    mov r3, #0
    bl func_02704448
    ldmfd sp!, {r4, r5, r6, pc}
}
