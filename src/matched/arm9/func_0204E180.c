/*
 * function: TEXTPRINT_PrintCodes
 * address:  0x0204E180
 * packet:   pkt_0204E180
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_TextPrintWork     0x02146A78  data
 *   SYSTEMFONT_GetGlyphHeight  0x020463C0  arm
 *   SYSTEMFONT_GetGlyphWidth  0x020463D8  arm
 *   SYSTEMFONT_SetColors  0x020463E0  arm
 *   func_020436FC  0x020436FC  arm
 *   func_02045A98  0x02045A98  arm
 *   SYSTEMFONT_GetGlyph  0x02046300  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *
 * textprint.c: draw a u16 string with the fixed 8x8 debug font into
 * pp->bmp at pp->x/pp->y.  Control codes: 1 newline (x back to pp->x, y
 * down by font height + line space), 2 a full-width space (7), 3 a half
 * space; every other code c renders glyph c - 4 into the 0x26-byte context
 * at g_TextPrintWork and blits it.  The cursor is written back to pp at the end.
 *
 * Shape facts: case 2 is `x = x + width` (the compound form truncates
 * width to u16 first); the loop test is `eom != *str` (cmp operand order);
 * locals declared eom, glyph, width, height so the callee-saved registers
 * land as in the image.
 */

#include "../include/G_TextCtx.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pixels[0x20];
    u8  width;
    u8  pad21;
    u16 x;
    u16 y;
} TextCtx;

typedef struct {
    void *bmp;
    u16 x;
    u16 y;
    u8  letterSpace;
    u8  lineSpace;
    u8  fg : 4;
    u8  bg : 4;
} TextParam;

extern struct TextCtx *g_TextPrintWork;

extern int SYSTEMFONT_GetGlyphHeight(void);
struct Bmp;
struct Obj020437AC;
extern int SYSTEMFONT_GetGlyphWidth(void);
extern void  SYSTEMFONT_SetColors(u32 fg, u32 bg);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern u16   func_02045A98(void);
extern void SYSTEMFONT_GetGlyph(int idx, u8 *out);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);

void TEXTPRINT_PrintCodes(const u16 *str, TextParam *pp)
{
    u16 eom;
    void *glyph;
    u32 width;
    u32 height;
    u16 c;

    height = SYSTEMFONT_GetGlyphHeight();
    width = SYSTEMFONT_GetGlyphWidth();
    g_TextPrintWork->x = pp->x;
    g_TextPrintWork->y = pp->y;
    SYSTEMFONT_SetColors(pp->fg, pp->bg);
    glyph = func_020436FC(g_TextPrintWork, 1, 1, 0x20, 0);
    eom = func_02045A98();
    while (eom != *str) {
        c = *str;
        str++;
        switch (c) {
        case 1:
            g_TextPrintWork->x = pp->x;
            g_TextPrintWork->y += (u16)(height + pp->lineSpace);
            break;
        case 2:
            g_TextPrintWork->x = g_TextPrintWork->x + width;
            break;
        case 3:
            g_TextPrintWork->x += (u16)(width / 2);
            break;
        default:
            SYSTEMFONT_GetGlyph((u16)(c - 4), (u8 *)g_TextPrintWork);
            func_020439A0(glyph, pp->bmp, 0, 0, g_TextPrintWork->x, g_TextPrintWork->y,
                          g_TextPrintWork->width, height, 0);
            g_TextPrintWork->x += (u16)(g_TextPrintWork->width + pp->letterSpace);
            break;
        }
    }
    pp->x = g_TextPrintWork->x;
    pp->y = g_TextPrintWork->y;
    func_020437AC(glyph);
}
