/*
 * function: ISS_DUNGEON_SYS_DeleteTable
 * address:  0x0202B360
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the +4 pointer and then the object itself through the heap
 * release.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_DeleteTable.c \
 *       --func ISS_DUNGEON_SYS_DeleteTable --addr 0x0202B360 --thumb --cc 1.1p1
 */
#include "../include/Obj15832.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);

void ISS_DUNGEON_SYS_DeleteTable(u8 *p)
{
    func_020307B0(((struct Obj15832 *)p)->f4);
    func_020307B0(p);
}
