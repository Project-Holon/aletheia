/*
 * function: sub_0202F170
 * address:  0x0202F170
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A03C8      0x020A03C8  data
 *
 * Index of the entry whose first field matches, 0 when there is none.
 * Unsigned loop here, signed in sub_0202F144.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F170.c \
 *       --func sub_0202F170 --addr 0x0202F170 --cc 1.1p1 --thumb
 */

#include "../include/G_020A03C8.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern struct G_020A03C8 g_020A03C8[];

u32 sub_0202F170(u16 key)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (g_020A03C8[i].a == key)
            return i;
    }
    return 0;
}
