/*
 * function: func_02701A60
 * address:  0x02701A60
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088610  0x02088610  code twl a2
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;

extern s32 func_02088610(u32, u32, u32);

asm void func_02701A60(const u8 *ptr)
{
    stmdb   sp!, {r4, r5, r6, lr}
    ldrb    r1, [r0, #1]
    ldrb    r2, [r0, #0]
    ldrb    r3, [r0, #2]
    mov     r0, r1, lsl #8
    orr     r0, r0, r2, lsl #16
    orr     r6, r3, r0
    mov     r5, #0x15
    mov     r4, #0
loop:
    mov     r0, r5
    mov     r1, r6
    mov     r2, r4
    bl      func_02088610
    cmp     r0, #0
    blt     loop
    ldmfd   sp!, {r4, r5, r6, pc}
}
