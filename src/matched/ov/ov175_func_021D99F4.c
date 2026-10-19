/*
 * function: WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu
 * address:  0x021D99F4
 * packet:   pkt_021D99F4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteMainWindow   0x021E5D40  thumb
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu   0x021E89D0  thumb
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   WIFIBATTLEMATCH_VIEW_DrawStatusWindow   0x021E5F24  thumb
 *
 * Release path for the ov175 object's 0x30 block pointer: free it
 *     through 0x021E89D0 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_UTIL_DeleteMenu(u32 p);

void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *obj)
{
    u32 p = ((struct Obj00013 *)obj)->f30;

    if (p != 0) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu(p);
        ((struct Obj00013 *)obj)->f30 = 0;
    }
}

