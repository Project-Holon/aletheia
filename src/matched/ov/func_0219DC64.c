/*
 * function: FLDMMDL_RAIL_MOVE_AcDirD0
 * address:  0x0219DC64
 * packet:   pkt_0219DC64
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_RAIL_MOVE_AcDirSet(its own argument 1, 0x1) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_AcDirSet  0x0219DC34  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern int FLDMMDL_RAIL_MOVE_AcDirSet(u32 a, u32 b);

u32 FLDMMDL_RAIL_MOVE_AcDirD0(u32 a1)
{
    FLDMMDL_RAIL_MOVE_AcDirSet(a1, 0x1);

    return 0x1;
}

