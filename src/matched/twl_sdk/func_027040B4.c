/*
 * function: func_027040B4
 * address:  0x027040B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm twl a2
 *   func_02088610  0x02088610  arm twl a2
 */

typedef unsigned int u32;

extern void func_020862F0(u32, u32);
extern int func_02088610(u32, u32, u32);

asm void func_027040B4(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r1, #0x800
    mov r4, r0
    bl func_020862F0
    mov r6, r4, lsr #5
    mov r5, #0x14
    mov r4, #0
@lbl_027040D0:
    mov r0, r5
    mov r1, r6
    mov r2, r4
    bl func_02088610
    cmp r0, #0
    dcd 0xbafffff9
    ldmfd sp!, {r4, r5, r6, pc}
}
