/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2
 * address:  0x0219DB48
 * packet:   pkt_0219DB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_GetFldEffCtrl  0x0219DC08  thumb  ov021
 *   FLDEFF_KEMURI_StartFacing  0x021AC578  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a);
extern u32 FLDEFF_KEMURI_StartFacing(u32, u32);

int FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2(u32 a, u32 b, u32 c, u32 d)
{
return FLDEFF_KEMURI_StartFacing(a, FLDMMDL_RAIL_MOVE_GetFldEffCtrl(a));
}

