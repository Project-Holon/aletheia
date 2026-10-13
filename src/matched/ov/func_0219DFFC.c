/*
 * function: FLDMMDL_RAIL_MOVE_AcStayWalkR4F0
 * address:  0x0219DFFC
 * packet:   pkt_0219DFFC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_RAIL_MOVE_AcStayWalkSet(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_AcStayWalkSet  0x0219DE64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_RAIL_MOVE_AcStayWalkSet(u32 a, u32 b, u16 c, u16 d);

u32 FLDMMDL_RAIL_MOVE_AcStayWalkR4F0(u32 a1)
{
    FLDMMDL_RAIL_MOVE_AcStayWalkSet(a1, 0x3, 0x4, 0x4);

    return 0x1;
}

