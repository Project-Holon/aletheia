/*
 * function: FLDMMDL_RAIL_GetFrontLocation
 * address:  0x0219E634
 * packet:   pkt_0219E634
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
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17975.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 ZONEDATA_DirToRailKey(int i);
extern u32 FLDMMDL_SysGetNogridMapper(u32);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u32 FIELD_RAIL_WORK_QueryStep(u32, u32, u32, u32);

int FLDMMDL_RAIL_GetFrontLocation(void *a, u32 b)
{
FLDMMDL_SysGetNogridMapper((u32)FLDMMDL_GetMmdlSys((void *)a));
return FIELD_RAIL_WORK_QueryStep(((struct Obj17975 *)((u8 *)(FLDMMDL_GetMoveProcWork((void *)a))))->f0, ZONEDATA_DirToRailKey(FLDMMDL_GetDirDisp((void *)a)), b, 0);
}

