#ifndef GAME_ARM9_WM_ICON_H
#define GAME_ARM9_WM_ICON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_icon.c, prototypes copied from their definitions. */

#include "../types.h"

u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 charNo);
int GFL_NET_WM_ICON_GetCharOffset(int engine);
void GFL_NET_WM_ICON_LoadGraphics(int engine, int iconVariant, int heapId);
void GFL_NET_WM_ICON_ClearOam(void);
void GFL_NET_WM_ICON_EasyStart(u32 x, u32 y, u32 iconVariant, u32 heapId);
void GFL_NET_WM_ICON_EasyEnd(void);
u32 GFL_NET_WM_ICON_EasySetLevel(u32 level);
void GFL_NET_WM_ICON_EasySetScreen(u32 isTop, u32 heapId);
void GFL_NET_WM_ICON_EasyMain(void);
void GFL_NET_WM_ICON_EasyObjWindowOn(void);
void GFL_NET_WM_ICON_EasyObjWindowOff(void);
void GFL_NET_WM_ICON_SetDefaultPos(u16 x, u16 y);
void GFL_NET_WM_ICON_SetDefaultScreen(u32 screen);
u32 GFL_NET_WM_ICON_EasyGetEngine(void);
/* END mkheaders: generated region */

#endif
