/*
 * file:     camera_system_p07.c
 * unit:     yes
 * function: func_021B6564, func_021B656C, func_021B6574
 * address:  0x021B6564
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B6564(void);
asm void func_021B656C(void);
asm void func_021B6574(void);

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02706324, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function like the other veneers under src/matched/ov.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6564(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706324
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02706174, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function like the other veneers under src/matched/ov.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B656C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706174
}

asm void func_021B6574(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706324
}
