/*
 * function: ISS_DUNGEON_SYS_SelectRecord
 * address:  0x0202B49C
 * packet:   pkt_0202B49C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_DUNGEON_SYS_ApplyTrack.c is now a manifest entry (matched class)
 *
 * Resolves the node's 0x14 descriptor into the 0x18 slot and, when that
 * succeeds, feeds the resolved handle and the key derived from the node's
 * second word to ISS_DUNGEON_SYS_ApplyTrack.
 *
 * symbols:
 *   ISS_DUNGEON_SYS_FindRecord  0x0202B374  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   ISS_DUNGEON_SYS_ApplyTrack  0x0202B2CC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_DUNGEON_SYS_SelectRecord.c \
 *       --func ISS_DUNGEON_SYS_SelectRecord --addr 0x0202B49C --thumb --cc 1.1p1
 */
#include "../include/Obj02009.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  ISS_DUNGEON_SYS_FindRecord(u32 desc, u32 id);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void ISS_DUNGEON_SYS_ApplyTrack(u8 *p, u32 idx);

void ISS_DUNGEON_SYS_SelectRecord(u8 *p, u32 id)
{
    u32 r = ISS_DUNGEON_SYS_FindRecord(((struct Obj02009 *)p)->f14, id);

    ((struct Obj02009 *)p)->f18 = r;
    if (r != 0) {
        ISS_DUNGEON_SYS_ApplyTrack((u8 *)(((struct Obj02009 *)p)->f18), GAME_DATA_GetSeason((const struct BigObj *)(((struct Obj02009 *)p)->f8)));
    }
}
