/*
 * function: FLDMMDL_RAIL_MOVE_AcWalkL8F0
 * address:  0x0219DD84
 * packet:   pkt_0219DD84
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_RAIL_MOVE_AcWalkSet(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_AcWalkSet  0x0219DC88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_RAIL_MOVE_AcWalkSet(u32 a1, u32 a2, u32 a3, u32 a4);

u32 FLDMMDL_RAIL_MOVE_AcWalkL8F0(u32 a1)
{
    FLDMMDL_RAIL_MOVE_AcWalkSet(a1, 0x2, 0x8, 0x3);

    return 0x1;
}

