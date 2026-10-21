#ifndef GAME_ARM9_BMP_MENULIST_H
#define GAME_ARM9_BMP_MENULIST_H

#include "../arm9/bmp_menulist_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_menulist.c, prototypes copied from their definitions. */

struct BmpMenuList;
struct BmpMenuListTemplate;
struct Strbuf;
struct Bmp;
struct BmpWin;

#include "../types.h"

struct BmpMenuList *BMP_MENULIST_Create(struct BmpMenuListTemplate *menuTemplate, u16 scroll, u16 row, u32 heap);
s32 BMP_MENULIST_Main(struct BmpMenuList *menu);
void BMP_MENULIST_Delete(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow);
void BMP_MENULIST_Redraw(struct BmpMenuList *menu);
void BMP_MENULIST_SetColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow);
void BMP_MENULIST_SetOverrideColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow);
void BMP_MENULIST_GetListIndex(struct BmpMenuList *menu, u16 *outIndex);
void BMP_MENULIST_GetPos(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow);
u16 BMP_MENULIST_GetCursorY(struct BmpMenuList *menu);
u16 BMP_MENULIST_GetRowY(struct BmpMenuList *menu, u32 row);
u32 BMP_MENULIST_GetItemValue(struct BmpMenuList *menu, u32 index);
u32 BMP_MENULIST_GetAttr(struct BmpMenuList *menu, u32 attr);
void BMP_MENULIST_PrintItem(struct BmpMenuList *menu, struct Strbuf *text, u32 x, u32 y, u32 queued);
void BMP_MENULIST_DrawItems(struct BmpMenuList *menu, u16 item, u16 winRow, u16 numRows, u32 scrollFirst);
void BMP_MENULIST_DrawCursor(struct BmpMenuList *menu);
void BMP_MENULIST_EraseCursor(struct BmpMenuList *menu, u32 row);
u8 BMP_MENULIST_StepCursor(struct BmpMenuList *menu, u8 dir);
void BMP_MENULIST_ScrollRows(struct BmpMenuList *menu, u16 numRows, u32 fromBottom);
u32 BMP_MENULIST_MoveCursor(struct BmpMenuList *menu, u8 redraw, u8 steps, u8 dir);
void BMP_MENULIST_NotifyCursor(struct BmpMenuList *menu, void *arg);
void BMP_MENULIST_ShiftChars4bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes);
void BMP_MENULIST_ShiftChars8bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes);
void BMP_MENULIST_ShiftWindow(struct BmpWin *win, u32 dir, u32 start, u32 fillColor, u16 tiles);
void BMP_MENULIST_ResetCursorTile(struct BmpMenuList *menu, int heap);
u32 BMP_MENULIST_GetUserData(struct BmpMenuList *menu);
void BMP_MENULIST_SetCancelDisabled(struct BmpMenuList *menu, u32 disabled);
/* END mkheaders: generated region */

#endif
