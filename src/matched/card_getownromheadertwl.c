/*
 * function: CARD_GetOwnRomHeaderTWL
 * address:  0x02075E04
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (12 bytes):
 *   ldr r0, [pc]
 *   bx  lr
 *   .word 0x02FFE000
 *
 * TWL ROM header mapped at a fixed address, materialised from a literal
 * pool with no relocation.
 */

void *CARD_GetOwnRomHeaderTWL(void)
{
    return (void *)0x02FFE000;
}
