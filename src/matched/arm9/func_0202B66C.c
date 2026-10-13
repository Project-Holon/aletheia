/*
 * function: ISS_SYS_DeleteRoad
 * address:  0x0202B66C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0x14 field through ISS_ROAD_SYS_Delete (the OS_FreeToHeap thunk)
 * and clears it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_DeleteRoad.c \
 *       --func ISS_SYS_DeleteRoad --addr 0x0202B66C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ROAD_SYS_Delete  0x0202B1EC  thumb
 */
#include "../include/Obj02011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern void ISS_ROAD_SYS_Delete(void *ptr);

void ISS_SYS_DeleteRoad(struct Obj *o)
{
    ISS_ROAD_SYS_Delete((void *)(((struct Obj02011 *)o)->f14));
    ((struct Obj02011 *)o)->f14 = 0;
}
