/*
 * function: WIFIBATTLEMATCH_NET_DeleteTradeIcon
 * address:  0x021D97A4
 * packet:   pkt_021D97A4
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
 *   POKETRADE_2D_DeleteMarkingIcon   0x021E5EF8  thumb  ov119
 *   WIFIBATTLEMATCH_VIEW_DrawStatusWindow   0x021E5F24  thumb
 *
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line carries the ov177 hint that the
 *     image's call to it there fixes.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void POKETRADE_2D_DeleteMarkingIcon(void *p);

void WIFIBATTLEMATCH_NET_DeleteTradeIcon(char *obj)
{
    u32 p = ((struct Obj00013 *)obj)->f1C;

    if (p != 0) {
        POKETRADE_2D_DeleteMarkingIcon((void *)p);
        ((struct Obj00013 *)obj)->f1C = 0;
    }
}

