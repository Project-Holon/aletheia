/*
 * file:     unit_02004EB4.c
 * unit:     yes
 * function: func_02004EB4, func_02004ED4, func_02004F20
 * address:  0x02004EB4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void INITi_IsRunOnTwl(void);
asm void INITi_Copy32(void);
asm void INITi_Fill32(void);

asm void INITi_IsRunOnTwl(void)
{
    ldr r0, =0x04004000
    ldrb r0, [r0]
    and r0, r0, #3
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}

asm void INITi_Copy32(void)
{
    stmfd sp!, {r3-r11}
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    ldmneia r1!, {r4, r5, r6, r7}
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    ldmneia r1!, {r4, r5}
    stmneia r0!, {r4, r5}
    tst r2, #4
    ldmneia r1!, {r4}
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}

asm void INITi_Fill32(void)
{
    stmfd sp!, {r3-r11}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    mov r11, r1
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    stmneia r0!, {r4, r5}
    tst r2, #4
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}
