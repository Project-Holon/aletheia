/*
 * file:     wf2dmap_actor_find.c
 * function: WF2DMAP_ACTOR_FIND_HasMatch
 * address:  0x021C5550
 * packet:   pkt_021C5550
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WF2DMAP_OBJ_FindAtPos  0x021C4BA4  thumb
 *
 * Addresses are Black-image addresses.
 */

#include "../types.h"
#include "wf2dmap_obj.h"

int WF2DMAP_ACTOR_FIND_HasMatch(void *target, void *list, int index)
{
    return WF2DMAP_OBJ_FindAtPos(target, list, index) != 0;
}
