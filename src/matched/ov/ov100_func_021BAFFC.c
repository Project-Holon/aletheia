/*
 * function: func_021BAFFC
 * address: 0x021BAFFC
 * packet: pkt_ov100_021BAFFC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B967C 0x021B967C thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 *   func_021BAFCC 0x021BAFCC thumb ov100
 */
#include "../include/Obj07966.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void func_021BA5F4(unsigned a);
extern int func_021B95C0(u8 *p);
extern void func_021B967C(int,int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B96B8(u8 *a);
extern void func_021BAFCC(int p);
void func_021BAFFC(int a) {
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0))!=0) {
  int v=APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj07966 *)a)->fCC0);
  APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0));
  *(int *)&((struct Obj07966 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a); func_021B95C0((u8 *)a); func_021B95B8((u8 *)a,(u32)func_021B96B8);
  } else func_021B95B8((u8 *)a,(u32)func_021BAFCC);
  func_021B967C(a,0);
 }
}
