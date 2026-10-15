/*
 * function: WIFIBATTLEMATCH_NET_GetCompWaitResult
 * address:  0x021D9A30
 * packet:   pkt_021D9A30
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback  0x021E8A80  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull  0x021E8A90  thumb  ov177
 *
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors WIFIBATTLEMATCH_NET_GetWaitResult.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(u32 h);
extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p);

u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *obj)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(((struct Obj00013 *)obj)->f3C);
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)(((struct Obj00013 *)obj)->f3C)) != 0)
        return ((struct Obj00013 *)obj)->f40;
    return 0xFFFF;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * Identical blocker to WIFIBATTLEMATCH_NET_GetWaitResult: the call at +0x0C targets 0x021E8A90,
 * which is not a traced function label in any overlay listing.
 */
