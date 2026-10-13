/*
 * function: PMS_INPUT_SetHandler
 * address: 0x021BD7A0
 * packet: pkt_ov110_021BD7A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   PMS_INPUT_UiSwitchMenu 0x021BD8A8 thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 *   PMS_INPUT_UiSwitchBrowse 0x021BD8B8 thumb ov110
 *   PMS_INPUT_HandleWordList 0x021BEDEC thumb ov110
 *   PMS_INPUT_UiSwitchWordList 0x021BD8C8 thumb ov110
 *   PMS_INPUT_VIEW_UpdateEditFocus 0x021BAE24 thumb ov110
 *   PMS_INPUT_VIEW_UpdateCategoryFocus 0x021BAE94 thumb ov110
 *   PMS_INPUT_VIEW_UpdateWordwinFocus 0x021BAED0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
extern int PMS_INPUT_HandleBrowse(u8 *,void *);
extern int PMS_INPUT_HandleWordList(u8 *,void *);
extern int PMS_INPUT_UiSwitchMenu(u8 *p);
extern int PMS_INPUT_UiSwitchBrowse(u8 *p);
extern int PMS_INPUT_UiSwitchWordList(u8 *p);
extern void PMS_INPUT_VIEW_UpdateEditFocus(u8 *p, u8 *a1, void *a2);
extern void PMS_INPUT_VIEW_UpdateCategoryFocus(u8 *p, u8 *q, void *a2);
extern void PMS_INPUT_VIEW_UpdateWordwinFocus(u8 *p, u8 *a1, void *a2);
void PMS_INPUT_SetHandler(u8 *p,Handler fn) {
 *(Handler *)&((struct Obj00012 *)p)->f24=fn; ((struct Obj00012 *)p)->f20=0;
 if(fn==PMS_INPUT_HandleMenu) { PMS_INPUT_VIEW_UpdateEditFocus(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)PMS_INPUT_UiSwitchMenu; }
 else if(fn==PMS_INPUT_HandleBrowse) { PMS_INPUT_VIEW_UpdateCategoryFocus(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)PMS_INPUT_UiSwitchBrowse; }
 else if(fn==PMS_INPUT_HandleWordList) { PMS_INPUT_VIEW_UpdateWordwinFocus(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)PMS_INPUT_UiSwitchWordList; }
 else *(Handler *)&((struct Obj00012 *)p)->f74=0;
}
