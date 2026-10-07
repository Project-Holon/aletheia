/*
 * function: func_021B655C
 * address:  0x021B655C
 * packet:   pkt_ov172_021B655C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the pointer
 * word 0x02706174, the arm half of the overlay's import table into the
 * TWL region.  No C spelling produces it, so it is written as an asm
 * function like the other veneers under src/matched/ov.
 *
 * Addresses are Black-image addresses.
 */

asm void func_021B655C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02706174
}
