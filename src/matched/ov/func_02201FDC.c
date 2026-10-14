/*
 * function: WORLDTRADE_SERVER_StateCheckAsyncEnd
 * address:  0x02201FDC
 * packet:   pkt_02201FDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm  ov114
 *
 * Every concrete byte is reproduced (36 bytes, the last two of them the
 * listing's alignment padding).  The single wildcard is the BLX at +0004 to
 * DPW_TR_IsAsyncEnd, which has no independent witness outside 02201FDC..02201FFE;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Guessing one of those eight
 * regions would be a false witness, so the site stays parked until the region
 * that owns 0x021C866C is named.
 *
 * The shape itself is settled: the callee's result selects state 0x30 or 0x2e,
 * then the 0/0x15 pair is published and 2 is returned.
 
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
*/
#include "../include/Obj12244.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_SERVER_StateCheckAsyncEnd(u8 *p)
{
    if (DPW_TR_IsAsyncEnd(p) != 0) {
        ((struct Obj12244 *)p)->f28 = 0x30;
    } else {
        ((struct Obj12244 *)p)->f28 = 0x2e;
    }
    WORLDTRADE_SetStateAndReturn(p, 0, 0x15);
    return 2;
}
