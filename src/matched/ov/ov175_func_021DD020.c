/*
 * function: WIFIBATTLEMATCH_NET_GetGsProfileId
 * address:  0x021DD020
 * packet:   pkt_021DD020
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb  arm9
 *   (none)
 *
 * Tail call to the arm9 Thumb routine 0x02009CC0 with the object's
 *  *  +0x04 field; pooled `ldr r3; bx r3`, so nothing is saved.
 */
#include "../include/Obj24397.h"

typedef unsigned long u32;

extern int WIFILIST_GetGsProfileId(void *a0);

u32 WIFIBATTLEMATCH_NET_GetGsProfileId(char *obj)
{
    return WIFILIST_GetGsProfileId((void *)(((struct Obj24397 *)obj)->f4));
}

