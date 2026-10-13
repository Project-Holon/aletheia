/*
 * function: FIELD_RAIL_WORK_GetEndPoint
 * address:  0x021B834C
 * packet:   pkt_021B834C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with two object fields.
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00454.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);

u8 *FIELD_RAIL_WORK_GetEndPoint(u8 *p)
{
    return FIELD_RAIL_SETTING_GetPoint((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 4));
}
