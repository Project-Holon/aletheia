/*
 * function: FLDMMDL_RAIL_GetNowLocation
 * address:  0x0219E334
 * packet:   pkt_0219E334
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
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17973.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u32 FIELD_RAIL_WORK_GetLocation(u32, u32);

int FLDMMDL_RAIL_GetNowLocation(u32 a, u32 b)
{
return FIELD_RAIL_WORK_GetLocation(((struct Obj17973 *)((u8 *)(FLDMMDL_GetMoveProcWork((void *)a))))->f0, b);
}

