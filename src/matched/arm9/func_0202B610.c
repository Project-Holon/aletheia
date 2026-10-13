/*
 * function: ISS_SYS_CreateCity
 * address:  0x0202B610
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker ISS_SYS_UpdateCity.c is now a manifest entry (matched class)
 *
 * Builds the +0x10 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_CreateCity.c \
 *       --func ISS_SYS_CreateCity --addr 0x0202B610 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_CITY_SYS_Create  0x0202AAF4  thumb
 *   ISS_SYS_GetLocation  0x0202B7F8  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void *ISS_SYS_GetLocation(struct Obj *o);
struct Node;
extern struct Node *ISS_CITY_SYS_Create(u32 a, void *heapId);

void ISS_SYS_CreateCity(struct Obj *o)
{
    ((struct Obj00563 *)o)->f10 = (u32)ISS_CITY_SYS_Create((u32)ISS_SYS_GetLocation(o), (void *)(((struct Obj00563 *)o)->f0));
}
