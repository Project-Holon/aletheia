/*
 * file:     unit_021D5824_p01.c
 * unit:     yes
 * function: func_021D5824, func_021D5904, func_021D5950
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
} Canvas_021D5824;

typedef struct {
    Font font[2];
    Canvas_021D5824 canvas[32];
    Canvas_021D5824 bg[2];
    void *unused;
    void *file[2];
    u8 renew[2];
} MemFont_021D5824;

typedef struct {
    u8 chr[0x18];
    u8 text[0x10];
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas_021D5904;

typedef struct {
    u8 font[0x10];
    Canvas_021D5904 canvas[32];
    Canvas_021D5904 bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont_021D5904;

typedef int bool;

typedef struct {
    u8 chr0[0x14];
    CharFmt *pFmt;
    TextCanvas text;
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas_021D5950;

typedef struct {
    Font font[2];
    Canvas_021D5950 canvas[32];
    Canvas_021D5950 bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont_021D5950;

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
extern void NNS_G2dCharCanvasInitForOBJ1D(Canvas_021D5950 *cnv, void *base, int w, int h, int fmt);
void func_021D5824(void);
void func_021D5904(void);
void *func_021D5950(int lcd, int width, int height, bool head, int *obj, int font);
extern MemFont_021D5824 *g_021DE680;
extern char *g_021DBFE4[2];
extern char *g_021DBFEC[2];
extern MemFont_021D5904 *g_021DE680_free;


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


void *func_021D5950(int lcd, int width, int height, bool head, int *obj, int font)
{
    Canvas_021D5950 *cnv;
    u8 *base;
    int name;
    Font *fp;

    cnv = DWCi_QUElPopBack(g_021DE680->unused);
    cnv->width = width;
    cnv->height = height;
    cnv->buf = DWCi_OVRlAlloc(lcd, width * height, head, &name);
    cnv->name = name;
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
