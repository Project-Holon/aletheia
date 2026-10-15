/*
 * function: WIFIBATTLEMATCH_NET_DeleteRegSprite
 * address:  0x021D98B8
 * packet:   pkt_021D98B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeletePartyWindow  0x021E82BC  thumb  ov177
 *
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */
#include "../include/Obj14330.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *p);

void WIFIBATTLEMATCH_NET_DeleteRegSprite(char *obj)
{
    u32 p = ((struct Obj14330 *)obj)->f24;
    if (p != 0) {
        WIFIBATTLEMATCH_VIEW_DeletePartyWindow((char *)p);
        ((struct Obj14330 *)obj)->f24 = 0;
    }
}

