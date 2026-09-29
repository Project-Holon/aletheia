/*
 * function: func_021D5DB0
 * address:  0x021D5DB0
 * packet:   pkt_ov016_021D5DB0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlDrawStringEx (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   NNS_G2dFontFindGlyphIndex        0x02067F9C  arm
 *   NNS_G2dFontGetCharWidthsFromIndex 0x02067FE4  arm
 *   DWCi_FNTlDrawCharEx              0x021D5D74  arm  ov016
 *   g_021DE680                       0x021DE680  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 pad[7];
    u8 type;
} FGlyph;

typedef struct {
    u32 pad[2];
    FGlyph *glyph;
} FRes;

typedef struct {
    FRes *res;
    void *pad;
} Font;

typedef struct {
    void *pCanvas;
    Font *pFont;
    int hSpace;
    int vSpace;
} TextCanvas;

typedef struct {
    u8 chr[0x18];
    TextCanvas text;
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas;

typedef struct {
    Font font[2];
    Canvas canvas[32];
    Canvas bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont;

extern MemFont *g_021DE680;
typedef struct {
    signed char left;
    signed char glyphWidth;
    signed char charWidth;
} CharWidths;

extern int NNS_G2dFontFindGlyphIndex(void *font, u16 c);
extern CharWidths *NNS_G2dFontGetCharWidthsFromIndex(void *font, int idx);
extern void DWCi_FNTlDrawCharEx(void *canvas, int x, int y, int color, u16 chr, int font);

void func_021D5DB0(void *canvas, int x, int y, int color, int interval, u16 *txt, int font)
{
    Font *f;
    int idx;
    if (*txt == 0)
        return;
    do {
        f = &g_021DE680->font[font];
        idx = NNS_G2dFontFindGlyphIndex(f, *txt);
        if (idx == 0xffff)
            idx = ((u16 *)f->res)[1];
        DWCi_FNTlDrawCharEx(canvas, x + ((interval - NNS_G2dFontGetCharWidthsFromIndex(f, idx)->charWidth) >> 1), y, color, *txt, font);
        txt++;
        x += interval;
    } while (*txt != 0);
}
