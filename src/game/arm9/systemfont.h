#ifndef GAME_ARM9_SYSTEMFONT_H
#define GAME_ARM9_SYSTEMFONT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of systemfont.c, prototypes copied from their definitions. */

#include "../types.h"

void SYSTEMFONT_Load(const char *fontFile);
void SYSTEMFONT_GetGlyph(int idx, u8 *out);
u32 SYSTEMFONT_ExpandRowBits(u32 rowBits);
int SYSTEMFONT_GetGlyphHeight(void);
int SYSTEMFONT_GetGlyphWidth(void);
void SYSTEMFONT_SetColors(u32 fg, u32 bg);
/* END mkheaders: generated region */

#endif
