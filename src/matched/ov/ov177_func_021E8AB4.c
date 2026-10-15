/*
 * function: WIFIBATTLEMATCH_UTIL_SetRequest
 * address:  0x021E8AB4
 * packet:   pkt_021E8AB4
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter after WIFIBATTLEMATCH_UTIL_ClearCallback's pool: stores the second argument at
 * +0xc. Called from the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D7EF6, 0x021D8060,
 * 0x021D8550).
 */
#include "../include/Obj24454.h"

typedef unsigned int u32;

void WIFIBATTLEMATCH_UTIL_SetRequest(u32 sys, u32 v)
{
    ((struct Obj24454 *)sys)->fC = v;
}
