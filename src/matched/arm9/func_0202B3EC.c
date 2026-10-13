/*
 * function: ISS_DUNGEON_SYS_Delete
 * address:  0x0202B3EC
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs the destructor chain: ISS_DUNGEON_SYS_Stop, then releases the +0x14
 * sub-object and the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_Delete.c \
 *       --func ISS_DUNGEON_SYS_Delete --addr 0x0202B3EC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_DeleteTable  0x0202B360  thumb
 *   ISS_DUNGEON_SYS_Stop  0x0202B42C  thumb
 */
#include "../include/Obj15834.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_DUNGEON_SYS_Stop(u8 *a0);
extern void ISS_DUNGEON_SYS_DeleteTable(u8 *p);
extern u32 func_020307B0(void *p);

void ISS_DUNGEON_SYS_Delete(u8 *p)
{
    ISS_DUNGEON_SYS_Stop(p);
    ISS_DUNGEON_SYS_DeleteTable(*(u8 * *)&((struct Obj15834 *)p)->f14);
    func_020307B0(p);
}
