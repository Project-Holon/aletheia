/*
 * function: WF2DMAP_TOUCH_StartEditAnim
 * address: 0x021C958C
 * packet: pkt_ov128_021C958C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_SetActorAutoAnim 0x021C6DF8 thumb ov128
 *   WF2DMAP_TOUCH_SetValue 0x021C9BEC thumb ov128
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj10493.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void Wf2dmapFriend_SetActorAutoAnim(u8 *p, u32 a);
extern void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int a5);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WF2DMAP_TOUCH_StartEditAnim(char *p, void *q, void *r, int s) {
 int mode;
 ((struct Obj10493 *)p)->f4=0;
 Wf2dmapFriend_SetActorAutoAnim(r,0);
 mode=(((struct Obj10493 *)p)->f8==2)?2:1;
 WF2DMAP_TOUCH_SetValue((u16 *)p,q,r,mode,((struct Obj10493 *)p)->f0,s);
 GFL_USE_PlaySeDefaultVolume(0x548);
}
