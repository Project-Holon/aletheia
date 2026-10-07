/*
 * file:     camera_system_p02.c
 * unit:     yes
 * function: func_021B62C8, func_021B62D0, func_021B62D8, func_021B62E0, func_021B62E8
 * address:  0x021B62C8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B62C8(void);
asm void func_021B62D0(void);
asm void func_021B62D8(void);
asm void func_021B62E0(void);
asm void func_021B62E8(void);

asm void func_021B62C8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02701908
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700DB8, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62D0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700DB8
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x027000F8, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62D8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027000F8
}

asm void func_021B62E0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700108
}

/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700118, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62E8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700118
}
