/*
 * function: func_02702998
 * address:  0x02702998
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: data_02FFFC3C (ABS32 at +0xA0) has no witness.  It is a twl bss
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, and no pool word names it outside this range; there is
 *   no layout/data_objects.txt row for it either.
 *
 * symbols:
 *   func_02087C6C  0x02087C6C  arm twl
 *   data_02FFFC3C   0x02FFFC3C  data
 */

typedef unsigned int u32;

extern void func_02087C6C(u32);
extern u32 data_02FFFC3C[];

asm void func_02702998(u32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #8
    add r5, sp, #0
    mov r4, r0
    mov r0, r5
    bl func_02087C6C
    mov r1, #0
    mov r2, r1
@lbl_027029B8:
    ldrb r0, [r5, r1]
    add r1, r1, #1
    cmp r1, #6
    add r0, r2, r0
    mov r0, r0, lsl #0x10
    mov r2, r0, lsr #0x10
@lbl_dcd:
    dcd 0xbafffff8
    ldr r0, =data_02FFFC3C
    mov r1, #0xd
    ldr r0, [r0]
    ldr r3, =0x66666667
    mov r0, r0, lsl #0x10
    add r0, r2, r0, lsr #16
    mov r0, r0, lsl #0x10
    mov r2, r0, lsr #0x10
    mul r0, r2, r1
    cmp r4, #1
    smull r2, r4, r3, r0
    mov r1, r0, lsr #0x1f
    mov r3, #0xa
    addeq r4, r1, r4, asr #2
    smulleq r1, r2, r3, r4
    subeq r4, r0, r1
    addeq r0, r4, #0x1e
    addne r4, r1, r4, asr #2
    smullne r1, r2, r3, r4
    subne r4, r0, r1
    addne r0, r4, #0x69
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, pc}
}
