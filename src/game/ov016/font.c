/*
 * file:     font.c
 * unit:     yes
 * function: DWCi_FNTlInit, DWCi_FNTlEnd, DWCi_FNTlFormEx, DWCi_FNTlDelete, DWCi_FNTlFormBgEx, taskLoad, DWCi_FNTlDeleteBg, DWCi_FNTlDeleteBgLcd, DWCi_FNTlDraw, DWCi_FNTlDrawCharEx, DWCi_FNTlDrawStringEx, DWCi_FNTlDrawRect, DWCi_FNTlClear, DWCi_FNTlDisp, DWCi_FNTlRenewBg
 * address:  0x021D5824
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
 *   DWCi_QUElPushBack              0x021D546C  arm  ov016
 *   DWCi_OVRlFree                  0x021D71C0  arm  ov016
 *   DWCi_HEAPlAllocEx                0x021D6414  arm  ov016
 *   DWCi_QUElFormEx                  0x021D5410  arm  ov016
 *   DWCi_Language                    0x021C0EC8  arm  ov016
 *   DWCi_ARClReadEx                  0x021D4B68  arm  ov016
 *   NNS_G2dFontInitUTF16             0x02067F78  arm
 *   gFontWork                       0x021DE680  data
 *   sFontTable4                       0x021DBFE4  data
 *   sFontTable5                       0x021DBFEC  data
 *   DWCi_ARClRelease                 0x021D4C68  arm  ov016
 *   DWCi_QUElDelete                  0x021D5450  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm  ov016
 *   gMemFont                  0x021DE680  data
 *   DWCi_QUElPopBack                 0x021D54C4  arm  ov016
 *   DWCi_OVRlAlloc                   0x021D705C  arm  ov016
 *   NNSi_G2dCalcRequiredOBJ          0x02069184  arm
 *   NNS_G2dCharCanvasInitForOBJ1D    0x02068FF0  arm
 *   NNSi_G2dInitPenSimple  0x02068FC4  arm
 *   G2S_GetBG0ScrPtr  0x0207DF94  arm
 *   G2_GetBG0ScrPtr  0x0207DF60  arm
 *   NNS_G2dMapScrToCharText  0x02069078  arm
 *   DWCi_FNTlClear  0x021D5F14  arm    ov016
 *   DWCi_TSKlForm  0x021D7680  arm    ov016
 *   sFontTable3     0x021DAA76  data
 *   sFontTable2     0x021DAA74  data
 *   sFontTable1     0x021DAA70  data
 *   DWCi_ScreenDC_FlushRange                  0x020862F0  arm
 *   GX_LoadBG0Char                  0x0207EE68  arm
 *   GXS_LoadBG0Char                  0x0207EEFC  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm  ov016
 *   G2_GetBG0CharPtr                 0x0207E1F8  arm
 *   MIi_CpuClear16                   0x02082A48  arm
 *   NNSi_G2dTextCanvasDrawText       0x020696F4  arm
 *   NNS_G2dFontFindGlyphIndex        0x02067F9C  arm
 *   NNS_G2dFontGetCharWidthsFromIndex 0x02067FE4  arm
 *   DWCi_FNTlDrawCharEx              0x021D5D74  arm  ov016
 *   NNSi_G2dTextCanvasDrawTextRect   0x02069818  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm  ov016
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm  ov016
 *   DWCi_CELLlSetPalette             0x021D5098  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   NNS_G2dArrangeOBJ1D              0x020691E0  arm
 *   NNSi_G2dCharCanvasDrawChar  0x02068EA0  arm  arm9
 */
struct Ctx;
struct Fnt2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    unsigned char pad[7];
    unsigned char type;
} FGlyph;

typedef struct {
    unsigned long pad[2];
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
    unsigned char chr0[0x14];
    CharFmt *pFmt;
    TextCanvas text;
    void *buf;
    union {
        void *task;
        struct {
            unsigned short name;
            unsigned char width;
            unsigned char height;
        } obj;
    } u;
} Canvas;

