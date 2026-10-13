/*
 * file:     unit_021D5824.c
 * unit:     yes
 * function: func_021D5824, func_021D5904, func_021D5950, func_021D5A2C, func_021D5A58, func_021D5BC0, func_021D5C48, func_021D5CA8, func_021D5CCC, func_021D5D74, func_021D5DB0, func_021D5E5C, func_021D5F14, func_021D5F28, func_021D5FC4
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
 *   DWCi_HEAPlAllocEx                0x021D6414  arm  ov016
 *   DWCi_QUElFormEx                  0x021D5410  arm  ov016
 *   DWCi_Language                    0x021C0EC8  arm  ov016
 *   DWCi_ARClReadEx                  0x021D4B68  arm  ov016
 *   NNS_G2dFontInitUTF16             0x02067F78  arm
 *   g_021DE680                       0x021DE680  data
 *   g_021DBFE4                       0x021DBFE4  data
 *   g_021DBFEC                       0x021DBFEC  data
 *   DWCi_ARClRelease                 0x021D4C68  arm  ov016
 *   DWCi_QUElDelete                  0x021D5450  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm  ov016
 *   g_021DE680_free                  0x021DE680  data
 *   DWCi_QUElPopBack                 0x021D54C4  arm  ov016
 *   DWCi_OVRlAlloc                   0x021D705C  arm  ov016
 *   NNSi_G2dCalcRequiredOBJ          0x02069184  arm
 *   NNS_G2dCharCanvasInitForOBJ1D    0x02068FF0  arm
 *   func_021D6414  0x021D6414  arm    ov016
 *   func_02068FC4  0x02068FC4  arm
 *   func_0207DF94  0x0207DF94  arm
 *   func_0207DF60  0x0207DF60  arm
 *   func_02069078  0x02069078  arm
 *   func_021D5F14  0x021D5F14  arm    ov016
 *   func_021D7680  0x021D7680  arm    ov016
 *   g_021DAA76     0x021DAA76  data
 *   g_021DAA74     0x021DAA74  data
 *   g_021DAA70     0x021DAA70  data
 *   func_020862F0                  0x020862F0  arm
 *   func_0207EE68                  0x0207EE68  arm
 *   func_0207EEFC                  0x0207EEFC  arm
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
extern void func_021D71C0(void *ovram);
extern void func_021D546C(void *queue, void *data);
extern void *func_021D6414(unsigned long size, int align);
extern void func_02068FC4(int a, int b, int c, int d, int e);
extern void *func_0207DF94(void);
extern void *func_0207DF60(void);
extern void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
extern void func_021D5F14(void *c, int col);
extern void *func_021D7680(int kind, void (*f)(void *), void *w, unsigned char prio);
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_0207EE68(void *pSrc, unsigned long offset, unsigned long szByte);
extern void func_0207EEFC(void *pSrc, unsigned long offset, unsigned long szByte);
extern void DWCi_TSKlDeleteEx(int a, void *task);
extern void *G2_GetBG0CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void NNSi_G2dTextCanvasDrawText(TextCanvas *tc, int x, int y, int color, u32 flag, u16 *txt, Pair p);
extern s8 func_02068EA0(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code);
extern int NNS_G2dFontFindGlyphIndex(void *font, u16 c);
extern CharWidths *NNS_G2dFontGetCharWidthsFromIndex(void *font, int idx);
extern void DWCi_FNTlDrawCharEx(void *canvas, int x, int y, int color, u16 chr, int font);
extern void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *tc, int x, int y, int w, int h, int color, u32 flag, u16 *txt, Pair p);
extern void *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void NNS_G2dArrangeOBJ1D(void *oam, int w, int h, int x, int y, int a, int name, int b);
void func_021D5824(void);
void func_021D5904(void);
void *func_021D5950(int lcd, int width, int height, bool_0 head, int *obj, int font);
void func_021D5A2C(Canvas *a);
void *func_021D5A58(int lcd, int font);
void func_021D5BC0(void *task, void *work);
void func_021D5C48(void *canvas);
void func_021D5CA8(int a);
void func_021D5CCC(void *canvas, int x, int y, int color, u32 flag, u16 *txt);
int func_021D5D74(int a0, int a1, int a2, int a3, unsigned short s0, int s1);
void func_021D5DB0(void *canvas, int x, int y, int color, int interval, u16 *txt, int font);
void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
void DWCi_FNTlClear(Canvas *cnv, int color);
void func_021D5F28(void *canvas, int x, int y, void *cell, int prio);
void func_021D5FC4(int x);
extern MemFont *g_021DE680;
extern char *g_021DBFE4[2];
extern char *g_021DBFEC[2];
extern MemFont *g_021DE680_free;
extern const u16 g_021DAA74[];
extern const u16 g_021DAA76[];
extern const u16 g_021DAA70[];






/*
 * sdk:      DWCi_FNTlInit (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5824(void)
{
    int i;
    g_021DE680 = DWCi_HEAPlAllocEx(0x680, 4);
    g_021DE680->unused = DWCi_QUElFormEx(32, g_021DE680->canvas, 48);
    if (DWCi_Language() == 6) {
        for (i = 0; i < 2; i++) {
            g_021DE680->file[i] = DWCi_ARClReadEx(g_021DBFE4[i], 0, 4);
            NNS_G2dFontInitUTF16(&g_021DE680->font[i], g_021DE680->file[i]);
        }
    } else {
        for (i = 0; i < 2; i++) {
            g_021DE680->file[i] = DWCi_ARClReadEx(g_021DBFEC[i], 0, 4);
            NNS_G2dFontInitUTF16(&g_021DE680->font[i], g_021DE680->file[i]);
        }
    }
}






/*
 * sdk:      DWCi_FNTlEnd (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5904(void)
{
    int i;
    for (i = 0; i < 2; i++)
        DWCi_ARClRelease(g_021DE680->file[i]);
    DWCi_QUElDelete(g_021DE680->unused);
    DWCi_HEAPlFree_((void **)&g_021DE680_free);
}






void *func_021D5950(int lcd, int width, int height, bool_0 head, int *obj, int font)
{
    Canvas *cnv;
    u8 *base;
    int name;
    Font *fp;

    cnv = DWCi_QUElPopBack(g_021DE680->unused);
    cnv->u.obj.width = width;
    cnv->u.obj.height = height;
    cnv->buf = DWCi_OVRlAlloc(lcd, width * height, head, &name);
    cnv->u.obj.name = name;
    *obj = NNSi_G2dCalcRequiredOBJ(width, height);
    base = (u8 *)(lcd == 1 ? 0x6600000 : 0x6400000);
    base += name * 128;
    NNS_G2dCharCanvasInitForOBJ1D(cnv, base, width, height, 4);
    cnv->pFmt->pfnClear(cnv, 0);
    fp = &g_021DE680->font[font];
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
void func_021D5A2C(Canvas *a)
{
    func_021D71C0(a->buf);
    func_021D546C(g_021DE680->unused, a);
}






/*
 * notes: EXACT.  Two passes: const-qualifying the three read-only tables
 *        (`extern const u16 g_021DAA74[]/g_021DAA76[]/g_021DAA70[]`) collapsed
 *        the +D0..+0104 argument-setup residue (33 differing bytes -> 10).
 *        The last residue was the +00AC..+00B4 field-run order: image stores
 *        `str r5,[r5,#0x18]` (cv->self) before `add r0,r0,r4,lsl #3` /
 *        `str r0,[r5,#0x1c]` (cv->font).  Writing the source self-first put
 *        cv->self in place but recoloured the block (g into r1, the constant
 *        1 into r0), 21 bytes.  Binding the loaded global pointer to a named
 *        local -- `MemFont *base = g_021DE680;` before `cv->text.pCanvas = cv;`, then
 *        `cv->text.pFont = &base->font[font];` -- keeps the self store first and the
 *        add base in r0.  See
 *        docs/idioms/a-named-local-for-the-loaded-global-base-settles-a-field-store-run.md.
 *
 * sdk:      DWCi_FNTlFormBgEx (libdwcutil.TWL.HYB.a font.o)
 */
