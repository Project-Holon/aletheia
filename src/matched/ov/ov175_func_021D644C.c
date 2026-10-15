/*
 * function: WIFIBATTLEMATCH_NET_DeleteRegCard
 * address:  0x021D644C
 * packet:   pkt_021D644C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWindow   0x021E7710  thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback   0x021E8AA0  thumb
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback   0x021E8A80  thumb
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull   0x021E8A90  thumb
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow   0x021E64C8  thumb
 *   WIFIBATTLEMATCH_UTIL_ClearCallback   0x021E8AA8  thumb
 *
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
#include "../include/Obj14327.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(u32 p);

void WIFIBATTLEMATCH_NET_DeleteRegCard(char *obj)
{
    u32 p = ((struct Obj14327 *)obj)->f1C;

    if (p != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(p);
        ((struct Obj14327 *)obj)->f1C = 0;
    }
}

