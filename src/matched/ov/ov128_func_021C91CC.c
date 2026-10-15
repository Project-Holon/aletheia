/*
 * function: WF2DMAP_TOUCH_ClearScreens
 * address: 0x021C91CC
 * packet: pkt_ov128_021C91CC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_ClearWindow 0x021C6B38 thumb ov128
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 */
#include "../include/Obj10490.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern void Wf2dmapFriend_ClearWindow(u8 *p);
extern void BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
void WF2DMAP_TOUCH_ClearScreens(char *p,void *q) {
 void *v;
 Wf2dmapFriend_ClearWindow(q);
 BG_SYS_SetTileEntry(2,0,0,0,32,24,0);func_02041B6C(2);
 v=((struct Obj10490 *)p)->f0;BMP_WIN_ClearScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
 v=((struct Obj10490 *)p)->f8;BMP_WIN_ClearScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
 BG_SYS_SetTileEntry(3,0,0,0,32,24,0);func_02041B6C(3);
}
