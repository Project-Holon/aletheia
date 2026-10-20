#ifndef GAME_ARM9_TEXTPRINT_H
#define GAME_ARM9_TEXTPRINT_H

#include "../types.h"

struct Bmp;

/* The debug console: the bitmap the text goes to, the cursor and the colors.
 * The flags byte at 0xB is set by GF_PANIC_Init and not read by TEXTPRINT. */
typedef struct TextParam {
    struct Bmp *charBitmap; /* 0x0 */
    u16 cursorX;            /* 0x4 */
    u16 cursorY;            /* 0x6 */
    u8  advanceX;           /* 0x8 */
    u8  advanceY;           /* 0x9 */
    u8  fgColor : 4;        /* 0xA */
    u8  bgColor : 4;
    u8  flags;              /* 0xB */
} TextParam;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of textprint.c, prototypes copied from their definitions. */

#include "../types.h"

void TEXTPRINT_Init(u32 fontId);
void TEXTPRINT_PrintCodes(const u16 *codes, TextParam *console);
void TEXTPRINT_PrintText(const char *text, TextParam *console);
void TEXTPRINT_SjisToGlyphCodes(const char *text, u16 *out, int maxCodes);
u16 TEXTPRINT_AsciiToGlyphCode(u8 asciiChar);
u16 TEXTPRINT_SjisToGlyphCode(u16 sjisChar);
/* END mkheaders: generated region */

#endif
