/*
 * file:     unit_021D5824_p05.c
 * unit:     yes
 * function: func_021D5E5C, func_021D5F14, func_021D5F28, func_021D5FC4
 * address:  0x021D5E5C
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
 *   NNSi_G2dTextCanvasDrawTextRect   0x02069818  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm  ov016
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm  ov016
 *   DWCi_CELLlSetPalette             0x021D5098  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   NNS_G2dArrangeOBJ1D              0x020691E0  arm
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
} Canvas_021D5E5C;

typedef struct {
    u8 font[0x10];
    Canvas_021D5E5C canvas[32];
    Canvas_021D5E5C bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont;

typedef struct {
    signed char a;
    signed char b;
} Pair;

typedef struct {
    u8 chr[0x18];
    u8 text[0x10];
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas_021D5F28;

extern void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *tc, int x, int y, int w, int h, int color, u32 flag, u16 *txt, Pair p);
extern void *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void NNS_G2dArrangeOBJ1D(void *oam, int w, int h, int x, int y, int a, int name, int b);
void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
asm void DWCi_FNTlClear(void);
void func_021D5F28(void *canvas, int x, int y, void *cell, int prio);
void func_021D5FC4(int x);
extern MemFont *g_021DE680;


/*
 * sdk:      DWCi_FNTlDrawRect (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt)
{
    Canvas_021D5E5C *cnv = canvas;
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

asm void DWCi_FNTlClear(void)
{
	stmdb sp!, {r3, lr}
	ldr r2, [r0, #0x14]
	ldr r2, [r2, #4]
	blx r2
	ldmia sp!, {r3, pc}
}


/*
 * sdk:      DWCi_FNTlDisp (libdwcutil.TWL.HYB.a(font.o))
 */
void func_021D5F28(void *canvas, int x, int y, void *cell, int prio)
{
    Canvas_021D5F28 *cnv = canvas;
    void *oam;
    oam = DWCi_CELLlGetObj(cell, 0);
    DWCi_CELLlSetEffect(cell, -1, 0, 0);
    DWCi_CELLlSetPalette(cell, -1, 0, 15);
    DWCi_CELLlSetPriority(cell, -1, prio);
    NNS_G2dArrangeOBJ1D(oam, cnv->width, cnv->height, x, y, 0, cnv->name, 2);
}

void func_021D5FC4(int x)
{
    unsigned char *p = *(unsigned char **)0x021DE680;
    int v = 1;

    if (x == (int)(p + 0x610))
        *(unsigned char *)(p + 0x67c) = v;
    else
        *(unsigned char *)(p + 0x67d) = v;
}
