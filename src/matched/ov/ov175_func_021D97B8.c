/*
 * function: WIFIBATTLEMATCH_NET_IsTradeIconReady
 * address:  0x021D97B8
 * packet:   pkt_021D97B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E64C8  0x021E64C8  thumb  ov177
 *
 * Thunk: hands the +0x1c block to 0x021E64C8 and returns its result; the
 *     poll WIFIBATTLEMATCH_NET_SetupTradeIconAndWait spins on.
 */
#include "../include/Obj24302.h"

typedef unsigned long u32;

extern u32 func_021E64C8(u32 p);

u32 WIFIBATTLEMATCH_NET_IsTradeIconReady(char *obj)
{
    return func_021E64C8(((struct Obj24302 *)obj)->f1C);
}