typedef struct {
    Font font[2];
    Canvas canvas[32];
    Canvas bg[2];
    void *unused;
    void *file[2];
    unsigned char renew[2];
} MemFont;

typedef int bool_0;

typedef unsigned char bool_021D5824;

typedef struct {
    signed char a;
    signed char b;
} Pair;

typedef signed char    s8;

typedef struct {
    signed char left;
    signed char glyphWidth;
    signed char charWidth;
} CharWidths;

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern int DWCi_Language(void);
extern void *DWCi_ARClReadEx(char *path, u32 *size, int alignment);
extern void NNS_G2dFontInitUTF16(void *font, void *res);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_QUElDelete(void *queue);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_QUElPopBack(void *queue);
extern void *DWCi_OVRlAlloc(int lcd, int num, int head, int *name);
extern u32 NNSi_G2dCalcRequiredOBJ(int w, int h);
extern void NNS_G2dCharCanvasInitForOBJ1D(Canvas *cnv, void *base, int w, int h, int fmt);
extern void DWCi_OVRlFree(void *ovram);
extern void DWCi_QUElPushBack(void *queue, void *data);
extern void NNSi_G2dInitPenSimple(int a, int b, int c, int d, int e);
extern void *G2S_GetBG0ScrPtr(void);
extern void *G2_GetBG0ScrPtr(void);
extern void NNS_G2dMapScrToCharText(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
extern void *DWCi_TSKlForm(int kind, void (*f)(void *), void *w, unsigned char prio);
extern void DWCi_ScreenDC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GX_LoadBG0Char(void *pSrc, unsigned long offset, unsigned long szByte);
extern void GXS_LoadBG0Char(void *pSrc, unsigned long offset, unsigned long szByte);
extern void DWCi_TSKlDeleteEx(int a, void *task);
extern void *G2_GetBG0CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void NNSi_G2dTextCanvasDrawText(TextCanvas *tc, int x, int y, int color, u32 flag, u16 *txt, Pair p);
extern s8 NNSi_G2dCharCanvasDrawChar(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code);
extern int NNS_G2dFontFindGlyphIndex(void *font, u16 c);
extern CharWidths *NNS_G2dFontGetCharWidthsFromIndex(void *font, int idx);
int DWCi_FNTlDrawCharEx(void *canvas, int x, int y, int color, unsigned short chr, int font);
extern void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *tc, int x, int y, int w, int h, int color, u32 flag, u16 *txt, Pair p);
extern void *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void NNS_G2dArrangeOBJ1D(void *oam, int w, int h, int x, int y, int a, int name, int b);
void DWCi_FNTlInit(void);
void DWCi_FNTlEnd(void);
void *DWCi_FNTlFormEx(int lcd, int width, int height, bool_0 head, int *obj, int font);
void DWCi_FNTlDelete(Canvas *a);
void *DWCi_FNTlFormBgEx(int lcd, int font);
void DWCi_FNTlDeleteBg(void *canvas);
void DWCi_FNTlDeleteBgLcd(int a);
void DWCi_FNTlDraw(void *canvas, int x, int y, int color, u32 flag, u16 *txt);
void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, u16 *txt, int font);
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
void DWCi_FNTlClear(Canvas *cnv, int color);
void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
void DWCi_FNTlRenewBg(int x);
extern MemFont *gFontWork;
extern char *sFontTable4[2];
extern char *sFontTable5[2];
extern MemFont *gMemFont;
extern const u16 sFontTable2[];
extern const u16 sFontTable3[];
extern const u16 sFontTable1[];


/*
 * sdk:      DWCi_FNTlInit (libdwcutil.TWL.HYB.a(font.o))
 */

static void taskLoad(void *task, void *work);
void DWCi_FNTlInit(void)
{
    int i;
    gFontWork = DWCi_HEAPlAllocEx(0x680, 4);
    gFontWork->unused = DWCi_QUElFormEx(32, gFontWork->canvas, 48);
    if (DWCi_Language() == 6) {
        for (i = 0; i < 2; i++) {
            gFontWork->file[i] = DWCi_ARClReadEx(sFontTable4[i], 0, 4);
            NNS_G2dFontInitUTF16(&gFontWork->font[i], gFontWork->file[i]);
        }
    } else {
        for (i = 0; i < 2; i++) {
            gFontWork->file[i] = DWCi_ARClReadEx(sFontTable5[i], 0, 4);
            NNS_G2dFontInitUTF16(&gFontWork->font[i], gFontWork->file[i]);
        }
    }
}


