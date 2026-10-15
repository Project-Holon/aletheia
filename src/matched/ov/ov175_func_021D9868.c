/*
 * function: WIFIBATTLEMATCH_NET_IsCompCardReady
 * address:  0x021D9868
 * packet:   pkt_021D9868
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepRecordWindow  0x021E777C  thumb  ov177
 *
 * Thunk: hands the +0x20 block to 0x021E777C (ov177) and returns its result.
 */
#include "../include/Obj24304.h"

typedef unsigned long u32;

extern u32 WIFIBATTLEMATCH_VIEW_StepRecordWindow(u32 p);

u32 WIFIBATTLEMATCH_NET_IsCompCardReady(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepRecordWindow(((struct Obj24304 *)obj)->f20);
}
