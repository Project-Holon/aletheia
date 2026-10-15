/*
 * function: WF2DMAP_OBJDRAW_RestoreFrame
 * address: 0x021C57F4
 * packet: pkt_ov127_021C57F4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_OBJDRAW_GetFrameValue 0x021C58F8 thumb ov127
 *   WF2DMAP_OBJDRAW_SetFrame 0x021C5944 thumb ov127
 *   WF2DMAP_OBJDRAW_UpdateActor 0x021C574C thumb ov127
 */
#include "../include/Obj00328.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJDRAW_GetFrameValue(char *,int);
extern void WF2DMAP_OBJDRAW_SetFrame(u8 *,int,int);
extern void WF2DMAP_OBJDRAW_UpdateActor(u8 *);
void WF2DMAP_OBJDRAW_RestoreFrame(u8 *p) { WF2DMAP_OBJDRAW_SetFrame(p,WF2DMAP_OBJDRAW_GetFrameValue(*(char * *)&((struct Obj00328 *)p)->f4,((struct Obj00328 *)p)->f8),((struct Obj00328 *)p)->fA); WF2DMAP_OBJDRAW_UpdateActor(p); }
