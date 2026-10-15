/*
 * function: WIFICLUBACTOR_AttachSprite
 * address: 0x021BA190
 * packet: pkt_ov099_021BA190
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_OBJDRAW_AddActor 0x021C5680 thumb ov127
 *   WF2DMAP_OBJDRAW_SetActive 0x021C57D8 thumb ov127
 *   WF2DMAP_OBJDRAW_SetFrameDefault 0x021C57DC thumb ov127
 *   WF2DMAP_OBJDRAW_SetActorValue 0x021C5840 thumb ov127
 */
#include "../include/Obj02660.h"
#include "../include/Obj06347.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *WF2DMAP_OBJDRAW_AddActor(u8 *,void *,int,u32); extern void WF2DMAP_OBJDRAW_SetActive(void *,int); extern void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *); extern void WF2DMAP_OBJDRAW_SetActorValue(char *,int);
void WIFICLUBACTOR_AttachSprite(u8 *p,u8 *s,int n) { *(u8 * *)&((struct Obj02660 *)s)->f4=WF2DMAP_OBJDRAW_AddActor(*(u8 * *)&((struct Obj06347 *)p)->f590,((struct Obj02660 *)s)->f0,n,((struct Obj06347 *)p)->f4); if (n==0) { WF2DMAP_OBJDRAW_SetActive(((struct Obj02660 *)s)->f4,0); WF2DMAP_OBJDRAW_SetFrameDefault(*(u8 * *)&((struct Obj02660 *)s)->f4); WF2DMAP_OBJDRAW_SetActorValue(*(char * *)&((struct Obj02660 *)s)->f4,0); } }
