/*
 * function: func_06899BA0
 * address:  0x06899BA0
 * packet:   pkt_ov095_06899BA0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A four-byte ARM long-branch veneer, `ldr pc, [pc, #-4]` over the word
 * 0x02030734, the arm9 function it jumps to. No C spelling produces it, so it is
 * written as an asm function, as in the ov172 veneers (ov172_func_021B62A8.c).
 * 2026-10-05 integrator: label left open after the pengy waves.
 */

asm void func_06899BA0(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02030734
}
