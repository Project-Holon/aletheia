/*
 * function: WF2DMAP_OBJDRAW_FillSpawnDesc
 * address: 0x021C5564
 * packet: pkt_ov127_021C5564
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 */
#include "../include/Obj10476.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y; } Pos;
extern Pos WF2DMAP_OBJ_GetPos(void *);
void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *out,void *p,int kind,int index,int value) { *(Pos *)out=WF2DMAP_OBJ_GetPos(p); ((struct Obj10476 *)out)->f4=kind; out[7]=index; out[6]=value; }
