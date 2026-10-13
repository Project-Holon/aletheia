/*
 * function: CLACT_GetCharacterProxy
 * address:  0x0204AB84
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *
 * Copy the 36-byte header of a 64-byte-stride record out of the actor
 * table hung off the manager's pointer member at +0x10c into the caller's
 * buffer.  The whole copy is one aggregate assignment: two ldm/stm pairs
 * of four registers and a trailing word.
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

struct Rec {
    u32 w[9];
};

void CLACT_GetCharacterProxy(u32 idx, struct Rec *dst)
{
    struct Rec *src = (struct Rec *)(((u8 *)g_ClactSystem->owner_slots) + idx * 64);

    *dst = *src;
}
