/*
 * function: WIFIBATTLEMATCH_NET_IsBoxReady
 * address:  0x021D63B0
 * packet:   pkt_021D63B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow  0x021E64C8  thumb  ov177
 *
 * Thunk: hands the +0x18 block to 0x021E64C8 and returns its result.  No
 *     lr save anywhere, so the compiler emitted the call as a pooled
 *     `ldr r3; bx r3` tail jump.
 */
#include "../include/Obj24228.h"

typedef unsigned long u32;

extern u32 WIFIBATTLEMATCH_VIEW_StepMainWindow(u32 p);

u32 WIFIBATTLEMATCH_NET_IsBoxReady(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindow(((struct Obj24228 *)obj)->f18);
}

