/*
 * function: CheckMagic
 * address:  0x02199284
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set when the six-byte test of the object at 0x021A5A7C fails.
 *
 * symbols:
 *   gNatNegMagic  0x021A5A7C  data
 */

#include "../include/G_Magic6.h"

extern struct Magic6 gNatNegMagic;
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);

int CheckMagic(const u8 *a)
{
    return func_020923F0(a, (const u8 *)((char *)&gNatNegMagic), 6) == 0;
}

