/*
 * function: DWCi_FNTlFormEx
 * address:  0x021D5950
 * packet:   pkt_ov016_021D5950
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlFormEx (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   DWCi_QUElPopBack                 0x021D54C4  arm  ov016
 *   DWCi_OVRlAlloc                   0x021D705C  arm  ov016
 *   NNSi_G2dCalcRequiredOBJ          0x02069184  arm
 *   NNS_G2dCharCanvasInitForOBJ1D    0x02068FF0  arm
 *   gFontWork                       0x021DE680  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef int bool;

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
    void *pad;
    void (*pfnClear)(void *cnv, int color);
} CharFmt;

typedef struct {
    u8 chr0[0x14];
    CharFmt *pFmt;
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

extern MemFont *gFontWork;

extern void *DWCi_QUElPopBack(void *queue);
extern void *DWCi_OVRlAlloc(int lcd, int num, int head, int *name);
extern u32 NNSi_G2dCalcRequiredOBJ(int w, int h);
extern void NNS_G2dCharCanvasInitForOBJ1D(Canvas *cnv, void *base, int w, int h, int fmt);

void *DWCi_FNTlFormEx(int lcd, int width, int height, bool head, int *obj, int font)
{
    Canvas *cnv;
    u8 *base;
    int name;
    Font *fp;

    cnv = DWCi_QUElPopBack(gFontWork->unused);
    cnv->width = width;
    cnv->height = height;
    cnv->buf = DWCi_OVRlAlloc(lcd, width * height, head, &name);
    cnv->name = name;
    *obj = NNSi_G2dCalcRequiredOBJ(width, height);
    base = (u8 *)(lcd == 1 ? 0x6600000 : 0x6400000);
    base += name * 128;
    NNS_G2dCharCanvasInitForOBJ1D(cnv, base, width, height, 4);
    cnv->pFmt->pfnClear(cnv, 0);
    fp = &gFontWork->font[font];
    cnv->text.pCanvas = cnv;
    cnv->text.pFont = fp;
    cnv->text.hSpace = 1;
    cnv->text.vSpace = 1;
    return cnv;
}
