/*
 * function: PMS_INPUT_VIEW_UpdateCategoryFocus
 * address: 0x021BAE94
 * packet: pkt_ov110_021BAE94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 */
#include "../include/Obj06387.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void PMSIV_CATEGORY_SetCursorVisible(u8 *,int);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *,int,int);
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_MoveCursor(u8 *,unsigned);
void PMS_INPUT_VIEW_UpdateCategoryFocus(u8 *p, u8 *q, void *a2) { PMSIV_CATEGORY_SetCursorVisible(*(u8 * *)&((struct Obj06387 *)p)->f58,1); if(**(int * *)&((struct Obj06387 *)p)->f78==1) { if(PMS_INPUT_GetBrowseMode(q)==1) PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj06387 *)p)->f64,0,0); } else PMSIV_CATEGORY_MoveCursor(*(u8 * *)&((struct Obj06387 *)p)->f58,PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj06387 *)p)->f18)); }
