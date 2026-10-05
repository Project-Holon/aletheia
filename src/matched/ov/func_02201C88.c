/*
 * function: func_02201C88
 * address:  0x02201C88
 * packet:   pkt_02201C88
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x02201C88..0x02201CBA; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_02201C88(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj00018 *)p)->f28 = 0;
    return 3;
}
