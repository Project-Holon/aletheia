#ifndef GAME_OV016_SCROLLBAR_H
#define GAME_OV016_SCROLLBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrollbar.c, prototypes copied from their definitions. */

#include "../types.h"

void DWCi_SBlInit(int kind, int max, int x, int y, int pos);
void DWCi_SBlEnd(void);
u8 DWCi_SBlGet(void);
unsigned char DWCi_SBlGetState(void);
void DWCi_SBlDisp(int scrollPos);
void DWCi_SBlEnable(void);
void DWCi_SBlDisable(void);
/* END mkheaders: generated region */

#endif
