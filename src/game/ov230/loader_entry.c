/*
 * file:     loader_entry.c
 * function: LOADER_ENTRY_Start
 * address:  0x021889B0
 * packet:   pkt_ov230_021889B0
 * region:   ov230
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     position-independent entry: r0 = pc + 4 (0x021889BC, the
 *           descriptor table that follows the code), always nonzero, so the
 *           bne reaches the decoder LOADER_DECRYPT_DecodeBlocks (loader_decrypt.c) with r0
 *           naming the table. The 40 bytes after the bne are that table
 *           (four {0x02189EC0+k*0x3C, 0x0218AFC4} pairs and a zero word pair),
 *           data rather than code; it is written out here as DCD words. The decoder at 0x02188A48 is now filed in
 *           loader_decrypt.c, so the bne resolves and the file is EXACT.
 *
 * symbols:
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

#include "loader_decrypt.h"

/* hand-written in the original: position-independent entry reading pc (orr r0, pc, #0), followed by its range table (four biased start/end pairs, then the terminator) */
asm void LOADER_ENTRY_Start(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     LOADER_DECRYPT_DecodeBlocks
    DCD     0x02189EC0
    DCD     0x0218AFC4
    DCD     0x02189EFC
    DCD     0x0218AFC4
    DCD     0x02189F38
    DCD     0x0218AFC4
    DCD     0x02189F74
    DCD     0x0218AFC4
    DCD     0x00000000
    DCD     0x00000000
}
