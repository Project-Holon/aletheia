/*
 * function: WF2DMAP_MAP_GetCell
 * address: 0x021C4818
 * packet: pkt_ov127_021C4818
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sWf2dmapEmptyCell 0x021C600C data a4
 */
#include "../include/Obj08123.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;
extern Cell sWf2dmapEmptyCell;
Cell WF2DMAP_MAP_GetCell(u8 *p, u32 x, u32 y)
{
 Cell r = sWf2dmapEmptyCell;
 if (((struct Obj08123 *)p)->f0 > x && ((struct Obj08123 *)p)->f2 > y) r=*(Cell *)(((struct Obj08123 *)p)->f4 + (x + ((struct Obj08123 *)p)->f0*y)*4);
 return r;
}
