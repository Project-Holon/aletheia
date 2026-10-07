/*
 * file:     unit_02731718_p01.c
 * unit:     yes
 * function: func_02731754, func_02731760
 * address:  0x02731754
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_02731754(void);
asm void func_02731760(void);

asm void func_02731754(void)
{
    mov     r3, #0x60
    add     r3, r0
    mov     r2, #0
    str     r2, [r3]
    swi     0x24
    bx      lr
}

asm void func_02731760(void)
{
    swi     0x25
    bx      lr
}
