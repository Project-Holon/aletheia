/*
 * function: ISS_SYS_CreateDungeon
 * address:  0x0202B624
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker ISS_DUNGEON_SYS_Create.c is now a manifest entry (matched class)
 *
 * Builds the +0x18 sub-object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_CreateDungeon.c \
 *       --func ISS_SYS_CreateDungeon --addr 0x0202B624 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_Create  0x0202B3A0  thumb
 *   ISS_SYS_GetLocation  0x0202B7F8  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void *ISS_SYS_GetLocation(struct Obj *o);
struct Node;
extern struct Node *ISS_DUNGEON_SYS_Create(u32 a, u32 b, u32 heapId);

void ISS_SYS_CreateDungeon(struct Obj *o)
{
    ((struct Obj00563 *)o)->f18 = (u32)ISS_DUNGEON_SYS_Create(((struct Obj00563 *)o)->f4,
                                             (u32)ISS_SYS_GetLocation(o), ((struct Obj00563 *)o)->f0);
}
