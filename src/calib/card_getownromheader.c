/*
 * Calibration target, written from the disassembly only.
 *
 * function: CARD_GetOwnRomHeader
 * address:  0x02075DF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Original:
 *   ldr r0, [pc]       ; 0x02FFFE00
 *   bx  lr
 *   .word 0x02FFFE00
 *
 * A constant address rather than a relocated symbol, so this one can reach
 * EXACT: there is nothing for the linker to rewrite.  0x02FFFE00 is the
 * copy of the cartridge ROM header the boot code leaves in shared WRAM.
 */

void *CARD_GetOwnRomHeader(void)
{
    return (void *)0x02FFFE00;
}
