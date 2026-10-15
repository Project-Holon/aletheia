/*
 * function: MB_COMM_SYS_MainWireless
 * address: 0x021EF79C
 * packet: pkt_ov107_021EF79C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_StartMeasureChannel 0x02178E84 thumb ov014
 *   WIH_Finalize 0x02179498 thumb ov014
 *   MB_PARENT_SYS_FreeBuffers 0x021F0DB4 thumb ov107
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   WIH_Initialize 0x021790E4 thumb ov014
 *   GFL_NET_WM_ICON_EasyStart 0x02037010 arm
 *   GFL_NET_WM_ICON_EasySetScreen 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MB_COMM_SYS_StartParent 0x021EF96C thumb ov107
 *   MB_UTIL_MSG_ClearWindow 0x021F1898 thumb ov107
 *   MB_UTIL_MSG_SetWindowLayout 0x021F1628 thumb ov107
 *   MB_UTIL_MSG_CreateWordSet 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   MB_UTIL_MSG_SetNumberZeroPad 0x021F1918 thumb ov107
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   MB_UTIL_MSG_PrintStream 0x021F1704 thumb ov107
 *   MB_UTIL_MSG_DeleteWordSet 0x021F18EC thumb ov107
 *   MB_COMM_SYS_MainRecruit 0x021EFA14 thumb ov107
 *   MB_UTIL_MSG_PrintQueued 0x021F17E0 thumb ov107
 *   MB_UTIL_MSG_SetTimeIconPending 0x021F1B38 thumb ov107
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WIH_End 0x02179570 thumb ov014
 *   MB_COMM_SYS_WmEndCallback 0x021EFC10 thumb ov107
 *   MB_COMM_SYS_ResetHook 0x021EFCA8 thumb ov107
 *   WM_GetLinkLevel 0x0208EE9C arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   GFL_NET_WM_ICON_EasyMain 0x02037154 arm
 *   gMbParentUi 0x021F6EA0 data a4
 */
#include "../include/Obj00072.h"
#include "../include/Obj22277.h"
#include "../include/G_Counter.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIH_GetSysState(void),WIH_StartMeasureChannel(void),WIH_Finalize(void);
extern void MB_PARENT_SYS_FreeBuffers(void),WIH_FreeWork(void);
extern int WIH_Initialize(u32,int,int);
extern void GFL_NET_WM_ICON_EasyStart(u32,u32,u32,u32),GFL_NET_WM_ICON_EasySetScreen(u32,u32);
extern void func_020351F8(u32 a, u32 b);
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MB_COMM_SYS_StartParent(u8 *),MB_UTIL_MSG_ClearWindow(void *),MB_UTIL_MSG_SetWindowLayout(void *,int),MB_UTIL_MSG_CreateWordSet(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void MB_UTIL_MSG_SetNumberZeroPad(unsigned char *a, int b, int c, int d);
extern signed char MSG_SPEED_GetWait(void);
struct Obj;
extern void MB_UTIL_MSG_PrintStream(void *,int,int);
extern void MB_UTIL_MSG_DeleteWordSet(void *);
extern void MB_COMM_SYS_MainRecruit(u8 *);
extern void MB_UTIL_MSG_PrintQueued(void *,int);
extern void MB_UTIL_MSG_SetTimeIconPending(u8 *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WIH_End(void (*cb)(int));
extern int MB_COMM_SYS_WmEndCallback(void);
extern int WM_GetLinkLevel(void);
extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);
extern void GFL_NET_WM_ICON_EasyMain(void);
extern struct Counter gMbParentUi;
extern void MB_COMM_SYS_ResetHook(u8 *p);
int MB_COMM_SYS_MainWireless(u8 *p)
{
 void *q;
 if(WIH_GetSysState()==9 || WIH_GetSysState()==10){
  ((struct Obj00072 *)p)->f30=0;((struct Obj00072 *)p)->f14=1;
  if(WIH_Finalize()==1){MB_PARENT_SYS_FreeBuffers();WIH_FreeWork();return 1;}return 0;
 }
 switch(p[0x24]){
 case 0:
  *(int *)(((u8 *)&gMbParentUi)+8)=0;((struct Obj00072 *)p)->f1C=1;
  WIH_Initialize(((struct Obj00072 *)p)->f0,(int)MB_COMM_SYS_WmEndCallback,0);
  GFL_NET_WM_ICON_EasyStart(240,0,0,((struct Obj00072 *)p)->f0);
  if(p[0x28]==0)GFL_NET_WM_ICON_EasySetScreen(0,((struct Obj00072 *)p)->f0);
  else GFL_NET_WM_ICON_EasySetScreen(1,((struct Obj00072 *)p)->f0);
  p[0x24]=1;func_020351F8((u32)MB_COMM_SYS_ResetHook,(u32)p);break;
 case 1:
  if(WIH_GetSysState()==1 && WIH_StartMeasureChannel()==1)p[0x24]=2;break;
 default:break;
 case 2:
  if(WIH_GetSysState()==7){
   q=GAME_DATA_GetMyStatus(((struct Obj22277 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);MB_COMM_SYS_StartParent(p);
   MB_UTIL_MSG_ClearWindow(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,2);
   else MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,3);
   MB_UTIL_MSG_CreateWordSet(((struct Obj00072 *)p)->f68);MB_UTIL_MSG_SetNumberZeroPad(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   if(p[0x28]==0)MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,0,MSG_SPEED_GetWait());
   else MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,20,MSG_SPEED_GetWait());
   MB_UTIL_MSG_DeleteWordSet(((struct Obj00072 *)p)->f68);p[0x24]=3;
  }break;
 case 3:MB_COMM_SYS_MainRecruit(p);break;
 case 4:
  MB_UTIL_MSG_ClearWindow(((struct Obj00072 *)p)->f68);MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,1);
  if(p[0x28]==0)MB_UTIL_MSG_PrintQueued(((struct Obj00072 *)p)->f68,1);
  else MB_UTIL_MSG_PrintQueued(((struct Obj00072 *)p)->f68,21);
  MB_UTIL_MSG_SetTimeIconPending(((struct Obj00072 *)p)->f68,1);CLACT_SetActorAnimSeq(((struct Obj00072 *)p)->f7C,15);p[0x24]=5;break;
 case 5:((struct Obj00072 *)p)->f30=1;p[0x24]=6;break;
 case 8:p[0x24]=6;break;
 case 6:*(int *)(((u8 *)&gMbParentUi)+8)=0;WIH_End((void (*)(int))((int (*)(int))MB_COMM_SYS_WmEndCallback));((struct Obj00072 *)p)->f1C=0;p[0x24]=7;break;
 case 7:if(*(int *)(((u8 *)&gMbParentUi)+8)==1){func_020351F8(0,0);WIH_FreeWork();return 1;}break;
 }
 GFL_NET_WM_ICON_EasySetLevel(3-WM_GetLinkLevel());GFL_NET_WM_ICON_EasyMain();return 0;
}
