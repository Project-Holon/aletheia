#ifndef GAME_ARM9_BMP_CURSOR_H
#define GAME_ARM9_BMP_CURSOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_cursor.c, prototypes copied from their definitions. */

struct MenuCursor;
struct MenuTarget;
struct PrintQueue;
struct GfFont;

#include "../types.h"

struct MenuCursor *BMP_CURSOR_Create(u32 heap);
void BMP_CURSOR_Delete(struct MenuCursor *cursor);
void BMP_CURSOR_Draw(struct MenuCursor *cursor, u32 x, u32 y, struct MenuTarget *target, struct PrintQueue *printer, struct GfFont *font);
void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap);
/* END mkheaders: generated region */

#endif
