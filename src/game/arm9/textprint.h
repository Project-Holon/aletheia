#ifndef GAME_ARM9_TEXTPRINT_H
#define GAME_ARM9_TEXTPRINT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of textprint.c, prototypes copied from their definitions. */

#include "../types.h"

void TEXTPRINT_Init(u32 fontId);
void TEXTPRINT_SjisToGlyphCodes(char *text, u16 *out, int maxCodes);
u16 TEXTPRINT_AsciiToGlyphCode(u8 asciiChar);
u16 TEXTPRINT_SjisToGlyphCode(u16 sjisChar);
/* END mkheaders: generated region */

#endif
