/*
 * function: WORLDTRADE_DEPOSIT_FindLevelBracketIndex
 * address:  0x021F886C
 * packet:   pkt_021F886C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0220301C  0x0220301C  data
 *   g_02202FC4  0x02202FC4  data
 *
 * Index of a key/value pair in one of two s16 tables.
 */

#include "../include/G_0220301C.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef struct { u32 unk; s16 key; s16 val; } Entry;
extern struct G_0220301C g_0220301C[12];
extern Entry g_02202FC4[11];

int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which)
{
    int i;
    int n;
    Entry *tab;

    if (which == 0) {
        tab = ((Entry *)g_0220301C);
        n = 0xc;
    } else {
        tab = g_02202FC4;
        n = 0xb;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].val == val) {
            return i;
        }
    }
    return 0;
}

