/*
 * function: ISS_DUNGEON_SYS_Update
 * address:  0x0202B404
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When the object is active and its +0x10 and +0x12 halfwords differ,
 * latches the new value and re-resolves the current record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_Update.c \
 *       --func ISS_DUNGEON_SYS_Update --addr 0x0202B404 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_SelectRecord  0x0202B49C  thumb
 */
#include "../include/Obj02009.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ISS_DUNGEON_SYS_SelectRecord(u8 *p, u32 id);

void ISS_DUNGEON_SYS_Update(u8 *p)
{
    u16 a;
    u16 b;

    if (((struct Obj02009 *)p)->fC == 0) {
        return;
    }
    a = ((struct Obj02009 *)p)->f10;
    b = ((struct Obj02009 *)p)->f12;
    if (a == b) {
        return;
    }
    ((struct Obj02009 *)p)->f10 = b;
    ISS_DUNGEON_SYS_SelectRecord(p, ((struct Obj02009 *)p)->f10);
}
