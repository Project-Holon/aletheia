/*
 * function: WIFIBATTLEMATCH_NET_SetCompWaitCallback
 * address:  0x021D9A1C
 * packet:   pkt_021D9A1C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback  0x021E8AA0  thumb  ov177
 *
 * Closes the +0x3c stream handle through 0x021E8AA0 and parks the +0x40
 *     result word at the 0xFFFF sentinel.  Mirrors WIFIBATTLEMATCH_NET_SetWaitCallback.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);

void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *obj, void *fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback((int *)(((struct Obj00013 *)obj)->f3C), (int)fn);
    ((struct Obj00013 *)obj)->f40 = 0xFFFF;
}

