#ifndef GAME_OV194_NSBTX_TO_CLWK_H
#define GAME_OV194_NSBTX_TO_CLWK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nsbtx_to_clwk.c, prototypes copied from their definitions. */

#include "../types.h"

void NAMEIN_GRAPHIC_BlitTexture(const char *src, int width, int x, int y, int w, int h, char *dst);
void NAMEIN_GRAPHIC_CopyRows(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step);
void NAMEIN_GRAPHIC_LoadIconMember(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap);
/* END mkheaders: generated region */

#endif
