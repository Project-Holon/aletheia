/*
 * function: POKETRADE_SAVE_StepSaveCancelNotice
 * address: 0x021E0B34
 * packet: pkt_ov119_021E0B34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_SAVE_SetWaitCounter 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   FADE_Start 0x0204E720 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepBeginSyncRange24 0x021E0BA4 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern void POKETRADE_SAVE_CreateMessageResources(char *p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
typedef unsigned char  u8;
extern void POKETRADE_SAVE_SetWaitCounter(u8 *p, u32 v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_SAVE_StepBeginSyncRange24(void *);
void POKETRADE_SAVE_StepSaveCancelNotice(char *p) {POKETRADE_SAVE_CreateMessageResources(p);MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),50,(void *)(*(int *)&((struct Obj00001 *)p)->f738));*(int *)&((struct Obj00001 *)p)->f644=(int)BMP_MENUWORK_LoadFrameGfx((void *)6,15,0,((struct Obj00001 *)p)->f5F4);POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_SAVE_SetWaitCounter((u8 *)p,0);func_02040588(6,1);GFL_NET_RefreshWmIconAtTopRight(1,((struct Obj00001 *)p)->f5F4);FADE_Start(3,16,0,2);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginSyncRange24);}
