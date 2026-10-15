/*
 * function: WF2DMAP_OBJDRAW_UpdateAllActors
 * address: 0x021C571C
 * packet: pkt_ov127_021C571C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJDRAW_IsActorFree 0x021C58B8 thumb ov127
 *   WF2DMAP_OBJDRAW_UpdateActor 0x021C574C thumb ov127
 */
#include "../include/Obj10477.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJDRAW_IsActorFree(char *);
extern void WF2DMAP_OBJDRAW_UpdateActor(u8 *);
void WF2DMAP_OBJDRAW_UpdateAllActors(u8 *p) { int i,offset; for(i=0;i<((struct Obj10477 *)p)->f8;i++) { offset=i*20; if(WF2DMAP_OBJDRAW_IsActorFree(*(char * *)&((struct Obj10477 *)p)->f4+offset)==0) WF2DMAP_OBJDRAW_UpdateActor(*(u8 * *)&((struct Obj10477 *)p)->f4+offset); } }
