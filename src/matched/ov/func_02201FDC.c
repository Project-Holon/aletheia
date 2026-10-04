/*
 * function: func_02201FDC
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
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *
 * Every concrete byte is reproduced (36 bytes, the last two of them the
 * listing's alignment padding).  The single wildcard is the BLX at +0004 to
 * func_021C866C, which has no independent witness outside 02201FDC..02201FFE;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Guessing one of those eight
 * regions would be a false witness, so the site stays parked until the region
 * that owns 0x021C866C is named.
 *
 * The shape itself is settled: the callee's result selects state 0x30 or 0x2e,
 * then the 0/0x15 pair is published and 2 is returned.
 
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
*/
#include "../include/Obj12244.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021C866C(u8 *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_02201FDC(u8 *p)
{
    if (func_021C866C(p) != 0) {
        ((struct Obj12244 *)p)->f28 = 0x30;
    } else {
        ((struct Obj12244 *)p)->f28 = 0x2e;
    }
    func_021F4EC0(p, 0, 0x15);
    return 2;
}
