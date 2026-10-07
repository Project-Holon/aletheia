/*
 * function: sub_0202F138
 * address:  0x0202F138
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   g_020A03C8      0x020A03C8  data
 *
 * First field of entry i of the 0x2E-entry table; the sibling lookups
 * sub_0202F144 (second field) and sub_0202F170 (index) share it.  All three
 * are unlabelled leaf functions in the 0x0202F114..0x0202F190 gap.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F138.c \
 *       --func sub_0202F138 --addr 0x0202F138 --cc 1.1p1 --thumb
 */

#include "../include/G_020A03C8.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern struct G_020A03C8 g_020A03C8[];

u16 sub_0202F138(u32 i)
{
    return g_020A03C8[i].a;
}
