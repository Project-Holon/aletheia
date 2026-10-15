/*
 * function: BEACON_VIEW_SetEntryStatusVisible
 * address:  0x021F0ED0
 * packet:   pkt_021F0ED0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_SetEntryStatusVisible 0x021F0ED0 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj20418.h"

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void BEACON_VIEW_SetEntryStatusVisible(char *p, int a)
{
    CLACT_SetActorDrawEnable(((struct Obj20418 *)p)->f14, a);
}
