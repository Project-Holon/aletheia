/*
 * function: FLDMMDL_RAIL_GetHitBitsDirNoAttr
 * address:  0x0219E418
 * packet:   pkt_0219E418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the third argument to 0.
 *
 * symbols:
 *   FLDMMDL_RAIL_GetHitBitsDir  0x0219E424  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_RAIL_GetHitBitsDir(u32 o, u32 k, u32 x);

int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32 a, u32 b)
{
    return FLDMMDL_RAIL_GetHitBitsDir(a, b, 0);
}
