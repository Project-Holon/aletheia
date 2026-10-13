/*
 * function: FLDMMDL_RAIL_MOVE_AcJumpL16F0
 * address:  0x0219E27C
 * packet:   pkt_ov021_0219E27C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_AcJumpSet  0x0219E084  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FLDMMDL_RAIL_MOVE_AcJumpSet(u32, u32, u32, u32, u16, s16, u16);

int FLDMMDL_RAIL_MOVE_AcJumpL16F0(u32 a)
{
    FLDMMDL_RAIL_MOVE_AcJumpSet(a, 2, 0x2000, 16, 3, 0, 0x100);
    return 1;
}
