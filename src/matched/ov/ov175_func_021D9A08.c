/*
 * function: WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone
 * address:  0x021D9A08
 * packet:   pkt_021D9A08
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
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  WIFIBATTLEMATCH_NET_DeleteCompSprite is
 *     the matching free path for the same field.
 */
#include "../include/Obj24309.h"

typedef unsigned long u32;

extern int WIFIBATTLEMATCH_UTIL_UpdateMenu(u32 p);

int WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(char *obj)
{
    u32 p = ((struct Obj24309 *)obj)->f30;

    if (p != 0)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu(p);
    return -1;
}

