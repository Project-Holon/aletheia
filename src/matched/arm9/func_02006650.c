/*
 * function: func_02006650
 * address:  0x02006650
 * packet:   pkt_02006650
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: scans the first three records of a
 * 0x34-byte strided table for the word at +4 equal to 1.
 *
 * symbols:
 *   d_02140484  0x02140484  data
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_Sub02006544State.h"

typedef unsigned char u8;

extern struct Sub02006544State d_02140484;

int func_02006650(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (*(int *)(&(*(u8 *)&d_02140484) + i * 0x34 + 4) == 1)
            return 1;
    }
    return 0;
}
