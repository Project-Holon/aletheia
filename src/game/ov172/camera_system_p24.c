/*
 * file:     camera_system_p24.c
 * unit:     yes
 * function: func_021B6918, func_021B6920, func_021B6928, func_021B6930
 * address:  0x021B6918
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B6918(void);
asm void func_021B6920(void);
asm void func_021B6928(void);
asm void func_021B6930(void);


/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027020F0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6918(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027020F0
}



asm void func_021B6920(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02702158
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027022F8, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6928(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027022F8
}

asm void func_021B6930(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0270229C
}
