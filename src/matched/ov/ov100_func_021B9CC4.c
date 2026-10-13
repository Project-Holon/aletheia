/*
 * function: IRCBATTLEMATCH_StepSendTrainerInfo
 * address: 0x021B9CC4
 * packet: pkt_ov100_021B9CC4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009CA8 0x02009CA8 thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepSendMacAddress 0x021B9C50 thumb ov100
 */
#include "../include/Obj03738.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned int   u32;
struct BigObj;
struct TaskMenu;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern void func_02009CA8(void *account, void *out);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepSendMacAddress(int a);
void IRCBATTLEMATCH_StepSendTrainerInfo(int a)
{
 u8 x[12];
 int k=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7b,k)!=0) {
  if(((struct Obj03738 *)a)->f24C==7) {
   func_02009CA8((void *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj03738 *)a)->f244)),x);
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,k,(u32)x)!=0) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,k);
    IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepSendMacAddress);
    if(((struct Obj03738 *)a)->fCC0!=0) {
     APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
     ((struct Obj03738 *)a)->fCC0=0;
    }
   }
  } else {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,k);
   if(((struct Obj03738 *)a)->fCC0!=0) {
    APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
    ((struct Obj03738 *)a)->fCC0=0;
   }
   IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepSendMacAddress);
  }
 }
}
