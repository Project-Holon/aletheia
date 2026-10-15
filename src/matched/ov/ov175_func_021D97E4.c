/*
 * function: WIFIBATTLEMATCH_NET_StartTradeIconAnim
 * address:  0x021D97E4
 * packet:   pkt_021D97E4
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
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void WIFIBATTLEMATCH_NET_StartTradeIconAnim(char *obj, u32 arg)
{
    if (((struct Obj00013 *)obj)->f1C != 0)
        WIFIBATTLEMATCH_VIEW_DrawStatusWindow(((struct Obj00013 *)obj)->f1C, arg, ((struct Obj00013 *)obj)->f14,
                      ((struct Obj00013 *)obj)->f10, ((struct Obj00013 *)obj)->f8, 0x57);
}