/*
 * sdk:      DWCi_FNTlEnd (libdwcutil.TWL.HYB.a(font.o))
 */
void DWCi_FNTlEnd(void)
{
    int i;
    for (i = 0; i < 2; i++)
        DWCi_ARClRelease(gFontWork->file[i]);
    DWCi_QUElDelete(gFontWork->unused);
    DWCi_HEAPlFree_((void **)&gMemFont);
}


void *DWCi_FNTlFormEx(int lcd, int width, int height, bool_0 head, int *obj, int font)
{
    Canvas *cnv;
    u8 *base;
    int name;
    Font *fp;

    cnv = DWCi_QUElPopBack(gFontWork->unused);
    cnv->u.obj.width = width;
    cnv->u.obj.height = height;
    cnv->buf = DWCi_OVRlAlloc(lcd, width * height, head, &name);
    cnv->u.obj.name = name;
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


/*
 * Release the word at +0x28 then hand the record to the queue at +0x670.
 * Addresses are Black-image addresses.
 */
void DWCi_FNTlDelete(Canvas *a)
{
    DWCi_OVRlFree(a->buf);
    DWCi_QUElPushBack(gFontWork->unused, a);
}


/*
 * notes: EXACT.  Two passes: const-qualifying the three read-only tables
 *        (`extern const u16 sFontTable2[]/sFontTable3[]/sFontTable1[]`) collapsed
 *        the +D0..+0104 argument-setup residue (33 differing bytes -> 10).
 *        The last residue was the +00AC..+00B4 field-run order: image stores
 *        `str r5,[r5,#0x18]` (cv->self) before `add r0,r0,r4,lsl #3` /
 *        `str r0,[r5,#0x1c]` (cv->font).  Writing the source self-first put
 *        cv->self in place but recoloured the block (g into r1, the constant
 *        1 into r0), 21 bytes.  Binding the loaded global pointer to a named
 *        local -- `MemFont *base = gFontWork;` before `cv->text.pCanvas = cv;`, then
 *        `cv->text.pFont = &base->font[font];` -- keeps the self store first and the
 *        add base in r0.  See
 *        docs/idioms/a-named-local-for-the-loaded-global-base-settles-a-field-store-run.md.
 *
 * sdk:      DWCi_FNTlFormBgEx (libdwcutil.TWL.HYB.a font.o)
 */
void *DWCi_FNTlFormBgEx(int lcd, int font)
{
    Canvas *cv;
    void *scr;
    u16 w, h, chr;

    h = sFontTable3[lcd * 2];
    w = sFontTable2[lcd * 2];
    cv = &gFontWork->bg[lcd];
    cv->buf = DWCi_HEAPlAllocEx(w * h * 32, 32);
    if (lcd == 1) {
        *(volatile u16 *)0x04001008 &= 0xFFBF;
        *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xC00;
    } else {
        *(volatile u16 *)0x04000008 &= 0xFFBF;
        *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xC00;
    }
    NNSi_G2dInitPenSimple((int)cv, (int)cv->buf, w, h, 4);
    MemFont *base = gFontWork;
    cv->text.pCanvas = cv;
    cv->text.pFont = &base->font[font];
    cv->text.hSpace = 1;
    cv->text.vSpace = 1;
    if (lcd == 1)
        scr = G2S_GetBG0ScrPtr();
    else
        scr = G2_GetBG0ScrPtr();
    chr = sFontTable1[lcd];
    NNS_G2dMapScrToCharText(scr, w, h, 0, 0, 0x20, chr, 0xF);
    DWCi_FNTlClear(cv, 0);
    cv->u.task = DWCi_TSKlForm(1, (void (*)(void *))taskLoad, &gFontWork->renew[lcd], 0xC8);
    return cv;
}


/*
 * sdk:      taskLoad (font.o)
 *
 * Closed (w5_nm): written from the DWARF (bool *renew, MemFont->bg[n] and the
 * renew[0] address test) instead of raw offsets; that gives the object's r5/r6
 * roles.  The object reads `work` from r1: the DWARF lists only `work`, so the
 * task callback's first argument is unnamed in the vendor source and is spelled
 * `task` here.
 */
static void taskLoad(void *task, void *work)
{
    unsigned char *renew = (unsigned char *)work;

    if (!*renew)
        return;
    if (renew == &gFontWork->renew[0]) {
        DWCi_ScreenDC_FlushRange(gFontWork->bg[0].buf, 0x6000);
        GX_LoadBG0Char(gFontWork->bg[0].buf, 0, 0x6000);
    } else {
        DWCi_ScreenDC_FlushRange(gFontWork->bg[1].buf, 0x3000);
        GXS_LoadBG0Char(gFontWork->bg[1].buf, 0x3000, 0x3000);
    }
    *renew = 0;
}


/*
 * sdk:      DWCi_FNTlDeleteBg (libdwcutil.TWL.HYB.a(font.o))
 */
void DWCi_FNTlDeleteBg(void *canvas)
{
    Canvas *cnv = canvas;
    DWCi_TSKlDeleteEx(1, cnv->u.task);
    if (cnv == gFontWork->bg)
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x6000);
    else
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x3000);
    DWCi_HEAPlFree_(&cnv->buf);
}


