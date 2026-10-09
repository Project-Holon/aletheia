/*
 * file:     unit_0273042C_p02.c
 * unit:     yes
 * function: func_027312D0, func_027312F8
 * address:  0x027312D0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_027312D0(void);
asm void func_027312F8(void);

asm void func_027312D0(void)
{
    ldr r0, =0x02FFFDFC
    ldr r0, [r0]
    ldr r0, [r0]
    mov r0, r0, lsl #0x1c
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}

asm void func_027312F8(void)
{
    ldr r0, =0x02FFFD68
    ldrb r0, [r0, #4]
    mov r0, r0, lsl #0x1f
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}
