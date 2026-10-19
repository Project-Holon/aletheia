/*
 * function: Wf2dmapFriend_ShowEntryDetail
 * address: 0x021C875C
 * packet: pkt_ov128_021C875C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WF2DMAP_TOUCH_MakeScreen 0x021CA42C thumb ov128
 *   WF2DMAP_TOUCH_UpdateItemBar 0x021CA2DC thumb ov128
 *   WF2DMAP_TOUCH_SetScreenBrightness 0x021CA3E8 thumb ov128
 */
#include "../include/Obj23088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void WF2DMAP_TOUCH_MakeScreen(char *);
extern void WF2DMAP_TOUCH_UpdateItemBar(char *);
extern void WF2DMAP_TOUCH_SetScreenBrightness(int);
void Wf2dmapFriend_ShowEntryDetail(char *p,char *q) {BMP_MENUWORK_DrawWindowBorder(((struct Obj23088 *)p)->f108,1);WF2DMAP_TOUCH_MakeScreen(q);WF2DMAP_TOUCH_UpdateItemBar(p);WF2DMAP_TOUCH_SetScreenBrightness(1);}
