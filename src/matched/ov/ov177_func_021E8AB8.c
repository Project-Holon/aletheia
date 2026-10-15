/*
 * function: WIFIBATTLEMATCH_UTIL_CommitRequest
 * address:  0x021E8AB8
 * packet:   pkt_021E8AB8
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field copy after WIFIBATTLEMATCH_UTIL_SetRequest: the word at +0xc is stored to +4.
 * Called from ov175 at 0x021D5550 and from the root WIFIBATTLEMATCH_NET_CompStepF
 * (0x021D8858).
 */
#include "../include/Obj08290.h"

typedef unsigned int u32;

void WIFIBATTLEMATCH_UTIL_CommitRequest(u32 sys)
{
    ((struct Obj08290 *)sys)->f4 = ((struct Obj08290 *)sys)->fC;
}
