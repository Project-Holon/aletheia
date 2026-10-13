/*
 * function: FIELD_RAIL_WORK_GetPointCamera
 * address:  0x021B836C
 * packet:   pkt_021B836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a field of each argument.
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetCamera  0x021B8820  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18118.h"
#include "../include/Obj18119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_SETTING_GetCamera(u32 a, u32 b);

void FIELD_RAIL_WORK_GetPointCamera(u8 *p, u8 *q)
{
    FIELD_RAIL_SETTING_GetCamera(((struct Obj18118 *)p)->f24, ((struct Obj18119 *)q)->f3C);
}
