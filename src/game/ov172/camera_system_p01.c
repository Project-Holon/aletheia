/*
 * file:     camera_system_p01.c
 * unit:     yes
 * function: func_021B62B0, func_021B62B8, func_021B62C0
 * address:  0x021B62B0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B62B0(void);
asm void func_021B62B8(void);
asm void func_021B62C0(void);

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700CB4, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62B0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700CB4
}

asm void func_021B62B8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02701248
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027017DC, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62C0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027017DC
}
