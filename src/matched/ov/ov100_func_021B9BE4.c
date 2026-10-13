/*
 * function: IRCBATTLEMATCH_StepSendPlayerSlots
 * address: 0x021B9BE4
 * packet: pkt_ov100_021B9BE4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepSendRegulation 0x021B9B7C thumb ov100
 */
#include "../include/Obj22076.h"
typedef unsigned short u16;

typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,u32,u32);
extern unsigned GFL_NET_IsParentAid(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, u32, u32);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepSendRegulation(int a);
void IRCBATTLEMATCH_StepSendPlayerSlots(int a)
{
 int k=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7d,k)!=0) {
  if(GFL_NET_IsParentAid()!=0) {
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc05,4,((struct Obj22076 *)a)->f244+0x18)!=0) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,k);
    IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepSendRegulation);
   }
  } else {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,k);
   IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepSendRegulation);
  }
 }
}
