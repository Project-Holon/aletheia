/*
 * function: WF2DMAP_TOUCH_SelectMenu
 * address: 0x021C93C0
 * packet: pkt_ov128_021C93C0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_PlayActorAnimA 0x021CA3A0 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimB 0x021CA3C4 thumb ov128
 *   WF2DMAP_TOUCH_FindNextEntry 0x021C9D88 thumb ov128
 *   func_021C6E18 0x021C6E18 thumb ov128
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj08131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WF2DMAP_TOUCH_PlayActorAnimA(char *p);
extern void WF2DMAP_TOUCH_PlayActorAnimB(char *p);
extern int WF2DMAP_TOUCH_FindNextEntry(u8 *p, int direction);
extern void func_021C6E18(u8 *p, int i, u16 a);
int WF2DMAP_TOUCH_SelectMenu(char *p,void *q,void *r,int n) {
 switch(n) {
 case 0:GFL_USE_PlaySeDefaultVolume(0x551);WF2DMAP_TOUCH_PlayActorAnimA(r);return 7;
 case 1:GFL_USE_PlaySeDefaultVolume(0x556);WF2DMAP_TOUCH_PlayActorAnimB(r);return 8;
 case 2:if(WF2DMAP_TOUCH_FindNextEntry(q,0)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=0;func_021C6E18(r,1,11);return 6;}break;
 case 3:if(WF2DMAP_TOUCH_FindNextEntry(q,1)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=1;func_021C6E18(r,0,10);return 6;}break;
 }
 return 2;
}
