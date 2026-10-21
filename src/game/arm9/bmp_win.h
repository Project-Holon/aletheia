#ifndef GAME_ARM9_BMP_WIN_H
#define GAME_ARM9_BMP_WIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_win.c, prototypes copied from their definitions. */

struct BmpWin;
struct Bmp;

#include "../types.h"

void BMP_WIN_Init(u32 heapId);
void BMP_WIN_Exit(void);
struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
struct BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset);
struct BmpWin *BMP_WIN_Alloc(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset, u8 is8bpp);
u32 BMP_WIN_Delete(struct BmpWin *win);
void BMP_WIN_TransferChars(struct BmpWin *win);
void BMP_WIN_MakeScreen(struct BmpWin *win);
void BMP_WIN_DrawFrame(struct BmpWin *win, u16 baseTile, u32 palette);
void BMP_WIN_ClearScreen(struct BmpWin *win);
u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
u8 BMP_WIN_GetWidth(struct BmpWin *win);
u8 BMP_WIN_GetHeight(struct BmpWin *win);
u8 BMP_WIN_GetDispWidth(struct BmpWin *win);
u8 BMP_WIN_GetDispHeight(struct BmpWin *win);
u8 BMP_WIN_GetPosX(struct BmpWin *win);
u8 BMP_WIN_GetPosY(struct BmpWin *win);
u16 BMP_WIN_GetCharOffset(struct BmpWin *win);
struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
u8 BMP_WIN_GetPalette(struct BmpWin *win);
void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX);
void BMP_WIN_SetPosY(struct BmpWin *win, u8 posY);
void BMP_WIN_SetDispHeight(struct BmpWin *win, u8 dispHeight);
void BMP_WIN_SetPalette(struct BmpWin *win, u8 palette);
/* END mkheaders: generated region */

#endif
