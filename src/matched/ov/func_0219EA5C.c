/*
 * function: FLDMMDL_RAIL_InitRailWork
 * address:  0x0219EA5C
 * packet:   pkt_0219EA5C
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
 *   FIELD_NOGRID_MAPPER_CreateRailWork  0x021BB394  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12077.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetNogridMapper(u32);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FIELD_NOGRID_MAPPER_CreateRailWork(u32);

int FLDMMDL_RAIL_InitRailWork(void *a, u32 b)
{
((struct Obj12077 *)((u8 *)(a)))->f0 = FIELD_NOGRID_MAPPER_CreateRailWork(FLDMMDL_SysGetNogridMapper((u32)FLDMMDL_GetMmdlSys((void *)b)));
((struct Obj12077 *)((u8 *)(a)))->f6 = 2;
return 2;
}

