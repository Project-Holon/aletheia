/*
 * file:     unit_021D5824_p03.c
 * unit:     yes
 * function: func_021D5CA8, func_021D5CCC
 * address:  0x021D5CA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NNSi_G2dTextCanvasDrawText       0x020696F4  arm
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

typedef struct {
    signed char a;
    signed char b;
} Pair;

extern void func_021D5C48(void *);
extern void NNSi_G2dTextCanvasDrawText(TextCanvas *tc, int x, int y, int color, u32 flag, u16 *txt, Pair p);
void func_021D5CA8(int a);
void func_021D5CCC(void *canvas, int x, int y, int color, u32 flag, u16 *txt);
extern MemFont *g_021DE680;


/*
 * Tail-call func_021D5C48 with the argument scaled by 0x30 into the table at 0x021DE680 + 0x610.
 * Addresses are Black-image addresses.
 */
void func_021D5CA8(int a)
{
    func_021D5C48((void *)(*(int *)0x021DE680 + 0x610 + a * 0x30));
}


void func_021D5CCC(void *canvas, int x, int y, int color, u32 flag, u16 *txt)
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
    NNSi_G2dTextCanvasDrawText(&cnv->text, x, y, color, flag, txt, p);
}
