/*
 * file:     unit_0272E9E8_p02.c
 * unit:     yes
 * function: func_0272EBDC, func_0272EC38
 * address:  0x0272EBDC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

asm u32 func_0272EBDC(void *r0);
asm void func_0272EC38(void);

asm u32 func_0272EBDC(void *r0)
{
    ldr r2, [r0, #0x204]
    mov r1, #0x14
    mul r1, r2, r1
    add r1, r1, #0xff
    ldr r2, [r0, #0x1fc]
    ldr r0, [r0, #0x200]
    mov ip, #0
    add r2, r2, #0x1f
    mov r0, r0, lsl #5
    bic r3, r2, #0x1f
    add r2, r0, #0x1f
    add r1, r1, #0x500
    sub r0, ip, #0x600
    and r0, r1, r0
    mov r0, r0, lsl #2
    add r0, r0, #0x1f
    add r3, r3, #0
    bic r1, r2, #0x1f
    add r1, r3, r1
    bic r0, r0, #0x1f
    add r0, r1, r0
    add r0, r0, #0x260
    bx lr
}




asm void func_0272EC38(void)
{
}
