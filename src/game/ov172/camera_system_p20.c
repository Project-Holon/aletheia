/*
 * file:     camera_system_p20.c
 * unit:     yes
 * function: func_021B6850, func_021B6858, func_021B6860
 * address:  0x021B6850
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B6850(void);
asm void func_021B6858(void);
asm void func_021B6860(void);

asm void func_021B6850(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FC90, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6858(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FC90
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6860(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}
