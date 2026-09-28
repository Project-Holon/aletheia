/*
 * function: func_01FF852C
 * address:  0x01FF852C
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

asm void func_01FF852C(u32 data, void *destp, u32 size)
{
    add ip, r1, r2
_loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt _loop
    bx lr
}
