/*
 * function: WF2DMAP_OBJDRAW_AllocActor
 * address: 0x021C58C8
 * packet: pkt_ov127_021C58C8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJDRAW_IsActorFree 0x021C58B8 thumb ov127
 */
#include "../include/Obj10478.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJDRAW_IsActorFree(char *);
char *WF2DMAP_OBJDRAW_AllocActor(u8 *p) { int i,offset; for(i=0;i<((struct Obj10478 *)p)->f8;i++) { offset=i*20; if(WF2DMAP_OBJDRAW_IsActorFree(*(char * *)&((struct Obj10478 *)p)->f4+offset)==1) return *(char * *)&((struct Obj10478 *)p)->f4+offset; } return 0; }
