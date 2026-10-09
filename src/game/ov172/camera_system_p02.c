/*
 * file:     camera_system_p02.c
 * unit:     yes
 * function: func_021B62A8, func_021B62B0, func_021B62B8, func_021B62C0, func_021B62C8, func_021B62D0, func_021B62D8, func_021B62E0, func_021B62E8, func_021B62F0, func_021B62F8, func_021B6300, func_021B6308, func_021B6310, func_021B6318, func_021B6320, func_021B6328, func_021B6330
 * address:  0x021B62A8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_021B62A8(void);
asm void func_021B62B0(void);
asm void func_021B62B8(void);
asm void func_021B62C0(void);
asm void func_021B62C8(void);
asm void func_021B62D0(void);
asm void func_021B62D8(void);
asm void func_021B62E0(void);
asm void func_021B62E8(void);
asm void func_021B62F0(void);
asm void func_021B62F8(void);
asm void func_021B6300(void);
asm void func_021B6308(void);
asm void func_021B6310(void);
asm void func_021B6318(void);
asm void func_021B6320(void);
asm void func_021B6328(void);
asm void func_021B6330(void);





/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02700938, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62A8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02700938
}






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




/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0270218C, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62F0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0270218C
}




/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02730B04, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B62F8(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730B04
}




asm void func_021B6300(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730FBC
}




asm void func_021B6308(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730FBC
}




asm void func_021B6310(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730B04
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02730FBC, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6318(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730FBC
}



asm void func_021B6320(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02730FBC
}



/*
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0270723C, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */
asm void func_021B6328(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0270723C
}

asm void func_021B6330(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02707278
}
