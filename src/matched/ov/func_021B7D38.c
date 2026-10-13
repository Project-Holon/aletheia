/*
 * function: FIELD_RAIL_GetLocationPos
 * address:  0x021B7D38
 * packet:   pkt_021B7D38
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
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07526.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_RAIL_WORK_SetLocation(u32, u32, u32, u32);
extern u32 FIELD_RAIL_WORK_GetPos(u32, u32);

int FIELD_RAIL_GetLocationPos(u32 a, u32 b, u32 c, u32 d)
{
FIELD_RAIL_WORK_SetLocation(((struct Obj07526 *)((u8 *)(a)))->f1C, b, c, d);
return FIELD_RAIL_WORK_GetPos(((struct Obj07526 *)((u8 *)(a)))->f1C, c);
}

