/*
 * function: DWCi_FNTlDisp
 * address:  0x021D5F28
 * packet:   pkt_ov016_021D5F28
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlDisp (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm  ov016
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm  ov016
 *   DWCi_CELLlSetPalette             0x021D5098  arm  ov016
 *   DWCi_CELLlSetPriority            0x021D51F0  arm  ov016
 *   NNS_G2dArrangeOBJ1D              0x020691E0  arm
 *   gFontWork  0x021DE680  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 chr[0x18];
    u8 text[0x10];
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

extern MemFont *gFontWork;
extern void *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void NNS_G2dArrangeOBJ1D(void *oam, int w, int h, int x, int y, int a, int name, int b);

void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio)
{
    Canvas *cnv = canvas;
    void *oam;
    oam = DWCi_CELLlGetObj(cell, 0);
    DWCi_CELLlSetEffect(cell, -1, 0, 0);
    DWCi_CELLlSetPalette(cell, -1, 0, 15);
    DWCi_CELLlSetPriority(cell, -1, prio);
    NNS_G2dArrangeOBJ1D(oam, cnv->width, cnv->height, x, y, 0, cnv->name, 2);
}
