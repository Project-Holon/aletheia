/*
 * function: FLDMMDL_RAIL_AcquireRailWork
 * address:  0x0219EAB8
 * packet:   pkt_0219EAB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_SysGetNogridMapper (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb
 *   FIELD_NOGRID_MAPPER_CreateRailWork  0x021BB394  thumb  ov021
 *   FLDMMDL_RAIL_ApplyStoredLocation  0x0219EAEC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07482.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetNogridMapper(u32);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_RAIL_ApplyStoredLocation(u32, u32);
extern u32 FIELD_NOGRID_MAPPER_CreateRailWork(u32);

int FLDMMDL_RAIL_AcquireRailWork(u32 a, u32 b)
{
*(u32 *)&((struct Obj07482 *)((u8 *)(a)))->f0 = FIELD_NOGRID_MAPPER_CreateRailWork(FLDMMDL_SysGetNogridMapper((u32)FLDMMDL_GetMmdlSys((void *)b)));
return FLDMMDL_RAIL_ApplyStoredLocation(a, b);
}

