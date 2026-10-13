/*
 * function: ISS_DUNGEON_SYS_HasRecord
 * address:  0x0202B438
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when the object's +0x14 sub-object holds a record with the
 * given id, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_HasRecord.c \
 *       --func ISS_DUNGEON_SYS_HasRecord --addr 0x0202B438 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_FindRecord  0x0202B374  thumb
 */
#include "../include/Obj15837.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *ISS_DUNGEON_SYS_FindRecord(u8 *p, u32 id);

u32 ISS_DUNGEON_SYS_HasRecord(u8 *p, u32 id)
{
    u8 *q = *(u8 * *)&((struct Obj15837 *)p)->f14;

    if (q == 0) {
        return 0;
    }
    return ISS_DUNGEON_SYS_FindRecord(q, id) != 0 ? 1 : 0;
}
