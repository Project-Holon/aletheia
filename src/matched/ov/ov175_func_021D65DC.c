/*
 * function: WIFIBATTLEMATCH_NET_IsSpriteAnimDone
 * address:  0x021D65DC
 * packet:   pkt_021D65DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 *
 * Query brother of WIFIBATTLEMATCH_NET_DeleteSprite: returns the +0x28 block's handler
 *     result through 0x021E8A00, or -1 when the field is empty.
 */
#include "../include/Obj24230.h"

typedef unsigned long u32;

extern int func_021E8A00(u32 p);

int WIFIBATTLEMATCH_NET_IsSpriteAnimDone(char *obj)
{
    u32 p = ((struct Obj24230 *)obj)->f28;

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}

