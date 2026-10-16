/*
 * file:     os_protectionunit.c
 * unit:     yes
 * function: OS_EnableProtectionUnit, OS_DisableProtectionUnit
 * address:  0x02086CF4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void OS_EnableProtectionUnit(void);
asm void OS_DisableProtectionUnit(void);

asm void OS_EnableProtectionUnit(void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr	r0, r0, #1
    mcr p15, 0, r0, c1, c0, 0
    bx	lr
}

/*
 * sdk:      OS_DisableProtectionUnit (os_protectionunit.o)
 * asm:      needs mrc/mcr on cp15 c1 (no C spelling); the object agrees: no
 *           DW_TAG_variable and one strictly increasing line per instruction.
 */
asm void OS_DisableProtectionUnit(void)
{
    mrc     p15, 0, r0, c1, c0, 0
    bic     r0, r0, #1
    mcr     p15, 0, r0, c1, c0, 0
    bx      lr
}
