/*
 * function: FLDMMDL_RAIL_MOVE_AcJumpSet
 * address:  0x0219E084
 * packet:   pkt_ov021_0219E084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_AcJumpSetSe  0x0219E00C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FLDMMDL_RAIL_MOVE_AcJumpSetSe(u32, u32, u32, u32, u16, s16, u16, u32);

void FLDMMDL_RAIL_MOVE_AcJumpSet(u32 a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g)
{
    FLDMMDL_RAIL_MOVE_AcJumpSetSe(a, b, c, d, e, f, g, 0x55E);
}
