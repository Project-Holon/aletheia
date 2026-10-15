/*
 * function: WIFIBATTLEMATCH_NET_DeleteBoxAndWait
 * address:  0x021D63DC
 * packet:   pkt_021D63DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_DeleteBoxRecord  0x021D639C  thumb
 *   WIFIBATTLEMATCH_NET_IsBoxAnimDone  0x021D63BC  thumb
 *
 * Only when the +0x18 pointer is live: spin on WIFIBATTLEMATCH_NET_IsBoxAnimDone until it
 *     reports ready, then hand the object to the WIFIBATTLEMATCH_NET_DeleteBoxRecord release path.
 */
#include "../include/Obj10680.h"

typedef unsigned long u32;

extern u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(char *obj);
extern void WIFIBATTLEMATCH_NET_DeleteBoxRecord(char *obj);

void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *obj)
{
    if (((struct Obj10680 *)obj)->f18 != 0) {
        while (WIFIBATTLEMATCH_NET_IsBoxAnimDone(obj) == 0)
            ;
        WIFIBATTLEMATCH_NET_DeleteBoxRecord(obj);
    }
}

