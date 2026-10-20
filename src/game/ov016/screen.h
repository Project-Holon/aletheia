#ifndef GAME_OV016_SCREEN_H
#define GAME_OV016_SCREEN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of screen.c, prototypes copied from their definitions. */

void DWCi_SCREENlInit(void *scr);
void DWCi_SCREENlEnd(void);
void DWCi_SCREENlRenew(void);
void DWCi_SCREENlCopy(void *src, int pos, int w, int h);
void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
void DWCi_SCREENlSetPalette(unsigned int v);
/* END mkheaders: generated region */

#endif
