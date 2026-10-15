/*
 * function: Wf2dmapFriend_ResetListWindow
 * address: 0x021C7694
 * packet: pkt_ov128_021C7694
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_TOUCH_SetBgOffset 0x021CA3E8 thumb ov128
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14037.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_SetBgOffset(int);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
void Wf2dmapFriend_ResetListWindow(u8 *p, void *ctx) {void *q;WF2DMAP_TOUCH_SetBgOffset(1);BMP_MENUWORK_DrawWindowBorder(((struct Obj14037 *)p)->f1C,0);q=((struct Obj14037 *)p)->f1C;BMP_WIN_ClearScreen(q);func_02041B6C(BMP_WIN_GetBgLayer(q));}