void *func_021D5A58(int lcd, int font)
{
    Canvas *cv;
    void *scr;
    u16 w, h, chr;

    h = g_021DAA76[lcd * 2];
    w = g_021DAA74[lcd * 2];
    cv = &g_021DE680->bg[lcd];
    cv->buf = func_021D6414(w * h * 32, 32);
    if (lcd == 1) {
        *(volatile u16 *)0x04001008 &= 0xFFBF;
        *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xC00;
    } else {
        *(volatile u16 *)0x04000008 &= 0xFFBF;
        *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xC00;
    }
    func_02068FC4((int)cv, (int)cv->buf, w, h, 4);
    MemFont *base = g_021DE680;
    cv->text.pCanvas = cv;
    cv->text.pFont = &base->font[font];
    cv->text.hSpace = 1;
    cv->text.vSpace = 1;
    if (lcd == 1)
        scr = func_0207DF94();
    else
        scr = func_0207DF60();
    chr = g_021DAA70[lcd];
    func_02069078(scr, w, h, 0, 0, 0x20, chr, 0xF);
    func_021D5F14(cv, 0);
    cv->u.task = func_021D7680(1, (void (*)(void *))func_021D5BC0, &g_021DE680->renew[lcd], 0xC8);
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
void func_021D5BC0(void *task, void *work)
{
    unsigned char *renew = (unsigned char *)work;

    if (!*renew)
        return;
    if (renew == &g_021DE680->renew[0]) {
        func_020862F0(g_021DE680->bg[0].buf, 0x6000);
        func_0207EE68(g_021DE680->bg[0].buf, 0, 0x6000);
    } else {
        func_020862F0(g_021DE680->bg[1].buf, 0x3000);
        func_0207EEFC(g_021DE680->bg[1].buf, 0x3000, 0x3000);
    }
    *renew = 0;
}




/*
 * sdk:      DWCi_FNTlDeleteBg (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5C48(void *canvas)
{
    Canvas *cnv = canvas;
    DWCi_TSKlDeleteEx(1, cnv->u.task);
    if (cnv == g_021DE680->bg)
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x6000);
    else
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x3000);
    DWCi_HEAPlFree_(&cnv->buf);
}





/*
 * Tail-call func_021D5C48 with the argument scaled by 0x30 into the table at 0x021DE680 + 0x610.
 * Addresses are Black-image addresses.
 */
void func_021D5CA8(int a)
{
    func_021D5C48(&g_021DE680->bg[a]);
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




int func_021D5D74(int a0, int a1, int a2, int a3, unsigned short s0, int s1)
{
    return func_02068EA0((struct Ctx *)a0, (struct Fnt2 **)&g_021DE680->font[s1], a1, a2, a3, s0);
}




/*
 * sdk:      DWCi_FNTlDrawStringEx (libdwcutil.TWL.HYB.a(font.o))
 */
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




/*
 * sdk:      DWCi_FNTlDrawRect (libdwcutil.TWL.HYB.a(font.o))
 */
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



void DWCi_FNTlClear(Canvas *cnv, int color)
{
    cnv->pFmt->pfnClear(cnv, color);
}




/*
 * sdk:      DWCi_FNTlDisp (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5F28(void *canvas, int x, int y, void *cell, int prio)
{
    Canvas *cnv = canvas;
    void *oam;
    oam = DWCi_CELLlGetObj(cell, 0);
    DWCi_CELLlSetEffect(cell, -1, 0, 0);
    DWCi_CELLlSetPalette(cell, -1, 0, 15);
    DWCi_CELLlSetPriority(cell, -1, prio);
    NNS_G2dArrangeOBJ1D(oam, cnv->u.obj.width, cnv->u.obj.height, x, y, 0, cnv->u.obj.name, 2);
}



void func_021D5FC4(int x)
{
    MemFont *p = g_021DE680;
    int v = 1;

    if (x == (int)&p->bg[0])
        p->renew[0] = v;
    else
        p->renew[1] = v;
}
