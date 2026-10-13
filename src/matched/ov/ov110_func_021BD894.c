/*
 * unit: yes
 * function: PMS_INPUT_HandleMenu, PMS_INPUT_UiSwitchMenu, PMS_INPUT_UiSwitchBrowse, PMS_INPUT_UiSwitchWordList
 * address: 0x021BD894
 * packet: pkt_ov110_021BD894
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsInputMenuHandlers 0x021C3920 data a4
 *   PMS_INPUT_VIEW_UpdateEditFocus 0x021BAE24 thumb ov110
 *   PMS_INPUT_VIEW_UpdateCategoryFocus 0x021BAE94 thumb ov110
 *   PMS_INPUT_VIEW_UpdateWordwinFocus 0x021BAED0 thumb ov110
 */
#include "../include/Obj13789.h"
#include "../include/Obj13790.h"
#include "../include/Obj13791.h"
typedef unsigned char u8;
extern int (*const gPmsInputMenuHandlers[])(u8 *,void *);
extern int PMS_INPUT_VIEW_UpdateEditFocus(void *,u8 *,void *);
extern int PMS_INPUT_VIEW_UpdateCategoryFocus(void *,u8 *,void *);
extern int PMS_INPUT_VIEW_UpdateWordwinFocus(void *,u8 *,void *);
int PMS_INPUT_HandleMenu(u8 *p,void *q) { return gPmsInputMenuHandlers[*(unsigned *)(p+4)](p,q); }
int PMS_INPUT_UiSwitchMenu(u8 *p) { return PMS_INPUT_VIEW_UpdateEditFocus(((struct Obj13789 *)p)->f14,p,((struct Obj13789 *)p)->f18); }
int PMS_INPUT_UiSwitchBrowse(u8 *p) { return PMS_INPUT_VIEW_UpdateCategoryFocus(((struct Obj13790 *)p)->f14,p,((struct Obj13790 *)p)->f18); }
int PMS_INPUT_UiSwitchWordList(u8 *p) { return PMS_INPUT_VIEW_UpdateWordwinFocus(((struct Obj13791 *)p)->f14,p,((struct Obj13791 *)p)->f18); }
