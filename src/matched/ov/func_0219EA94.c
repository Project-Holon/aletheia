/*
 * function: FLDMMDL_RAIL_ReleaseRailWork
 * address:  0x0219EA94
 * packet:   pkt_0219EA94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
 *   FIELD_NOGRID_MAPPER_DeleteRailWork  0x021BB3A0  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17976.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetNogridMapper(u32);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void FIELD_NOGRID_MAPPER_DeleteRailWork(u8 *p, u32 a1);

u32 FLDMMDL_RAIL_ReleaseRailWork(u32 a, u32 *b)
{
FIELD_NOGRID_MAPPER_DeleteRailWork((u8 *)FLDMMDL_SysGetNogridMapper((u32)FLDMMDL_GetMmdlSys((void *)b)), ((struct Obj17976 *)((u8 *)(a)))->f0);
return (u32)FLDMMDL_ClearStatusBit(b, (2 << 12));
}

