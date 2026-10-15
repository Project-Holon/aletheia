/*
 * function: POKETRADE_PROC_StepRestoreBrowseScene
 * address: 0x021DA8F8
 * packet: pkt_ov119_021DA8F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_ClearOfferSlots 0x021DD1B8 thumb ov119
 *   POKETRADE_NEGO_ExitMarkers 0x021DF904 thumb ov119
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_02045CAC 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_NEGO_RegisterIconResources 0x021DD528 thumb ov119
 *   POKETRADE_NEGO_DrawPlayerNames 0x021DD68C thumb ov119
 *   POKETRADE_NEGO_InitOfferMarkers 0x021DF78C thumb ov119
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   MI_CpuFill8 0x02082BCC arm
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_PROC_UpdateTouchbarButtons 0x021DBB6C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepRebuildTradeScene 0x021DA898 thumb ov119
 *   POKETRADE_PROC_RedrawAndSyncGrid 0x021DB7AC thumb ov119
 */
#include "../include/Obj03773.h"
typedef unsigned char u8;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern int POKETRADE_PROC_IsNetSession(void *),POKETRADE_PROC_IsHostSide(void *);
typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *);
extern void POKETRADE_NEGO_ClearOfferSlots(char *);
extern void POKETRADE_NEGO_ExitMarkers(void *);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_NEGO_RegisterIconResources(char *,int);
extern void POKETRADE_NEGO_DrawPlayerNames(char *p);
extern void POKETRADE_NEGO_InitOfferMarkers(void *);
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
extern void MI_CpuFill8(void *,int,int);
extern void POKETRADE_PROC_ShowDragIcon(void *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void POKETRADE_2D_CreateBoxWindows(char *p);
extern void POKETRADE_2D_SetupSubBlend(void *);
extern void POKETRADE_PROC_UpdateTouchbarButtons(char *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepRebuildTradeScene(char *);
extern void POKETRADE_PROC_RedrawAndSyncGrid(char *,int,int);
void POKETRADE_PROC_StepRestoreBrowseScene(char *p)
{
 if(POKETRADE_PROC_IsNetSession(p) && !GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)) return;
 POKETRADE_SAVE_CloseMessageWindowClear(p);
 if(POKETRADE_PROC_IsHostSide(p)) {
  POKETRADE_NEGO_ClearOfferSlots(p);POKETRADE_NEGO_ExitMarkers(p);
  if(((struct Obj03773 *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  func_02045CAC((struct MsgBank *)(((struct Obj03773 *)p)->f720),134,(void *)(((struct Obj03773 *)p)->f738));POKETRADE_SAVE_OpenMessageWindowTop(p);
  POKETRADE_NEGO_RegisterIconResources(p,0);POKETRADE_NEGO_DrawPlayerNames(p);
  ((struct Obj03773 *)p)->f11E8=0;((struct Obj03773 *)p)->f11E9=0;
  POKETRADE_NEGO_InitOfferMarkers(p);POKETRADE_NEGO_SetOfferMarkersState(p,1);
  MI_CpuFill8(p+0xca0,0,0x78);MI_CpuFill8(p+0xd18,0,0x3c);MI_CpuFill8(p+0xd54,0,0x3c);
  POKETRADE_PROC_ShowDragIcon(p);
  if(((struct Obj03773 *)p)->f64C) {APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj03773 *)p)->f64C));((struct Obj03773 *)p)->f64C=0;}
  POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);
 }
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRebuildTradeScene);POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
}
