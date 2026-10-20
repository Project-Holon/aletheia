#ifndef GAME_ARM9_BMP_MENU_H
#define GAME_ARM9_BMP_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_menu.c, prototypes copied from their definitions. */

#include "../arm9/bmp_menu_types.h"
#include "../arm9/bmp_menu_types.h"
#include "../types.h"

BmpMenu *BMP_MENU_Create(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);
BmpMenu *BMP_MENU_Add(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);
void BMP_MENU_Delete(BmpMenu *menu, u8 *outSelected);
u32 BMP_MENU_ProcessInput(BmpMenu *menu);
int BMP_MENU_MoveCursor(BmpMenu *menu, u32 dir, u32 sfxId);
int BMP_MENU_StepSelection(BmpMenu *menu, u32 dir);
u32 BMP_MENU_GetMaxItemWidth(BmpMenu *menu);
void BMP_MENU_DrawItems(BmpMenu *menu);
void BMP_MENU_DrawCursor(BmpMenu *menu);
void BMP_MENU_GetItemPixelPos(BmpMenu *menu, u8 *outX, u8 *outY, u8 itemPos);
BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winData, u16 tileBase, u8 palette, u8 startPos, u16 heapId);
u32 BMP_MENU_ProcessYesNo(BmpMenu *menu);
void BMP_MENU_DeleteYesNo(BmpMenu *menu);
/* END mkheaders: generated region */

#endif
