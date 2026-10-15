/*
 * function: TPOKE_DATA_GetRecordIndex
 * address:  0x0202A188
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns the halfword at entry i (times 8 plus 6) of the +0 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TPOKE_DATA_GetRecordIndex.c \
 *       --func TPOKE_DATA_GetRecordIndex --addr 0x0202A188 --thumb --cc 1.1p1
 *
 * symbols:
 *   TPOKE_DATA_GetEntryIndex  0x0202A20C  thumb
 */
#include "../include/Obj15808.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 v2, u32 v3);

u32 TPOKE_DATA_GetRecordIndex(u8 *p, u32 a, u32 v2, u32 v3)
{
    u32 i = TPOKE_DATA_GetEntryIndex(p, a, v2, v3);

    return *(u16 *)(((struct Obj15808 *)p)->f0 + i * 8 + 6);
}
