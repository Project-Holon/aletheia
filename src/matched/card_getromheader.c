/*
 * function: CARD_GetRomHeader
 * address:  0x02075DEC
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
 *   .word 0x02FFFA80
 *
 * The ROM header image is mapped at a fixed address; the return value is
 * that constant, materialised from a literal pool with no relocation.
 */

void *CARD_GetRomHeader(void)
{
    return (void *)0x02FFFA80;
}
