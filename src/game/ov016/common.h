#ifndef GAME_OV016_COMMON_H
#define GAME_OV016_COMMON_H

#include "../types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of common.c, prototypes copied from their definitions. */

#include "../types.h"

unsigned char *DWCi_Char(unsigned char *name);
void DWCi_CMNlLoadResource(char *file, void (*func)(const void *, u32, u32));
void DWCi_CMNlStep(int step);
void DWCi_CMNlButton(int kind);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId);
int DWCi_CMNlFontFlag(void);
/* END mkheaders: generated region */

#endif
