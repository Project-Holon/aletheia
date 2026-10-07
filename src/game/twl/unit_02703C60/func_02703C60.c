/*
 * function: func_02703C60
 * address:  0x02703C60
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: data_02150FEC and func_02703F60 (ABS32 at +0x74/+0x78) have no
 *   witness.  Both are twl bss objects (0x02732DA0..0x02735B40) with no ROM
 *   content, so sole-ref/self has no word to compare, no pool word names them
 *   outside this range, and there is no layout/data_objects.txt row.
 *
 * symbols:
 *   func_02085D94  0x02085D94  arm twl
 *   func_02703CDC  0x02703CDC  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   data_02150FEC  0x02150FEC  data a1
 *   func_02703F60  0x02703F60  arm twl
 */

typedef unsigned int u32;

extern void func_02085D94(u32, u32, u32);
extern u32 func_02703CDC(u32, u32, u32);
extern void func_02085E50(u32, u32, u32);
extern u32 data_02150FEC[];
extern u32 func_02703F60[];

asm void func_02703C60(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x28
    ldr r1, =data_02150FEC
    mov r6, r0
    ldr r0, [r1, #4]
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #5
    ldmeqfd sp!, {r4, r5, r6, pc}
    add r5, sp, #8
    mov r4, #1
    add r1, sp, #0
    mov r0, r5
    mov r2, r4
    bl func_02085D94
    ldr r1, =func_02703F60
    mov r0, r6
    mov r2, r5
    bl func_02703CDC
    str r0, [sp, #4]
    cmp r0, #0
    bne @lbl_02703CC8
    add r1, sp, #4
    mov r0, r5
    mov r2, r4
    bl func_02085E50
@lbl_02703CC8:
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r4, r5, r6, pc}
}
