/*
 * function: func_021B643C
 * address:  0x021B643C
 * packet:   pkt_021B62A8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x0272FCE0, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function, the same way the other hand-written bodies under src/matched
 * are; the pointer word is a plain constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 */

asm void func_021B643C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0272FCE0
}
