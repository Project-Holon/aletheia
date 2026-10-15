/*
 * function: MB_COMM_SYS_Exit
 * address: 0x021EE824
 * packet: pkt_ov107_021EE824
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UI_ClearKeepAwakeFlagsGlobal 0x02034FB8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0200566C 0x0200566C thumb
 *   GFL_NET_WM_ICON_EasyEnd 0x020370C8 arm
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_GetEventWorkAddress 0x020143CC thumb
 *   func_020307B0 0x020307B0 arm
 *   MB_COMM_SYS_DeleteNetState 0x021F0E40 thumb ov107
 *   MB_UTIL_MSG_Delete 0x021F1520 thumb ov107
 *   MB_COMM_SYS_ExitDisplay 0x021EF080 thumb ov107
 */
#include "../include/Obj00979.h"
#include "../include/Obj22274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Node;
extern void UI_ClearKeepAwakeFlagsGlobal(u32 v);
extern void func_02030EAC(struct Node *n);
extern void func_0200566C(void);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void MB_COMM_SYS_DeleteNetState(void *);
extern void MB_UTIL_MSG_Delete(char *p);
extern void MB_COMM_SYS_ExitDisplay(char *p);
void MB_COMM_SYS_Exit(u8 *p) {
 void *q; u16 *a,*b;
 UI_ClearKeepAwakeFlagsGlobal(16); func_02030EAC(((struct Obj00979 *)p)->f4);func_0200566C();GFL_NET_WM_ICON_EasyEnd();
 if(p[40]==1) GFL_USE_CancelChangeAndStopBgm();
 else { q=(void *)GAME_DATA_GetEventWork(((struct Obj22274 *)(*(u8 * *)&((struct Obj00979 *)p)->f8))->f4); a=(u16 *)ZONEDATA_GetEventWorkAddress((u32)q,16384);b=(u16 *)ZONEDATA_GetEventWorkAddress((u32)q,16385);*a=((struct Obj00979 *)p)->f38;*b=((struct Obj00979 *)p)->f3A; }
 if(((struct Obj00979 *)p)->f60) func_020307B0(((struct Obj00979 *)p)->f60);
 MB_COMM_SYS_DeleteNetState(((struct Obj00979 *)p)->fC);MB_UTIL_MSG_Delete(((struct Obj00979 *)p)->f68);MB_COMM_SYS_ExitDisplay((char *)p);
}
