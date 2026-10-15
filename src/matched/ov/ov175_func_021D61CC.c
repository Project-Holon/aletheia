/*
 * function: WIFIBATTLEMATCH_NET_TaskCleanupB
 * address:  0x021D61CC
 * packet:   pkt_021D61CC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: the call to 0x021E8AA8 has no func_ label in any overlay listing
 * (it is an unlabelled leaf in the overlapping window: ov093/ov170/ov177 hold
 * code or a pool word at that address but none traces a function start), so
 * no evidence class attests it.  Every concrete byte matches; --suggest-split
 * cannot help because the site is a direct `bl` with no second caller.
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_DeleteNetContext  0x021D9EA0  thumb  ov175
 *   WIFIBATTLEMATCH_UTIL_ClearCallback  0x021E8AA8  thumb
 */
#include "../include/Obj10679.h"
typedef unsigned int u32;

typedef unsigned char  u8;
extern void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *p);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(void *a);

void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *p)
{
    if (*pp != 0)
        return;
    if (((struct Obj10679 *)p)->f30 != 0) {
        WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)(((struct Obj10679 *)p)->f30));
        ((struct Obj10679 *)p)->f30 = 0;
    }
    WIFIBATTLEMATCH_UTIL_ClearCallback(a);
}
