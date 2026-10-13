/*
 * function: FLDMMDL_RAIL_GetDrawOffset
 * address:  0x0219E764
 * packet:   pkt_0219E764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern u32 FLDMMDL_RAIL_GetDrawOffsetByDir(u32, u32, u32);

int FLDMMDL_RAIL_GetDrawOffset(u32 a, u32 b)
{
FLDMMDL_RAIL_GetRailWork((void *)a);
return FLDMMDL_RAIL_GetDrawOffsetByDir(a, (((u32)FLDMMDL_GetDirDisp((void *)a) << 16) >> 16), b);
}

