/*
 * function: FIELD_RAIL_WORK_Reset
 * address:  0x021B919C
 * packet:   pkt_021B919C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object, a pass-through argument and the word at +0x78.
 *
 * symbols:
 *   FIELD_RAIL_WORK_Init  0x021B9164  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01358.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_WORK_Init(u8 *p, u32 a, u32 v);

void FIELD_RAIL_WORK_Reset(u8 *p, u32 a)
{
    FIELD_RAIL_WORK_Init(p, a, *(u32 *)&((struct Obj01358 *)p)->f78);
}
