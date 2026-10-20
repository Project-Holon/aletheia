#ifndef GAME_OV016_GRAPHICS_H
#define GAME_OV016_GRAPHICS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of graphics.c, prototypes copied from their definitions. */

struct tagRect;

void DWCi_GXlVisible(int lcd, int plane);
void DWCi_GXlInvisible(int lcd, int plane);
void DWCi_GXlSetWndPosition(int lcd, int wnd, struct tagRect *r);
void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, int effect);
/* END mkheaders: generated region */

#endif
