/*
 * function: ISS_SYS_CreateRoad
 * address:  0x0202B5FC
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * Builds the +0x14 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_CreateRoad.c \
 *       --func ISS_SYS_CreateRoad --addr 0x0202B5FC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ROAD_SYS_Create  0x0202B1AC  thumb
 *   ISS_SYS_GetLocation  0x0202B7F8  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void *ISS_SYS_GetLocation(struct Obj *o);
struct Node;
extern struct Node *ISS_ROAD_SYS_Create(u32 a, u32 heapId);

void ISS_SYS_CreateRoad(struct Obj *o)
{
    ((struct Obj00563 *)o)->f14 = (u32)ISS_ROAD_SYS_Create((u32)ISS_SYS_GetLocation(o), ((struct Obj00563 *)o)->f0);
}
