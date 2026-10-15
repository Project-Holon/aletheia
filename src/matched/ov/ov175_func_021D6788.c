/*
 * function: WIFIBATTLEMATCH_NET_SetWaitCallback
 * address:  0x021D6788
 * packet:   pkt_021D6788
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWindow   0x021E7710  thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback   0x021E8AA0  thumb
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback   0x021E8A80  thumb
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull   0x021E8A90  thumb
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow   0x021E64C8  thumb
 *   WIFIBATTLEMATCH_UTIL_ClearCallback   0x021E8AA8  thumb
 *
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
#include "../include/Obj01562.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_UTIL_SetCallback(u32 sys, void *fn);

void WIFIBATTLEMATCH_NET_SetWaitCallback(char *obj, void *fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback(((struct Obj01562 *)obj)->f38, fn);
    ((struct Obj01562 *)obj)->f3C = 0xFFFF;
}

