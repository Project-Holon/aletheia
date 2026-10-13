/*
 * function: ISS_DUNGEON_SYS_Activate
 * address:  0x0202B47C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object is idle, marks it active and resolves its current
 * record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_Activate.c \
 *       --func ISS_DUNGEON_SYS_Activate --addr 0x0202B47C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_SelectRecord  0x0202B49C  thumb
 */
#include "../include/Obj02009.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ISS_DUNGEON_SYS_SelectRecord(u8 *p, u32 id);

void ISS_DUNGEON_SYS_Activate(u8 *p)
{
    if (((struct Obj02009 *)p)->fC == 0) {
        ((struct Obj02009 *)p)->fC = 1;
        ISS_DUNGEON_SYS_SelectRecord(p, ((struct Obj02009 *)p)->f10);
    }
}
