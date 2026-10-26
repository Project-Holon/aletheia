#ifndef GAME_OV016_FONT_H
#define GAME_OV016_FONT_H

typedef int bool_0;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of font.c, prototypes copied from their definitions. */

struct Canvas;
typedef struct Canvas Canvas;

#include "../types.h"

void DWCi_FNTlInit(void);
void DWCi_FNTlEnd(void);
void *DWCi_FNTlFormEx(int lcd, int width, int height, bool_0 head, int *obj, int font);
void DWCi_FNTlDelete(Canvas *a);
void *DWCi_FNTlFormBgEx(int lcd, int font);
void DWCi_FNTlDeleteBg(void *canvas);
void DWCi_FNTlDeleteBgLcd(int a);
void DWCi_FNTlDraw(void *canvas, int x, int y, int color, u32 flag, u16 *txt);
int DWCi_FNTlDrawCharEx(void *canvas, int x, int y, int color, unsigned short chr, int font);
void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, u16 *txt, int font);
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
void DWCi_FNTlClear(Canvas *cnv, int color);
void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
void DWCi_FNTlRenewBg(Canvas *x);
/* END mkheaders: generated region */

#endif
