/*
 * function: func_021D5E5C
 * address:  0x021D5E5C
 * packet:   pkt_ov016_021D5E5C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlDrawRect (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   NNSi_G2dTextCanvasDrawTextRect   0x02069818  arm
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
    u8 font[0x10];
    Canvas canvas[32];
    Canvas bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont;

extern MemFont *g_021DE680;
typedef struct {
    signed char a;
    signed char b;
} Pair;

extern void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *tc, int x, int y, int w, int h, int color, u32 flag, u16 *txt, Pair p);

void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt)
{
    Canvas *cnv = canvas;
    Pair p = {0, 0};
    switch (cnv->text.pFont->res->glyph->type) {
    case 0:
    case 7:
        p.a = 1;
        break;
    case 1:
    case 2:
        p.b = 1;
        break;
    case 3:
    case 4:
        p.a = -1;
        break;
    case 5:
    case 6:
        p.b = -1;
        break;
    }
    NNSi_G2dTextCanvasDrawTextRect(&cnv->text, x, y, w, h, color, flag, txt, p);
}
