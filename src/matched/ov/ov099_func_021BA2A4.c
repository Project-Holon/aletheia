/*
 * function: WIFICLUBACTOR_SetBounceState
 * address: 0x021BA2A4
 * packet: pkt_ov099_021BA2A4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUBACTOR_UpdateBounce 0x021BA578 thumb ov099
 *   WIFICLUBACTOR_AnimateBounce 0x021BA36C thumb ov099
 *   WIFICLUBACTOR_QueueActorMove 0x021BA5B4 thumb ov099
 *   WF2DMAP_OBJDRAW_SetActive 0x021C57D8 thumb ov127
 */
#include "../include/Obj02448.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFICLUBACTOR_UpdateBounce(void *,void *); extern void WIFICLUBACTOR_AnimateBounce(void *,void *); extern void WIFICLUBACTOR_QueueActorMove(void *,int,void *); extern void WF2DMAP_OBJDRAW_SetActive(void *,int);
void WIFICLUBACTOR_SetBounceState(void *w,u8 *s) { ((struct Obj02448 *)s)->f10=(void *)WIFICLUBACTOR_UpdateBounce; ((struct Obj02448 *)s)->f18=(void *)WIFICLUBACTOR_AnimateBounce; ((struct Obj02448 *)s)->f8=28; ((struct Obj02448 *)s)->fC=4; WIFICLUBACTOR_QueueActorMove(w,4,s); WF2DMAP_OBJDRAW_SetActive(((struct Obj02448 *)s)->f4,0); }