/*
 * Tail-call DWCi_FNTlDeleteBg with the argument scaled by 0x30 into the table at 0x021DE680 + 0x610.
 * Addresses are Black-image addresses.
 */
void DWCi_FNTlDeleteBgLcd(int a)
{
    DWCi_FNTlDeleteBg(&gFontWork->bg[a]);
}


void DWCi_FNTlDraw(void *canvas, int x, int y, int color, u32 flag, u16 *txt)
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


int DWCi_FNTlDrawCharEx(void *canvas, int x, int y, int color, unsigned short chr, int font)
{
    return NNSi_G2dCharCanvasDrawChar((struct Ctx *)canvas, (struct Fnt2 **)&gFontWork->font[font], x, y, color, chr);
}


/*
 * sdk:      DWCi_FNTlDrawStringEx (libdwcutil.TWL.HYB.a(font.o))
 */
void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, u16 *txt, int font)
{
    Font *f;
    int idx;
    if (*txt == 0)
        return;
    do {
        f = &gFontWork->font[font];
        idx = NNS_G2dFontFindGlyphIndex(f, *txt);
        if (idx == 0xffff)
            idx = ((u16 *)f->res)[1];
        DWCi_FNTlDrawCharEx(canvas, x + ((interval - NNS_G2dFontGetCharWidthsFromIndex(f, idx)->charWidth) >> 1), y, color, *txt, font);
        txt++;
        x += interval;
    } while (*txt != 0);
}


/*
 * sdk:      DWCi_FNTlDrawRect (libdwcutil.TWL.HYB.a(font.o))
 */
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt)
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


void DWCi_FNTlClear(Canvas *cnv, int color)
{
    cnv->pFmt->pfnClear(cnv, color);
}


/*
 * sdk:      DWCi_FNTlDisp (libdwcutil.TWL.HYB.a(font.o))
 */
void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio)
{
    Canvas *cnv = canvas;
    void *oam;
    oam = DWCi_CELLlGetObj(cell, 0);
    DWCi_CELLlSetEffect(cell, -1, 0, 0);
    DWCi_CELLlSetPalette(cell, -1, 0, 15);
    DWCi_CELLlSetPriority(cell, -1, prio);
    NNS_G2dArrangeOBJ1D(oam, cnv->u.obj.width, cnv->u.obj.height, x, y, 0, cnv->u.obj.name, 2);
}


void DWCi_FNTlRenewBg(int x)
{
    MemFont *p = gFontWork;
    int v = 1;

    if (x == (int)&p->bg[0])
        p->renew[0] = v;
    else
        p->renew[1] = v;
}
