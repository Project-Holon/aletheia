/*
 * function: func_021BADB0
 * address: 0x021BADB0
 * packet: pkt_ov100_021BADB0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_IRC_WIRELESS_Step 0x0203D158 arm
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAD78 0x021BAD78 thumb ov100
 *   func_021BB058 0x021BB058 thumb ov100
 */
#include "../include/Obj07964.h"
typedef unsigned char u8;
extern int GFL_NET_IRC_WIRELESS_Step(void);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BAD78(unsigned a);
extern void func_021BB058(int a);
void func_021BADB0(int a) {
 if(GFL_NET_IRC_WIRELESS_Step()!=0) { func_021B95B8((u8 *)a,(u32)func_021BAD78); return; }
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj07964 *)a)->fCC0))!=0) {
  APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj07964 *)a)->fCC0);
  APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj07964 *)a)->fCC0));
  *(int *)&((struct Obj07964 *)a)->fCC0=0;
  func_02041B6C(6);
  func_021B95B8((u8 *)a,(u32)func_021BB058);
 }
}
