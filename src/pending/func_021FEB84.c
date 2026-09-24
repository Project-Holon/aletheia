/*
 * function: func_021FEB84
 * address:  0x021FEB84
 * packet:   pkt_021FEB84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *

 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x021FEB84..0x021FEBB6; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

int func_021FEB84(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    *(u32 *)(p + 0x28) = 0;
    return 3;
}
