/*
 * function: FIELD_RAIL_WORK_GetLinePos
 * address:  0x021B835C
 * packet:   pkt_021B835C
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
 *   FIELD_RAIL_SETTING_GetLinePos  0x021B8848  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00454.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_SETTING_GetLinePos(u32 a, u32 b);

void FIELD_RAIL_WORK_GetLinePos(u8 *p)
{
    FIELD_RAIL_SETTING_GetLinePos(*(u32 *)&((struct Obj00454 *)p)->f24, *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 0xc));
}
