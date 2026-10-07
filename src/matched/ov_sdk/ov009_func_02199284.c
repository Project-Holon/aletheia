/*
 * function: func_02199284
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
 *   g_021A5A7C  0x021A5A7C  data
 */

#include "../include/G_Magic6.h"

extern struct Magic6 g_021A5A7C;
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);

int func_02199284(const u8 *a)
{
    return func_020923F0(a, (const u8 *)((char *)&g_021A5A7C), 6) == 0;
}

