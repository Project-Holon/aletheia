/*
 * function: func_021B7264
 * address: 0x021B7264
 * packet: pkt_ov101_021B7264
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 * APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
#include "../include/Obj10232.h"
typedef unsigned int   u32;
struct Obj;
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
void func_021B7264(int p) {
 APP_TASKMENU_WIN_ResetDecide((struct Obj *)(((struct Obj10232 *)p)->f0));
 APP_TASKMENU_WIN_SetActive((struct Obj *)(((struct Obj10232 *)p)->f0),0);
 ((struct Obj10232 *)p)->f50=0;
}
