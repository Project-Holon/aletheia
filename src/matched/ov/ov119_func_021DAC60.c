/*
 * function: POKETRADE_PROC_StepRestartNetSession
 * address: 0x021DAC60
 * packet: pkt_ov119_021DAC60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepAfterWipeLoadBox 0x021DAC20 thumb ov119
 */
#include "../include/Obj06423.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *,int,int);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void WIPE_ResetBrightness(u32 which);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int),POKETRADE_PROC_StepAfterWipeLoadBox(void *);
void POKETRADE_PROC_StepRestartNetSession(char *p) {
 GFL_NET_RefreshWmIconAtTopRight(1,((struct Obj06423 *)p)->f5F4);if(((struct Obj06423 *)p)->f118C==2)DWC_RAP_SetVchatTalkLock(1);
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj06423 *)p)->f720),6,(void *)(((struct Obj06423 *)p)->f738));POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_SAVE_ShowTimeIcon(p);
 BG_SYS_SetMainVisiblePlanes(16);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(0);
 WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj06423 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAfterWipeLoadBox);
}
