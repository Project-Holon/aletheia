/*
 * function: WF2DMAP_TOUCH_GetMenuInput
 * address: 0x021C9544
 * packet: pkt_ov128_021C9544
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_GetMenuTouchInput 0x021C94DC thumb ov128
 *   WF2DMAP_TOUCH_GetMenuKeyInput 0x021C9450 thumb ov128
 *   UI_SetInputMode 0x020355D8 arm
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb  arm9
 */
#include "../include/Obj23105.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int WF2DMAP_TOUCH_GetMenuTouchInput(void *p, void *q, void *r, int *flag);
extern int WF2DMAP_TOUCH_GetMenuKeyInput(void *, int *, void *);
extern void UI_SetInputMode(u8 v);
int WF2DMAP_TOUCH_GetMenuInput(void *p,int *q,char *r) {
 int flag=0; int ret;
 if(!PRINTSYS_QUE_IsFinished(((struct Obj23105 *)r)->f34)) return 2;
 ret=WF2DMAP_TOUCH_GetMenuTouchInput(p,q,r,&flag);
 if(flag) {UI_SetInputMode(1); *q=1; return ret;}
 return WF2DMAP_TOUCH_GetMenuKeyInput(p,q,r);
}
