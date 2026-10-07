/*
 * function: sub_0202F144
 * address:  0x0202F144
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
 * Second field of the entry whose first field matches the key, 0 when there
 * is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F144.c \
 *       --func sub_0202F144 --addr 0x0202F144 --cc 1.1p1 --thumb
 */

#include "../include/G_020A03C8.h"

typedef unsigned short u16;
typedef int            s32;
typedef unsigned int   u32;

extern struct G_020A03C8 g_020A03C8[];

u32 sub_0202F144(u32 key)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (g_020A03C8[i].a == key)
            return g_020A03C8[i].b;
    }
    return 0;
}
